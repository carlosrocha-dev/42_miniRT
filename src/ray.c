/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:06:02 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:06:03 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_ray	transform(t_ray ray_, t_mtx operation)
{
	t_ray	new_ray;

	new_ray.origin = multiply_mtx_tuple(operation, ray_.origin);
	new_ray.direction = multiply_mtx_tuple(operation, ray_.direction);
	return (new_ray);
}

t_uple	position(t_ray ray_a, float time)
{
	t_uple	new_position;

	new_position = add(ray_a.origin, multiply(ray_a.direction, time));
	return (new_position);
}

t_ray	ray_for_pixel(t_camera camera, float px, float py)
{
	float	world_x;
	float	world_y;
	t_uple	pixel;
	t_uple	origin;

	world_x = camera.half_width - ((px + 0.5) * camera.pixel_size);
	world_y = camera.half_height - ((py + 0.5) * camera.pixel_size);
	pixel = multiply_mtx_tuple(camera.inverse, point(world_x, world_y, -1));
	origin = multiply_mtx_tuple(camera.inverse, point(0, 0, 0));
	return (ray(origin, normalize(subtract(pixel, origin))));
}

t_ray	ray(t_uple origin, t_uple direction)
{
	t_ray	new_ray;

	new_ray.origin = origin;
	new_ray.direction = direction;
	return (new_ray);
}
