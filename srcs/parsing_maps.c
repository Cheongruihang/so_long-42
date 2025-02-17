/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:19:41 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/25 16:27:18 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_store_whole_map_data(t_init_map *data);

char	*ft_process_data(char *data)
{
	size_t	len;

	if (!data)
		return (NULL);
	len = ft_strlen(data);
	while (len > 0 && (data[len - 1] == '\r' || data[len - 1] == '\n'))
	{
		data[len - 1] = '\0';
		len--;
	}
	return (data);
}

void	parsing_maps(t_init_map *data)
{
	int		fd;
	char	*temp_map;

	fd = open(data->maps, O_RDONLY);
	temp_map = get_next_line(fd);
	if (!temp_map)
		exit_with_error_fd("Error. Data can't be retrieved\n", data, fd);
	temp_map = ft_process_data(temp_map);
	data->length = ft_strlen(temp_map);
	while (temp_map)
	{
		temp_map = ft_process_data(temp_map);
		if ((int)ft_strlen(temp_map) != data->length)
		{
			free(temp_map);
			close(fd);
			exit_with_error("Wrong number of length in map\n", data);
		}
		data->height++;
		free(temp_map);
		temp_map = get_next_line(fd);
	}
	close(fd);
	ft_store_whole_map_data(data);
}

void	ft_store_whole_map_data(t_init_map *data)
{
	int		fd;
	int		i;
	char	*temp_map;

	i = 0;
	data->map = (char **)malloc((data->height + 1) * sizeof(char *));
	if (!data->map)
		exit_with_error("Cannot allocate map", data);
	fd = open(data->maps, O_RDONLY);
	if (fd < 0)
		exit_with_error("Error opening map file", data);
	temp_map = get_next_line(fd);
	while (temp_map)
	{
		temp_map = ft_process_data(temp_map);
		data->map[i] = temp_map;
		i++;
		temp_map = get_next_line(fd);
	}
	data->map[i] = NULL;
	temp_map = NULL;
	close(fd);
}
