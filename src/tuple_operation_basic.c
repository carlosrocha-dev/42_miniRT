/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operation_basic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:08:08 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:08:09 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_uple	add(t_uple tuple_a, t_uple tuple_b)
{
	t_uple	new_tuple;

	new_tuple.x = tuple_a.x + tuple_b.x;
	new_tuple.y = tuple_a.y + tuple_b.y;
	new_tuple.z = tuple_a.z + tuple_b.z;
	new_tuple.w = tuple_a.w + tuple_b.w;
	return (new_tuple);
}

t_uple	subtract(t_uple tuple_a, t_uple tuple_b)
{
	t_uple	new_tuple;

	new_tuple.x = tuple_a.x - tuple_b.x;
	new_tuple.y = tuple_a.y - tuple_b.y;
	new_tuple.z = tuple_a.z - tuple_b.z;
	new_tuple.w = tuple_a.w - tuple_b.w;
	return (new_tuple);
}

t_uple	negate(t_uple tuple)
{
	t_uple	new_tuple;

	new_tuple.x = -tuple.x;
	new_tuple.y = -tuple.y;
	new_tuple.z = -tuple.z;
	new_tuple.w = -tuple.w;
	return (new_tuple);
}

t_uple	multiply(t_uple tuple, double scalar)
{
	t_uple	new_tuple;

	new_tuple.x = tuple.x * scalar;
	new_tuple.y = tuple.y * scalar;
	new_tuple.z = tuple.z * scalar;
	new_tuple.w = tuple.w * scalar;
	return (new_tuple);
}

t_uple	divide(t_uple tuple, double scalar)
{
	t_uple	new_tuple;

	new_tuple.x = tuple.x / scalar;
	new_tuple.y = tuple.y / scalar;
	new_tuple.z = tuple.z / scalar;
	new_tuple.w = tuple.w / scalar;
	return (new_tuple);
}
