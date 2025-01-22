/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:40:18 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/12/23 21:40:18 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_wall(t_init_map *data)
{
    int i;
    
    i = 0;
    ft_printf(" Start check....\n");
    while (i < data -> length) {
        if (data->map[0][i] != '1' || data->map[data->height - 1][i] != '1')
        {
            ft_printf("Wall issue at top/bottom border: x = %d\n", i);
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < data -> height) {
        if (data->map[i][0] != '1' || data->map[i][data->length - 1] != '1')
        {
            ft_printf("Wall issue at left/right border: y= %d\n", i);
            ft_printf(" Place of  y :%c \n", data->map[i][data->length - 1]);
            return (1);
        }
        i++;
    }
    ft_printf("check completed\n");
    return(0);
}
int ft_check_char( t_init_map *data)
{
    int x;
    int y;
    
    y = 0;
    while (data->map[y] != NULL) {
        x = 0;
        while (data->map[y][x] != '\0') {
            if (data->map[y][x] != 'P' && data->map[y][x] != '0' &&
                data->map[y][x] != 'C' && data->map[y][x] != 'E' &&
                data->map[y][x] != '1')
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}
void ft_check_char_count(t_init_map *data)
{
    int x;
    int y;

    y =  0;
    while(data ->map[y] != NULL)
    {
        x = 0;
        while (data -> map[y][x] != '\0')
        {
            if (data -> map[y][x] == 'P')
            {
                data -> player++;
                data -> x = x;
                data -> y = y;
            }
            if (data -> map[y][x] == 'C')
                data -> count++;
            if (data -> map[y][x] == 'E')
                data -> escape++;
            x++;
        }
        y++;
    }
}
void ft_check_file(t_init_map *data)
{
    char	*b;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	b = "ber";
	len = ft_strlen(data->maps);
	if (len < 3)
		exit_with_error("Error.\nCheck file extension", data);
	i = len - 3;
	while (data->maps[i] != '\0' && b[j] != '\0')
	{
		if (data->maps[i] != b[j])
			exit_with_error("Error.\nCheck file extension", data);
		i++;
		j++;
	}
}
void ft_check(t_init_map *data)
{
    if (ft_check_wall(data) == 1)
        exit_with_error("Error. Map have no wall\n", data);
    if ( ft_check_char(data) == 1)
        exit_with_error("Error. Map have different error\n", data);
    ft_check_char_count(data);
    if (data -> count < 0 || data-> player != 1 || data -> escape != 1)
        exit_with_error("Error. Invalid map char count\n", data);
    ft_printf("Count:%d\n", data ->count);
    ft_printf("Start");
    if (validateMap(data)) {
        ft_printf("The map is valid!\n");
    } else {
        exit_with_error("The map is invalid!\n", data);
    }
    ft_check_char_count(data);
    data -> escape = 0;
    ft_printf("Count:%d\n", data ->count);
}
