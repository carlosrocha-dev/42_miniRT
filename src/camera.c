/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:03:12 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:03:13 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_mtx	view_transform(t_uple from, t_uple to, t_uple up)
{
	t_uple	forward;
	t_uple	left;
	t_uple	true_up;
	t_mtx	new_matrix;

	forward = normalize(subtract(to, from));
	left = cross(forward, normalize(up));
	true_up = cross(left, forward);
	new_matrix = matrix(line(left.x, left.y, left.z, 0), \
	line(true_up.x, true_up.y, true_up.z, 0), \
	line(-forward.x, -forward.y, -forward.z, 0), \
	line(0, 0, 0, 1));
	return (multiply_mtx(new_matrix, translation(-from.x, -from.y, -from.z)));
}

t_camera	camera(float field_of_view)
{
	t_camera	new_camera;

	field_of_view *= RADIANS;
	new_camera.half_width = tanf(field_of_view / 2);
	new_camera.half_height = new_camera.half_width;
	if ((WIN_W / WIN_H) < 1)
		new_camera.half_width *= (WIN_W / WIN_H);
	else if ((WIN_W / WIN_H) >= 1)
		new_camera.half_height /= (WIN_W / WIN_H);
	new_camera.pixel_size = (new_camera.half_width * 2) / WIN_W;
	new_camera.transform = get_identity_mtx();
	new_camera.inverse = inverse(new_camera.transform);
	return (new_camera);
}
