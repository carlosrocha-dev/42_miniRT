/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_normal_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:16 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:07:17 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_uple	cone_normal_at(t_object object_, t_uple point)
{
	double	dist;
	double	min_radius;
	double	max_radius;
	double	y;

	dist = (point.x * point.x) + (point.z * point.z);
	max_radius = pow(object_.cone.top, 2);
	if (dist < max_radius && point.y >= object_.cone.top - EPSILON)
		return (vector(0, 1, 0));
	min_radius = pow(object_.cone.base, 2);
	if (dist < min_radius && point.y <= object_.cone.base + EPSILON)
		return (vector(0, -1, 0));
	y = sqrt(dist);
	if (point.y > 0.0)
		y = -y;
	return (vector(point.x, y, point.z));
}

t_uple	cylinder_normal_at(t_object object_, t_uple point)
{
	double	dist;

	dist = (point.x * point.x) + (point.z * point.z);
	if (dist < 1 && point.y >= object_.cylinder.top - EPSILON)
		return (vector(0, 1, 0));
	if (dist < 1 && point.y <= object_.cylinder.base + EPSILON)
		return (vector(0, -1, 0));
	return (vector(point.x, 0, point.z));
}

t_uple	plane_normal_at(t_object object_, t_uple point_)
{
	t_uple	normal_at_;

	(void)object_;
	(void)point_;
	normal_at_ = vector(0, 1, 0);
	return (normal_at_);
}

t_uple	sphere_normal_at(t_object object_, t_uple point_)
{
	t_uple	normal_at_;

	(void)object_;
	normal_at_ = subtract(point_, point(0, 0, 0));
	normal_at_.w = 0;
	normal_at_ = normalize(normal_at_);
	return (normal_at_);
}
