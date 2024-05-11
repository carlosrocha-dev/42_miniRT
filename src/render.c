/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:06:11 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:12:23 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (SUCCESS);
}

int	first_hit(t_scene *scene, t_render *render)
{
	t_discr	discr;
	int		index;

	index = -1;
	render->hit = __FLT_MAX__;
	while (++index < *scene->obj_number)
	{
		discr = scene->objects[index].intersect(transform(render->ray, \
		scene->objects[index].inverse), scene->objects[index]);
		if (discr.discriminant < 0.0)
			continue ;
		if (discr.t > EPSILON && discr.t < render->hit)
		{
			render->hit = discr.t;
			render->hit_object = scene->objects[index];
		}
	}
	if (render->hit == __FLT_MAX__)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	close_hook(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (SUCCESS);
}

static void	write_pixel(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	render(t_data *data, t_scene *scene)
{
	int			px;
	int			py;
	t_render	render;

	px = -1;
	py = -1;
	while (++py < WIN_H - 1)
	{
		while (++px < WIN_W - 1)
		{
			render.ray = ray_for_pixel(scene->camera, px, py);
			if (first_hit(scene, &render))
				continue ;
			color_setup(&render, scene);
			write_pixel(data, px, py, render.final_color.color_int);
		}
		px = -1;
		ft_printf("\rRendering: %d%%", (int)(py * 100.0 / WIN_H));
	}
	ft_printf("\rRendering: 100%%\n");
	return (SUCCESS);
}
