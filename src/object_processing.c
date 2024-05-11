/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:17 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:30:18 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	process_plane(double params[11], t_scene *scene)
{
	int		index;
	t_uple	direction;

	params[6] /= 255;
	params[7] /= 255;
	params[8] /= 255;
	direction = vector(params[3], params[4], params[5]);
	plane(scene, point(params[0], params[1], params[2]), direction);
	scene->objects[*scene->obj_number - 1].material.color = \
	color(params[6], params[7], params[8]);
	index = 2;
	while (++index < 9)
	{
		if (index < 6 && \
		(params[index] < DECIMAL_MIN - 1 || params[index] > DECIMAL_MAX))
			return (FAILURE);
		if (index >= 6 && \
		(params[index] < DECIMAL_MIN || params[index] > DECIMAL_MAX))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	process_sphere(double params[11], t_scene *scene)
{
	int	index;

	params[4] /= 255;
	params[5] /= 255;
	params[6] /= 255;
	sphere(scene, point(params[0], params[1], params[2]), params[3]);
	scene->objects[*scene->obj_number - 1].material.color = \
	color(params[4], params[5], params[6]);
	index = 3;
	while (++index < 7)
	{
		if (params[index] < DECIMAL_MIN || params[index] > DECIMAL_MAX)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	process_cylinder(double params[11], t_scene *scene)
{
	int	index;

	params[8] /= 255;
	params[9] /= 255;
	params[10] /= 255;
	cylinder(scene, cyl_set(\
		point(params[0], params[1], params[2]), \
		vector(params[3], params[4], params[5]), \
		params[6], params[7]) \
	);
	scene->objects[*scene->obj_number - 1].material.color = \
		color(params[8], params[9], params[10]);
	index = 2;
	while (++index < 11)
	{
		if (index < 6 && \
		(params[index] < DECIMAL_MIN - 1 || params[index] > DECIMAL_MAX))
			return (FAILURE);
		if (index >= 8 && \
		(params[index] < DECIMAL_MIN || params[index] > DECIMAL_MAX))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	process_cone(double params[11], t_scene *scene)
{
	int	index;

	params[8] /= 255;
	params[9] /= 255;
	params[10] /= 255;
	cone(scene, cone_set(\
		point(params[0], params[1], params[2]), \
		vector(params[3], params[4], params[5]), \
		params[6], params[7]) \
	);
	scene->objects[*scene->obj_number - 1].material.color = \
		color(params[8], params[9], params[10]);
	index = 2;
	while (++index < 11)
	{
		if (index < 6 && \
		(params[index] < DECIMAL_MIN - 1 || params[index] > DECIMAL_MAX))
			return (FAILURE);
		if (index >= 8 && \
		(params[index] < DECIMAL_MIN || params[index] > DECIMAL_MAX))
			return (FAILURE);
	}
	return (SUCCESS);
}
