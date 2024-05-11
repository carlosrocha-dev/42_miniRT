/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:28 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:07:29 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_cone	cone_set(t_uple position, t_uple direction, double radii, double h)
{
	t_cone	new_cone;

	new_cone.closed = TRUE;
	new_cone.origin = position;
	new_cone.direction = direction;
	new_cone.radii = radii / 2;
	new_cone.top = h / 2;
	new_cone.base = -h / 2;
	return (new_cone);
}

t_cylinder	cyl_set(t_uple position, t_uple direction, double radii, double h)
{
	t_cylinder	new_cylinder;

	new_cylinder.closed = TRUE;
	new_cylinder.origin = position;
	new_cylinder.direction = direction;
	new_cylinder.radii = radii / 2;
	new_cylinder.top = h / 2;
	new_cylinder.base = -h / 2;
	return (new_cylinder);
}
