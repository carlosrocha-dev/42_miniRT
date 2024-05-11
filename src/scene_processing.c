/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:40:35 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 15:50:41 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	process_ambient_light(double params[11], t_scene *scene)
{
	int	index;

	params[1] /= RGB_MAX;
	params[2] /= RGB_MAX;
	params[3] /= RGB_MAX;
	ambient_light(scene, \
	color(params[1] * params[0], params[2] * params[0], params[3] * params[0]));
	index = -1;
	while (++index < 4)
	{
		if (params[index] < DECIMAL_MIN || params[index] > DECIMAL_MAX)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	process_point_light(double params[11], t_scene *scene)
{
	int	index;

	params[4] /= 255;
	params[5] /= 255;
	params[6] /= 255;
	point_light(scene, \
	point(params[0], params[1], params[2]), \
	color(params[4] * params[3], params[5] * params[3], params[6] * params[3]));
	index = 2;
	while (++index < 7)
	{
		if (params[index] < DECIMAL_MIN || params[index] > DECIMAL_MAX)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	process_camera(double params[11], t_scene *scene)
{
	scene->camera = camera(params[6]);
	scene->camera.transform = view_transform(point(params[0], \
	params[1], params[2]), point(0, 1, 0), \
	vector(params[3], params[4], params[5]));
	scene->camera.inverse = inverse(scene->camera.transform);
	return ((params[6] < FOV_MIN || params[6] > FOV_MAX));
}
