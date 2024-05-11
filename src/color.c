/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:03:06 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:03:07 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color	color(double red, double green, double blue)
{
	t_color	new_color;

	new_color.red = red;
	new_color.green = green;
	new_color.blue = blue;
	return (new_color);
}

t_color	add_c(t_color color_a, t_color color_b)
{
	t_color	new_color;

	new_color.red = color_a.red + color_b.red;
	new_color.green = color_a.green + color_b.green;
	new_color.blue = color_a.blue + color_b.blue;
	return (new_color);
}

t_color	subtract_c(t_color color_a, t_color color_b)
{
	t_color	new_color;

	new_color.red = color_a.red - color_b.red;
	new_color.green = color_a.green - color_b.green;
	new_color.blue = color_a.blue - color_b.blue;
	return (new_color);
}

t_color	multiply_c(t_color color, double scalar)
{
	t_color	new_color;

	new_color.red = color.red * scalar;
	new_color.green = color.green * scalar;
	new_color.blue = color.blue * scalar;
	return (new_color);
}

t_color	blend(t_color color_a, t_color color_b)
{
	t_color	new_color;

	new_color.red = color_a.red * color_b.red;
	new_color.green = color_a.green * color_b.green;
	new_color.blue = color_a.blue * color_b.blue;
	return (new_color);
}
