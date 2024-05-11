/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:04:55 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:04:56 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_mtx	get_identity_mtx(void)
{
	t_mtx	new_matrix;

	new_matrix = \
	matrix(line(1, 0, 0, 0), \
	line(0, 1, 0, 0), \
	line(0, 0, 1, 0), \
	line(0, 0, 0, 1));
	return (new_matrix);
}

t_uple	multiply_mtx_tuple(t_mtx mtx_a, t_uple tuple_a)
{
	t_uple	new_tuple;

	new_tuple.x = mtx_a.matrix[0][0] * tuple_a.x;
	new_tuple.x += mtx_a.matrix[0][1] * tuple_a.y;
	new_tuple.x += mtx_a.matrix[0][2] * tuple_a.z;
	new_tuple.x += mtx_a.matrix[0][3] * tuple_a.w;
	new_tuple.y = mtx_a.matrix[1][0] * tuple_a.x;
	new_tuple.y += mtx_a.matrix[1][1] * tuple_a.y;
	new_tuple.y += mtx_a.matrix[1][2] * tuple_a.z;
	new_tuple.y += mtx_a.matrix[1][3] * tuple_a.w;
	new_tuple.z = mtx_a.matrix[2][0] * tuple_a.x;
	new_tuple.z += mtx_a.matrix[2][1] * tuple_a.y;
	new_tuple.z += mtx_a.matrix[2][2] * tuple_a.z;
	new_tuple.z += mtx_a.matrix[2][3] * tuple_a.w;
	new_tuple.w = mtx_a.matrix[3][0] * tuple_a.x;
	new_tuple.w += mtx_a.matrix[3][1] * tuple_a.y;
	new_tuple.w += mtx_a.matrix[3][2] * tuple_a.z;
	new_tuple.w += mtx_a.matrix[3][3] * tuple_a.w;
	return (new_tuple);
}

t_mtx	multiply_mtx(t_mtx mtx_a, t_mtx mtx_b)
{
	int		col;
	int		row;
	t_mtx	new_mtx;

	col = -1;
	row = -1;
	while (++row < MAX)
	{
		while (++col < MAX)
		{
			new_mtx.matrix[row][col] = \
			mtx_a.matrix[row][0] * mtx_b.matrix[0][col];
			new_mtx.matrix[row][col] += \
			mtx_a.matrix[row][1] * mtx_b.matrix[1][col];
			new_mtx.matrix[row][col] += \
			mtx_a.matrix[row][2] * mtx_b.matrix[2][col];
			new_mtx.matrix[row][col] += \
			mtx_a.matrix[row][3] * mtx_b.matrix[3][col];
		}
		col = -1;
	}
	new_mtx.max = MAX;
	return (new_mtx);
}

t_mtx	line(double numb_1, double numb_2, double numb_3, double numb_4)
{
	static t_mtx	new_mtx;
	static int		index;

	(void)index;
	if (--index == -1)
		index = 3;
	new_mtx.matrix[index][0] = numb_1;
	new_mtx.matrix[index][1] = numb_2;
	new_mtx.matrix[index][2] = numb_3;
	new_mtx.matrix[index][3] = numb_4;
	return (new_mtx);
}

t_mtx	matrix(t_mtx mtx1, t_mtx mtx2, t_mtx mtx3, t_mtx mtx4)
{
	t_mtx	new_mtx;

	new_mtx.matrix[0][0] = mtx1.matrix[0][0];
	new_mtx.matrix[0][1] = mtx1.matrix[0][1];
	new_mtx.matrix[0][2] = mtx1.matrix[0][2];
	new_mtx.matrix[0][3] = mtx1.matrix[0][3];
	new_mtx.matrix[1][0] = mtx2.matrix[1][0];
	new_mtx.matrix[1][1] = mtx2.matrix[1][1];
	new_mtx.matrix[1][2] = mtx2.matrix[1][2];
	new_mtx.matrix[1][3] = mtx2.matrix[1][3];
	new_mtx.matrix[2][0] = mtx3.matrix[2][0];
	new_mtx.matrix[2][1] = mtx3.matrix[2][1];
	new_mtx.matrix[2][2] = mtx3.matrix[2][2];
	new_mtx.matrix[2][3] = mtx3.matrix[2][3];
	new_mtx.matrix[3][0] = mtx4.matrix[3][0];
	new_mtx.matrix[3][1] = mtx4.matrix[3][1];
	new_mtx.matrix[3][2] = mtx4.matrix[3][2];
	new_mtx.matrix[3][3] = mtx4.matrix[3][3];
	new_mtx.max = MAX;
	return (new_mtx);
}
