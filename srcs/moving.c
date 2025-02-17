/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:16 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/25 16:31:27 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	move_w(t_init_map *data)
{
	if (data->map[data->y - 1][data->x] != '1'
	&& data->map[data->y - 1][data->x] != 'E')
	{
		if (data->map[data->y - 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
			data->count--;
		}
		else if (data->map[data->y - 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		data->y--;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
	if (data->map[data->y - 1][data->x] == 'E'
			&& data->count == 0)
		ft_game_result(data);
}

void	move_s(t_init_map *data)
{
	if (data->map[data->y + 1][data->x] != '1'
		&& data->map[data->y + 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
			data->count--;
		}
		else if (data->map[data->y + 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
		}
		data->y++;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
	if (data->map[data->y + 1][data->x] == 'E'
			&& data->count == 0)
		ft_game_result(data);
}

void	move_a(t_init_map *data)
{
	if (data->map[data->y][data->x - 1] != '1'
		&& data->map[data->y][data->x - 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
			data->count--;
		}
		else if (data->map[data->y][data->x - 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		data->x--;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
	if (data->map[data->y][data->x - 1] == 'E'
			&& data->count == 0)
		ft_game_result(data);
}

void	move_d(t_init_map *data)
{
	if (data->map[data->y][data->x + 1] != '1'
		&& data->map[data->y][data->x + 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
			data->count--;
		}
		else if (data->map[data->y][data->x + 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		data->x++;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
	if (data->map[data->y][data->x + 1] == 'E'
			&& data->count == 0)
		ft_game_result(data);
}

int	press_key(int keycode, t_init_map *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		move_w(data);
	else if (keycode == A)
		move_a(data);
	else if (keycode == S)
		move_s(data);
	else if (keycode == D)
		move_d(data);
	return (0);
}
