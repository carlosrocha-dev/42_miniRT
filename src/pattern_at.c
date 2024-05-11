/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:53:14 by caalbert          #+#    #+#             */
/*   Updated: 2023/12/18 00:55:29 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color	uv_checker_at(t_material material, t_uple point)
{
	double		floor_total;
	t_checker	uv;

	uv = material.map(point);
	floor_total = (floor(uv.width * material.pattern.checkers.width) \
	+ floor(uv.height * material.pattern.checkers.height));
	if ((int)floor_total % 2 == 0)
		return (material.pattern.checkers.color_a);
	return (material.pattern.checkers.color_b);
}

t_color	gradient_at(t_material material, t_uple point)
{
	t_color	new_color;
	double	fraction;

	fraction = point.x - floor(point.x);
	new_color = subtract_c(material.pattern.color_b, material.pattern.color_a);
	new_color = add_c(material.pattern.color_a, \
	multiply_c(new_color, fraction));
	return (new_color);
}

t_color	stripe_at(t_material material, t_uple point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (material.pattern.color_a);
	return (material.pattern.color_b);
}

t_color	pattern_at(t_material material, t_object object_, t_uple point)
{
	t_color	new_color;
	t_uple	object_point;
	t_uple	pattern_point;

	object_point = multiply_mtx_tuple(object_.inverse, point);
	pattern_point = multiply_mtx_tuple(material.pattern.inverse, object_point);
	new_color = material.pattern.pattern_at(material, pattern_point);
	return (new_color);
}
