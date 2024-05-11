/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:04:00 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:04:01 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_mtx	rotation_z(double rotate)
{
	t_mtx	new_matrix;

	new_matrix = \
	matrix(line(cos(rotate), -sin(rotate), 0, 0), \
	line(sin(rotate), cos(rotate), 0, 0), \
	line(0, 0, 1, 0), \
	line(0, 0, 0, 1));
	return (new_matrix);
}

t_mtx	rotation_y(double rotate)
{
	t_mtx	new_matrix;

	new_matrix = \
	matrix(line(cos(rotate), 0, sin(rotate), 0), \
	line(0, 1, 0, 0), \
	line(-sin(rotate), 0, cos(rotate), 0), \
	line(0, 0, 0, 1));
	return (new_matrix);
}

t_mtx	rotation_x(double rotate)
{
	t_mtx	new_matrix;

	new_matrix = \
	matrix(line(1, 0, 0, 0), \
	line(0, cos(rotate), -sin(rotate), 0), \
	line(0, sin(rotate), cos(rotate), 0), \
	line(0, 0, 0, 1));
	return (new_matrix);
}
