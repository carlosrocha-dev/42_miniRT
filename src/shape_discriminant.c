/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_discriminant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:06:52 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:06:53 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_discr	cone_discriminant(t_ray ray_, t_object object_)
{
	double	calc[3];
	t_discr	new_discr;

	calc[0] = (ray_.direction.x * ray_.direction.x) \
	- (ray_.direction.y * ray_.direction.y) \
	+ (ray_.direction.z * ray_.direction.z);
	calc[1] = (2 * ray_.origin.x * ray_.direction.x) \
	- (2 * ray_.origin.y * ray_.direction.y) \
	+ (2 * ray_.origin.z * ray_.direction.z);
	new_discr.discriminant = (calc[1] * calc[1]) - 4 * calc[0] * \
	((ray_.origin.x * ray_.origin.x) - (ray_.origin.y * ray_.origin.y) \
	+ (ray_.origin.z * ray_.origin.z));
	new_discr.t = (-calc[1] - sqrt(new_discr.discriminant)) / (2 * calc[0]);
	calc[2] = (-calc[1] + sqrt(new_discr.discriminant)) / (2 * calc[0]);
	if (calc[2] < new_discr.t)
		new_discr.t = calc[2];
	new_discr.discriminant *= \
	((fabs(calc[0]) >= EPSILON && fabs(calc[1]) >= EPSILON) * 2) - 1;
	calc[2] = ray_.origin.y + new_discr.t * ray_.direction.y;
	new_discr.t *= (object_.cylinder.base < calc[2] \
	&& calc[2] < object_.cylinder.top);
	cone_expection(&new_discr, calc[0], calc[1], \
	((ray_.origin.x * ray_.origin.x) \
	- (ray_.origin.y * ray_.origin.y) + (ray_.origin.z * ray_.origin.z)));
	return (new_discr);
}

t_discr	cylinder_discriminant(t_ray ray_, t_object object_)
{
	double	calc[3];
	t_discr	new_discr;

	calc[0] = (ray_.direction.x * ray_.direction.x) \
	+ (ray_.direction.z * ray_.direction.z);
	calc[1] = (2 * ray_.origin.x * ray_.direction.x) \
	+ (2 * ray_.origin.z * ray_.direction.z);
	new_discr.discriminant = (calc[1] * calc[1]) - 4 * calc[0] * \
	((ray_.origin.x * ray_.origin.x) + (ray_.origin.z * ray_.origin.z) - 1);
	new_discr.t = (-calc[1] - sqrt(new_discr.discriminant)) / (2 * calc[0]);
	calc[2] = (-calc[1] + sqrt(new_discr.discriminant)) / (2 * calc[0]);
	if (calc[2] < new_discr.t)
		new_discr.t = calc[2];
	new_discr.discriminant *= ((fabs(calc[0]) >= EPSILON) * 2) - 1;
	calc[0] = ray_.origin.y + new_discr.t * ray_.direction.y;
	new_discr.t *= (object_.cylinder.base < calc[0] \
	&& calc[0] < object_.cylinder.top);
	cylinder_caps(&new_discr, object_, ray_);
	return (new_discr);
}

t_discr	plane_discriminant(t_ray ray_, t_object object_)
{
	t_discr	new_discr;

	(void)object_;
	new_discr.discriminant = -1;
	new_discr.t = -1;
	if (fabs(ray_.direction.y) >= EPSILON)
	{
		new_discr.discriminant = 1;
		new_discr.t = -ray_.origin.y / ray_.direction.y;
	}
	return (new_discr);
}

t_discr	sphere_discriminant(t_ray ray_, t_object object_)
{
	double	calc[3];
	t_discr	new_discr;
	t_uple	sphere_to_ray;

	sphere_to_ray = subtract(ray_.origin, object_.sphere.origin);
	calc[0] = dot(ray_.direction, ray_.direction);
	calc[1] = 2.0 * dot(ray_.direction, sphere_to_ray);
	new_discr.discriminant = (calc[1] * calc[1]) - 4 * calc[0] * \
	(dot(sphere_to_ray, sphere_to_ray) - 1);
	new_discr.t = (-calc[1] - sqrt(new_discr.discriminant)) / (2 * calc[0]);
	calc[2] = (-calc[1] + sqrt(new_discr.discriminant)) / (2 * calc[0]);
	if (calc[2] < new_discr.t)
		new_discr.t = calc[2];
	return (new_discr);
}
