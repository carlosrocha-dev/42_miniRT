/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:03:19 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:03:20 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	decimal_to_rgb(double color)
{
	if (color > 1)
		color = 1;
	color *= 255 + 0.5;
	return (color);
}

void	color_int(t_color *color)
{
	color->color_int = 0;
	color->color_int = decimal_to_rgb(color->red) << 16;
	color->color_int |= decimal_to_rgb(color->green) << 8;
	color->color_int |= decimal_to_rgb(color->blue);
}
