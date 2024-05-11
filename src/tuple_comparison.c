/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_comparison.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:57 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:07:58 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	equal(double number_a, double number_b)
{
	if (fabs(number_a - number_b) < EPSILON)
		return (TRUE);
	else
		return (FALSE);
}

int	equal_tuple(t_uple tuple_a, t_uple tuple_b)
{
	if (!equal(tuple_a.x, tuple_b.x))
		return (FALSE);
	if (!equal(tuple_a.y, tuple_b.y))
		return (FALSE);
	if (!equal(tuple_a.z, tuple_b.z))
		return (FALSE);
	if (!equal(tuple_a.w, tuple_b.w))
		return (FALSE);
	return (TRUE);
}
