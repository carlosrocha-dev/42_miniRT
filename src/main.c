/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:43:18 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:30:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, WIN_TITLE);
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, \
	&data->line_len, &data->endian);
}

int	main(int c, char **v)
{
	t_data	data;
	t_scene	scene;

	if (validate_args(c) || has_scene_is_valid(v[1]))
		return (FAILURE);
	printf("Scene is valid\n");
	printf("Opening file %s\n", v[1]);
	return_lines(&scene, v[1]);
	window(&data);
	render(&data, &scene);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 0, close_hook, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (SUCCESS);
}
