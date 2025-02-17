/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:22:14 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/25 12:40:17 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_init_map *data)
{
	(void) *data;
	exit(1);
}

void	ft_game_result(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_printf("Congratulations! You have completed the game!\n");
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	free_map(data);
	free_graphics(data);
	exit(0);
}

char	*ft_strdup(const char *src)
{
	char	*c;
	int		i;
	int		j;

	i = ft_strlen((char *)src);
	j = 0;
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (c != NULL)
	{
		while (src[j] != '\0')
		{
			c[j] = src[j];
			j++;
		}
		c[j] = '\0';
		return (c);
	}
	return (NULL);
}
