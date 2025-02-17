/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:30:54 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/25 17:04:06 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_graphics(t_init_map *data)
{
	int	img_height;
	int	img_width;

	data->graph = malloc(sizeof(t_graph));
	if (!data -> graph)
		exit_with_error("Error: Memory allocation failed", data);
	data->graph->player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&img_width, &img_height);
	data->graph->wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&img_width, &img_height);
	data->graph->empty = mlx_xpm_file_to_image(data->mlx, EMPTY,
			&img_width, &img_height);
	data->graph->exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&img_width, &img_height);
	data->graph->collect = mlx_xpm_file_to_image(data->mlx, COLLECT,
			&img_width, &img_height);
	data->graph->winner = mlx_xpm_file_to_image(data->mlx, WIN,
			&img_width, &img_height);
}

void	ft_initialise_struct(t_init_map *data, char *fd)
{
	data -> map = NULL;
	data -> height = 0;
	data -> length = 0;
	data -> x = 0;
	data -> y = 0;
	data -> player = 0;
	data -> count = 0;
	data -> step = 0;
	data -> escape = 0;
	data -> maps = fd;
	ft_graphics(data);
}

int	ft_frame(t_init_map *data)
{
	ft_create_map(data);
	return (0);
}

int	close_window(t_init_map *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	free_map(data);
	free_graphics(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_init_map	data;

	if (argc != 2)
		exit_with_error("Error, Variable must be 2", &data);
	else
	{
		data.mlx = mlx_init();
		ft_initialise_struct(&data, argv[1]);
		ft_check_file(&data);
		parsing_maps(&data);
		ft_check(&data);
		data.win = mlx_new_window(data.mlx, data.length * 40,
				data.height * 40, "so_long");
		mlx_hook(data.win, 2, 1, press_key, &data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_loop_hook(data.mlx, ft_frame, &data);
		mlx_loop(data.mlx);
	}
	free_map(&data);
	free_graphics(&data);
	return (0);
}
