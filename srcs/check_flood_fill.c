/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:47:21 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/12/25 14:47:21 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void freeMapCopy(char **map, int height) 
{
    int i;

    i = 0;
    while(i < height) 
    {
        free(map[i]);
        i++;
    }
    free(map); 
}

char **copyMap(char **original, int height, t_init_map *data) 
{
    char **copy;
    int i;

    i = 0;
    copy = malloc((height +1) * sizeof(char *));
    if (!copy) 
        exit_with_error("Failed to allocate memory for map copy", data);
    while (i < height)
    {
        copy[i] = ft_strdup(original[i]);
        if (!copy[i]) 
            exit_with_error("Failed to duplicate map row", data);
        i++;
    }
    copy[i] = NULL;
    return copy;
}


void floodFill(char **map, int x, int y, t_init_map *init) 
{
    char cell;
    if (x < 0 || x >= init->length  || y < 0 || y >= init->height)
        return;
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    cell = map[y][x];
    if (cell == 'C') {
        ft_printf("Collectable found at (%d, %d)\n", x, y);
        init->count--;
    } else if (cell == 'E') {
        ft_printf("Escape found at (%d, %d)\n", x, y);
        init->escape--;
    }
    map[y][x] = 'V';
    floodFill(map, x, y + 1, init);
    floodFill(map, x, y - 1, init); 
    floodFill(map, x + 1, y, init); 
    floodFill(map, x - 1, y, init); 
}


int validateMap(t_init_map *init) 
{
    char **mapCopy; 

    ft_printf("Validating map\n");
    mapCopy=copyMap(init->map, init->height, init);
    floodFill(mapCopy,  init->x, init->y, init);
    ft_printf("Done flood fill\n");
    freeMapCopy(mapCopy, init->height);
    if (init->count > 0) 
    {
        ft_printf("Not all collectables are reachable!\n");
        return 0;
    }
    if (init->escape > 0) 
    {
        ft_printf("The escape point is not reachable!\n");
        return 0;
    }
    return 1;
}



/*
void ft_return_initial(t_init_map *data)
{
    int x;
    int y;
    
    y = 0;
    while (data->map[y] != NULL) {
        x = 0;
        while (data->map[y][x] != '\0') {
            if (data->map[y][x] == 'V')
                data->map[y][x] = '0';
            x++;
        }
        y++;
    }
}
*/