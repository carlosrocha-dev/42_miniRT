/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:05:43 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:05:44 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_pattern	uv_pattern(double width, double height, t_color a, t_color b)
{
	t_pattern	new_pattern;

	new_pattern.has_pattern = TRUE;
	new_pattern.color_a = a;
	new_pattern.color_b = b;
	new_pattern.checkers.width = width;
	new_pattern.checkers.height = height;
	new_pattern.checkers.color_a = a;
	new_pattern.checkers.color_b = b;
	new_pattern.pattern_at = uv_checker_at;
	new_pattern.transform = get_identity_mtx();
	new_pattern.inverse = get_identity_mtx();
	new_pattern.transform = get_identity_mtx();
	return (new_pattern);
}

t_pattern	gradient_pattern(t_color color_a, t_color color_b)
{
	t_pattern	new_pattern;

	new_pattern.has_pattern = TRUE;
	new_pattern.color_a = color_a;
	new_pattern.color_b = color_b;
	new_pattern.pattern_at = gradient_at;
	new_pattern.transform = get_identity_mtx();
	new_pattern.inverse = get_identity_mtx();
	new_pattern.transform = get_identity_mtx();
	return (new_pattern);
}

t_pattern	stripe_pattern(t_color color_a, t_color color_b)
{
	t_pattern	new_pattern;

	new_pattern.has_pattern = TRUE;
	new_pattern.color_a = color_a;
	new_pattern.color_b = color_b;
	new_pattern.pattern_at = stripe_at;
	new_pattern.transform = get_identity_mtx();
	new_pattern.inverse = get_identity_mtx();
	new_pattern.transform = get_identity_mtx();
	return (new_pattern);
}

void	set_pattern_transform(t_pattern *pattern_, t_mtx transform)
{
	pattern_->transform = transform;
	pattern_->inverse = inverse(transform);
	pattern_->transpose = transpose(pattern_->inverse);
}

t_pattern	pattern(void)
{
	t_pattern	new_pattern;

	new_pattern.color_a = color(0, 0, 0);
	new_pattern.color_b = color(0, 0, 0);
	new_pattern.has_pattern = FALSE;
	new_pattern.pattern_at = stripe_at;
	new_pattern.transform = get_identity_mtx();
	new_pattern.inverse = get_identity_mtx();
	new_pattern.transform = get_identity_mtx();
	return (new_pattern);
}
