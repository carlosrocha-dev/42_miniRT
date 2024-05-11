/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:04:28 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:04:29 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_mtx	full_rotation(t_uple vector)
{
	double	x_angle;
	double	z_angle;
	double	ratio;
	t_mtx	new_mtx;

	ratio = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (0.0 == ratio)
		z_angle = PI_2;
	else
		z_angle = acos(vector.y / ratio);
	x_angle = acos(ratio);
	new_mtx = multiply_mtx(rotation_z(z_angle), rotation_x(x_angle));
	return (new_mtx);
}

t_mtx	scaling(double x, double y, double z)
{
	t_mtx	new_matrix;

	new_matrix = \
	matrix(line(x, 0, 0, 0), \
	line(0, y, 0, 0), \
	line(0, 0, z, 0), \
	line(0, 0, 0, 1));
	return (new_matrix);
}

t_mtx	translation(double x, double y, double z)
{
	t_mtx	new_matrix;

	new_matrix = \
	matrix(line(1, 0, 0, x), \
	line(0, 1, 0, y), \
	line(0, 0, 1, z), \
	line(0, 0, 0, 1));
	return (new_matrix);
}

t_mtx	inverse(t_mtx mtx_a)
{
	t_mtx	inversed;
	double	cof;
	double	determinant_;
	int		i[2];

	determinant_ = determinant(mtx_a);
	if (!determinant_)
		return (mtx_a);
	i[0] = -1;
	i[1] = -1;
	while (++i[0] < mtx_a.max)
	{
		while (++i[1] < mtx_a.max)
		{
			cof = cofactor(mtx_a, i[0], i[1]);
			inversed.matrix[i[1]][i[0]] = cof / determinant_;
		}
		i[1] = -1;
	}
	inversed.max = mtx_a.max;
	return (inversed);
}

t_mtx	transpose(t_mtx mtx_a)
{
	int		col;
	int		row;
	t_mtx	new_mtx;

	col = -1;
	row = -1;
	while (++row < MAX)
	{
		while (++col < MAX)
			new_mtx.matrix[row][col] = mtx_a.matrix[col][row];
		col = -1;
	}
	new_mtx.max = MAX;
	return (new_mtx);
}
