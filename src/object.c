/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:05:18 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:05:19 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	object(t_scene *scene)
{
	static t_object	objects[OBJ_MAX];
	static int		obj_number;

	if (!obj_number)
	{
		scene->objects = objects;
		scene->obj_number = &obj_number;
	}
	objects[obj_number].material = material();
	objects[obj_number].material.ambient = scene->ambient_light;
	objects[obj_number].transform = get_identity_mtx();
	objects[obj_number].inverse = get_identity_mtx();
	objects[obj_number].transpose = get_identity_mtx();
	obj_number += (obj_number < OBJ_MAX);
}

t_uple	normal_at(t_object object_, t_uple point_)
{
	t_uple	normal_at_;

	normal_at_ = multiply_mtx_tuple(object_.inverse, point_);
	normal_at_ = object_.normal_at(object_, normal_at_);
	normal_at_ = multiply_mtx_tuple(object_.transpose, normal_at_);
	normal_at_.w = 0;
	normal_at_ = normalize(normal_at_);
	return (normal_at_);
}

void	set_transform(t_object *object_, t_mtx transform)
{
	object_->transform = transform;
	object_->inverse = inverse(transform);
	object_->transpose = transpose(object_->inverse);
}
