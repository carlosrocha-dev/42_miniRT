/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:03 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:07:04 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_checker	cone_map(t_uple point)
{
	t_checker	new_checker;

	new_checker.width = 1 - (atan2(point.x, point.z) / (2 * PI) + 0.5);
	new_checker.height = 1 - (acos(point.y / magnitude(point)) / PI);
	new_checker.color_a = color(0, 0, 0);
	new_checker.color_b = color(0, 0, 0);
	return (new_checker);
}

t_checker	plane_map(t_uple point)
{
	t_checker	new_checker;

	new_checker.width = fmod(point.x, 1);
	new_checker.height = fmod(point.z, 1);
	new_checker.height += (new_checker.height < 0);
	new_checker.color_a = color(0, 0, 0);
	new_checker.color_b = color(0, 0, 0);
	return (new_checker);
}

t_checker	cylinder_map(t_uple point)
{
	t_checker	new_checker;

	new_checker.width = 1 - ((atan2(point.x, point.z) / (2 * PI)) + 0.5);
	new_checker.height = fmod(point.y, 1);
	new_checker.height += (new_checker.height < 0);
	new_checker.color_a = color(0, 0, 0);
	new_checker.color_b = color(0, 0, 0);
	return (new_checker);
}

t_checker	sphere_map(t_uple point)
{
	t_checker	new_checker;

	new_checker.width = 1 - ((atan2(point.x, point.z) / (2 * PI)) + 0.5);
	new_checker.height = \
	1 - acos(point.y / magnitude(vector(point.x, point.y, point.z))) / PI;
	new_checker.color_a = color(0, 0, 0);
	new_checker.color_b = color(0, 0, 0);
	return (new_checker);
}
