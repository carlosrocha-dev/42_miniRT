/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:03:49 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:03:50 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	determinant(t_mtx mtx_a)
{
	double	determinant_;
	int		col;

	col = -1;
	determinant_ = 0;
	if (mtx_a.max == 2)
	{
		determinant_ = mtx_a.matrix[0][0] * mtx_a.matrix[1][1];
		determinant_ -= mtx_a.matrix[0][1] * mtx_a.matrix[1][0];
		return (determinant_);
	}
	while (++col < mtx_a.max)
		determinant_ += mtx_a.matrix[0][col] * cofactor(mtx_a, 0, col);
	return (determinant_);
}

t_mtx	submatrix(t_mtx mtx_a, int row, int col)
{
	t_mtx	submtx;
	int		i[2];
	int		jump[2];

	i[0] = -1;
	i[1] = -1;
	jump[0] = 0;
	jump[1] = 0;
	while (++i[0] < mtx_a.max - 1)
	{
		jump[0] += (jump[0] == 0 && i[0] == row);
		while (++i[1] < mtx_a.max - 1)
		{
			jump[1] += (jump[1] == 0 && i[1] == col);
			submtx.matrix[i[0]][i[1]] = \
			mtx_a.matrix[i[0] + jump[0]][i[1] + jump[1]];
		}
		i[1] = -1;
		jump[1] = 0;
	}
	submtx.max = mtx_a.max - 1;
	return (submtx);
}

double	cofactor(t_mtx mtx_a, int row, int col)
{
	double	sign;

	sign = ((row + col) % 2 == 0) + ((row + col) % 2 != 0) * -1;
	return (minor(mtx_a, row, col) * sign);
}

double	minor(t_mtx mtx_a, int row, int col)
{
	mtx_a = submatrix(mtx_a, row, col);
	return (determinant(mtx_a));
}
