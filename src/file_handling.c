/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:37:22 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:12:20 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

int	validate_args(int argc)
{
	if (argc != 2)
	{
		printf("\033[33;1mError\n\033[0m");
		printf("An scene should be indicated!\n<./miniRT scene/scene.rt>\n");
		printf("You can use the following scenes:\n\n");
		system("ls -1 scene/");
		printf("\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	process_lines(int fd)
{
	char	*gnl;
	int		flag;
	int		camera;

	camera = 0;
	gnl = get_next_line(fd);
	while (gnl && *gnl)
	{
		flag = verifie_camera(gnl);
		if (flag == 1)
		{
			camera++;
			if (camera > 1)
			{
				printf("\033[31;1mError\n\033[0m");
				printf("The scene isn`t valid! More than one camera.\n");
				free(gnl);
				return (FAILURE);
			}
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (camera);
}

int	has_scene_is_valid(char *file)
{
	int	fd;
	int	camera_count;

	fd = open_file(file);
	if (fd == -1)
		return (FAILURE);
	camera_count = process_lines(fd);
	close(fd);
	if (camera_count == 0)
	{
		printf("\033[31;1mError\n\033[0m");
		printf("The scene isn`t valid, without camera.\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	verifie_camera(char *gnl)
{
	int	i;

	i = 0;
	if (gnl[i] == 'C')
	{
		i++;
		while (gnl[i] == ' ')
			i++;
		if ((gnl[i] == '-' || (gnl[i] >= '0' && gnl[i] <= '9')))
			return (FAILURE);
	}
	return (SUCCESS);
}
