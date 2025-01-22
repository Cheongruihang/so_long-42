/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:22:14 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/12/21 18:22:14 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void exit_with_error(const char *message, t_init_map *data)
{
    ft_printf("%s",message);
    free_map(data);
    free_graphics(data);
    exit(1);
}

void free_map(t_init_map *data) 
{
    int i;

    i = 0;
    if (data->map) {
        while (data->map[i]!= NULL) {
            free(data->map[i]);
            i++;
        }
        free(data->map);
    }
}

void ft_game_result(t_init_map *data)
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


