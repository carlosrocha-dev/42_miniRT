/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:45 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:07:46 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	cylinder(t_scene *scene, t_cylinder set_cyl)
{
	object(scene);
	scene->objects[*scene->obj_number - 1].cylinder = set_cyl;
	scene->objects[*scene->obj_number - 1].intersect = cylinder_discriminant;
	scene->objects[*scene->obj_number - 1].normal_at = cylinder_normal_at;
	scene->objects[*scene->obj_number - 1].material.map = cylinder_map;
	set_transform(&scene->objects[*scene->obj_number - 1], \
	multiply_mtx(translation(set_cyl.origin.x, set_cyl.origin.y, \
	set_cyl.origin.z), \
	multiply_mtx(full_rotation(set_cyl.direction), \
	scaling(set_cyl.radii, 1, set_cyl.radii))));
	scene->objects[*scene->obj_number - 1].cylinder.origin = point(0, 0, 0);
}

void	cone(t_scene *scene, t_cone set_cone)
{
	object(scene);
	scene->objects[*scene->obj_number - 1].cone = set_cone;
	scene->objects[*scene->obj_number - 1].intersect = cone_discriminant;
	scene->objects[*scene->obj_number - 1].normal_at = cone_normal_at;
	scene->objects[*scene->obj_number - 1].material.map = cone_map;
	set_transform(&scene->objects[*scene->obj_number - 1], \
	multiply_mtx(translation(set_cone.origin.x, set_cone.origin.y, \
	set_cone.origin.z), \
	multiply_mtx(full_rotation(set_cone.direction), \
	scaling(set_cone.radii, 1, set_cone.radii))));
	scene->objects[*scene->obj_number - 1].cone.origin = point(0, 0, 0);
}

void	plane(t_scene *scene, t_uple origin, t_uple direction)
{
	t_mtx	translate;
	t_mtx	rotate;

	object(scene);
	scene->objects[*scene->obj_number - 1].plane.origin = origin;
	scene->objects[*scene->obj_number - 1].material.specular = 0.5;
	scene->objects[*scene->obj_number - 1].intersect = plane_discriminant;
	scene->objects[*scene->obj_number - 1].normal_at = plane_normal_at;
	scene->objects[*scene->obj_number - 1].material.map = plane_map;
	translate = translation(origin.x, origin.y, origin.z);
	rotate = full_rotation(direction);
	set_transform(&scene->objects[*scene->obj_number - 1], \
	multiply_mtx(translate, rotate));
}

void	sphere(t_scene *scene, t_uple position, double radii)
{
	t_mtx	scale;
	t_mtx	translate;

	object(scene);
	scene->objects[*scene->obj_number - 1].sphere.origin = point(0, 0, 0);
	scene->objects[*scene->obj_number - 1].sphere.radii = radii / 2;
	scene->objects[*scene->obj_number - 1].material.diffuse = 0.7;
	scene->objects[*scene->obj_number - 1].material.specular = 0.3;
	scene->objects[*scene->obj_number - 1].intersect = sphere_discriminant;
	scene->objects[*scene->obj_number - 1].normal_at = sphere_normal_at;
	scene->objects[*scene->obj_number - 1].material.map = sphere_map;
	scale = scaling(radii / 2, radii / 2, radii / 2);
	translate = translation(position.x, position.y, position.z);
	set_transform(&scene->objects[*scene->obj_number - 1], \
	multiply_mtx(translate, scale));
}
