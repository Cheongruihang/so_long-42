/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:07:37 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/12/25 19:07:37 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_img(t_init_map *data, int j, int i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->player, j * 40, i * 40);
}

void	put_wall_img(t_init_map *data, int j, int i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->wall, (j) * 40, (i) * 40);
}

void	put_empty_img(t_init_map *data, int j, int i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->empty, (j) * 40, (i) * 40);
}

void	ft_create_map(t_init_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				put_wall_img(data, j, i);
			else if (data->map[i][j] == '0')
				put_empty_img(data, j, i);
			else if (data->map[i][j] == 'P')
				put_player_img(data, j, i);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->graph->exit, j * 40, i * 40);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->graph->collect, j * 40, i * 40);
			j++;
		}	
		i++;
	}
}
