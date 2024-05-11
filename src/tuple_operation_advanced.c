/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operation_advanced.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:08:03 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:08:04 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double	magnitude(t_uple vector)
{
	double	magnitude;

	magnitude = vector.x * vector.x;
	magnitude += vector.y * vector.y;
	magnitude += vector.z * vector.z;
	magnitude += vector.w * vector.w;
	return (sqrtf(magnitude));
}

t_uple	normalize(t_uple vector)
{
	t_uple	new_vector;
	double	magnitude_;

	magnitude_ = magnitude(vector);
	new_vector.x = vector.x / magnitude_;
	new_vector.y = vector.y / magnitude_;
	new_vector.z = vector.z / magnitude_;
	new_vector.w = vector.w / magnitude_;
	return (new_vector);
}

double	dot(t_uple vector_a, t_uple vector_b)
{
	double	dot_product;

	dot_product = vector_a.x * vector_b.x;
	dot_product += vector_a.y * vector_b.y;
	dot_product += vector_a.z * vector_b.z;
	dot_product += vector_a.w * vector_b.w;
	return (dot_product);
}

t_uple	cross(t_uple vector_a, t_uple vector_b)
{
	t_uple	new_vector;

	new_vector.x = vector_a.y * vector_b.z - vector_a.z * vector_b.y;
	new_vector.y = vector_a.z * vector_b.x - vector_a.x * vector_b.z;
	new_vector.z = vector_a.x * vector_b.y - vector_a.y * vector_b.x;
	new_vector.w = 0;
	return (new_vector);
}
