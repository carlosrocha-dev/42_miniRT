/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:06:19 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:06:20 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ambient_light(t_scene *scene, t_color intensity)
{
	scene->ambient_light = intensity;
}

void	point_light(t_scene *scene, t_uple position, t_color intensity)
{
	static t_plight	plights[OBJ_MAX];
	static int		plight_number;

	if (!plight_number)
	{
		scene->plights = plights;
		scene->plight_number = &plight_number;
	}
	plights[plight_number].position = position;
	plights[plight_number].intensity = intensity;
	plight_number += (plight_number < OBJ_MAX);
}
