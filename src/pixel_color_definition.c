/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color_definition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:05:51 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:05:52 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_uple	reflect(t_uple in, t_uple normal)
{
	t_uple	reflect_;

	reflect_ = subtract(in, multiply(multiply(normal, 2), dot(in, normal)));
	return (reflect_);
}

t_color	lighting(t_object object_, t_plight light, t_uple point, t_eye eye)
{
	t_color	effect_color;
	t_color	new_color;
	t_uple	lightv;
	double	r;

	if (object_.material.pattern.has_pattern)
		new_color = pattern_at(object_.material, object_, point);
	else
		new_color = object_.material.color;
	effect_color = blend(new_color, light.intensity);
	lightv = normalize(subtract(light.position, point));
	new_color = blend(effect_color, object_.material.ambient);
	r = dot(lightv, eye.normalv);
	if (r >= 0 && !light.shadow)
		new_color = add_c(new_color, \
		multiply_c(multiply_c(effect_color, object_.material.diffuse), r));
	lightv = reflect(negate(lightv), eye.normalv);
	r = dot(lightv, eye.eyev);
	if (r > 0)
	{
		r = pow(r, object_.material.shininess);
		new_color = add_c(new_color, \
		multiply_c(multiply_c(light.intensity, object_.material.specular), r));
	}
	return (new_color);
}

int	is_shadow(t_render *render, t_scene *scene, int index)
{
	t_render	render_tmp;
	t_uple		direction;

	direction = subtract(scene->plights[index].position, render->over_point);
	render_tmp.ray = ray(render->over_point, normalize(direction));
	first_hit(scene, &render_tmp);
	if (!first_hit(scene, &render_tmp) && render_tmp.hit < magnitude(direction))
		return (TRUE);
	return (FALSE);
}

void	shade_hit(t_render *render, t_scene *scene)
{
	int	index;

	index = -1;
	render->final_color = color(0, 0, 0);
	while (++index < *scene->plight_number)
	{
		scene->plights[index].shadow = is_shadow(render, scene, index);
		render->final_color = add_c(render->final_color, \
		lighting(render->hit_object, scene->plights[index], \
		render->point, render->eye));
	}
	color_int(&render->final_color);
}

void	color_setup(t_render *render, t_scene *scene)
{
	render->point = position(render->ray, render->hit);
	render->point.w = 1;
	render->eye.normalv = normal_at(render->hit_object, render->point);
	render->eye.eyev = negate(render->ray.direction);
	if (dot(render->eye.normalv, render->eye.eyev) < 0)
		render->eye.normalv = negate(render->eye.normalv);
	render->over_point = add(render->point, \
	multiply(render->eye.normalv, EPSILON));
	shade_hit(render, scene);
}
