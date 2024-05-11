/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:40:11 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 17:47:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	get_params(t_scene *scene, char *objects, const char *tokenizer, \
int (*f)(double params[11], t_scene *scene))
{
	double	params[11];
	char	tokenizer_ptr[1];
	char	*token;
	int		index;
	int		tokenizer_size;

	index = -1;
	tokenizer_size = ft_strlen(tokenizer);
	while (++index < tokenizer_size - 1)
	{
		tokenizer_ptr[0] = tokenizer[index + 1];
		if (index == 0)
			token = ft_strtok(objects, tokenizer_ptr);
		else if (index > 0)
		{
			token = ft_strtok(NULL, tokenizer_ptr);
			if (token)
				params[index - 1] = ft_atof(token);
		}
		if (token == NULL || token[0] == '\n')
			return (FAILURE);
	}
	return (f(params, scene));
}

int	parse_objects(char *objects, t_scene *scene)
{
	if (objects[0] == 'A')
		return (get_params(scene, objects, TOKEN_ALIGHT, \
		process_ambient_light));
	else if (objects[0] == 'C')
		return (get_params(scene, objects, TOKEN_CAMERA, process_camera));
	else if (objects[0] == 'L')
		return (get_params(scene, objects, TOKEN_PLIGHT, process_point_light));
	else if (ft_strncmp(objects, "sp", 2) == 0)
		return (get_params(scene, objects, TOKEN_SPHERE, process_sphere));
	else if (ft_strncmp(objects, "pl", 2) == 0)
		return (get_params(scene, objects, TOKEN_PLANE, process_plane));
	else if (ft_strncmp(objects, "cy", 2) == 0)
		return (get_params(scene, objects, TOKEN_CYLIN, process_cylinder));
	else if (ft_strncmp(objects, "cn", 2) == 0)
		return (get_params(scene, objects, TOKEN_CONE, process_cone));
	return (SUCCESS);
}

void	return_lines(t_scene *scene, char *file)
{
	char	*gnl;
	int		fd;
	int		line;
	int		error_trigger;

	fd = open_file(file);
	if (fd == -1)
		return ;
	gnl = get_next_line(fd);
	line = 0;
	error_trigger = 0;
	while (++line && !error_trigger && gnl && *gnl)
	{
		if (gnl[0] != '#' && gnl[0] != '\n')
			error_trigger = parse_objects(gnl, scene);
		free(gnl);
		gnl = get_next_line(fd);
	}
	if (error_trigger)
	{
		ft_printfd(ERROR_PARAM, STDERR_FILENO, line - 1);
		exit(1);
	}
}
