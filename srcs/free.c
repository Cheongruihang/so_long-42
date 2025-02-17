/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:40:57 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/25 17:45:12 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graphics(t_init_map *data)
{
	if (data->graph)
	{
		if (data->graph->player)
			mlx_destroy_image(data->mlx, data->graph->player);
		if (data->graph->wall)
			mlx_destroy_image(data->mlx, data->graph->wall);
		if (data->graph->empty)
			mlx_destroy_image(data->mlx, data->graph->empty);
		if (data->graph->exit)
			mlx_destroy_image(data->mlx, data->graph->exit);
		if (data->graph->collect)
			mlx_destroy_image(data->mlx, data->graph->collect);
		if (data->graph->winner)
			mlx_destroy_image(data->mlx, data->graph->winner);
		free(data->graph);
		data->graph = NULL;
	}
}

void	free_map(t_init_map *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}
