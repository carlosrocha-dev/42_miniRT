/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_discriminant_aux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:06:45 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:06:46 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	cylinder_caps(t_discr *new_discr, t_object object_, t_ray ray)
{
	double	result;
	double	t;

	if (object_.cylinder.closed == FALSE || fabs(ray.direction.y) < EPSILON)
		return ;
	t = (object_.cylinder.base - ray.origin.y) / ray.direction.y;
	result = ((ray.origin.x + t * ray.direction.x) * (ray.origin.x + t \
	* ray.direction.x)) + ((ray.origin.z + t * ray.direction.z) \
	* (ray.origin.z + t * ray.direction.z));
	if (result <= 1 && (new_discr->t < EPSILON || t < new_discr->t))
		new_discr->t = t;
	t = (object_.cylinder.top - ray.origin.y) / ray.direction.y;
	result = ((ray.origin.x + t * ray.direction.x) * (ray.origin.x + t \
	* ray.direction.x)) + ((ray.origin.z + t * ray.direction.z) \
	* (ray.origin.z + t * ray.direction.z));
	if (result <= 1 && (new_discr->t < EPSILON || t < new_discr->t))
		new_discr->t = t;
}

void	cone_caps(t_discr *new_discr, t_object object_, t_ray ray)
{
	double	result;
	double	t;

	if (object_.cone.closed == FALSE || fabs(ray.direction.y) < EPSILON)
		return ;
	t = (object_.cone.base - ray.origin.y) / ray.direction.y;
	result = ((ray.origin.x + t * ray.direction.x) * (ray.origin.x + t \
	* ray.direction.x)) + ((ray.origin.z + t * ray.direction.z) \
	* (ray.origin.z + t * ray.direction.z));
	if (result <= (object_.cone.base * object_.cone.base) \
	&& (new_discr->t < EPSILON || t < new_discr->t))
		new_discr->t = t;
	t = (object_.cone.top - ray.origin.y) / ray.direction.y;
	result = ((ray.origin.x + t * ray.direction.x) * (ray.origin.x + t \
	* ray.direction.x)) + ((ray.origin.z + t * ray.direction.z) \
	* (ray.origin.z + t * ray.direction.z));
	if (result <= (object_.cone.base * object_.cone.base) \
	&& (new_discr->t < EPSILON || t < new_discr->t))
		new_discr->t = t;
}

void	cone_expection(t_discr *d, double a, double b, double c)
{
	double	result;

	result = (-c) / (2.0 * b);
	if (fabs(a) < EPSILON)
	{
		if (result < EPSILON)
			return ;
		if (result < d->t)
			d->t = result;
	}
}
