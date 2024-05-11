/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:08:17 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:08:18 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_uple	point(double x, double y, double z)
{
	t_uple	new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	new_point.w = 1.0;
	return (new_point);
}

t_uple	vector(double x, double y, double z)
{
	t_uple	new_vector;

	new_vector.x = x;
	new_vector.y = y;
	new_vector.z = z;
	new_vector.w = 0.0;
	return (new_vector);
}

t_uple	tuple(double x, double y, double z, double w)
{
	t_uple	new_tuple;

	new_tuple.x = x;
	new_tuple.y = y;
	new_tuple.z = z;
	new_tuple.w = w;
	return (new_tuple);
}
