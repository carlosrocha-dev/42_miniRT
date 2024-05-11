/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:03:40 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:03:41 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_material	material(void)
{
	t_material	new_material;

	new_material.color = color(1, 1, 1);
	new_material.diffuse = 0.9;
	new_material.specular = 0.9;
	new_material.shininess = 200.0;
	new_material.pattern = pattern();
	return (new_material);
}
