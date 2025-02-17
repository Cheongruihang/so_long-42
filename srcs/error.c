/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:43:14 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/25 17:51:20 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error(const char *message, t_init_map *data)
{
	ft_printf("%s", message);
	free_map(data);
	free_graphics(data);
	exit(1);
}

void	exit_with_error_fd(const char *message, t_init_map *data, int fd)
{
	ft_printf("%s", message);
	free_map(data);
	free_graphics(data);
	close(fd);
	exit(1);
}
