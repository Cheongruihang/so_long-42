/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:04:59 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/08/25 12:26:51 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstadd_back(t_list **lst, char *content);
char	*process_the_line(t_list *data, char **temp_buffer);
char	*seperate_line(char *data, char **temp_buffer, char *buffer);
int		read_check_data(t_list **data, int fd);

char	*get_next_line(int fd)
{
	static t_list	*lst_buffer;
	char			*buff;
	char			*temp_buffer;
	int				line_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buff, 0) < 0)
		return (NULL);
	temp_buffer = NULL;
	line_read = read_check_data(&lst_buffer, fd);
	if (line_read < 0 || (line_read == 0 && !lst_buffer))
		return (NULL);
	buff = process_the_line(lst_buffer, &temp_buffer);
	ft_lstclear(&lst_buffer);
	if (temp_buffer)
	{
		ft_lstaddnode_back(&lst_buffer, temp_buffer);
		free(temp_buffer);
	}
	return (buff);
}

char	*process_the_line(t_list *data, char **temp_buffer)
{
	char	*buffer;
	char	*temp;

	buffer = malloc(1);
	buffer[0] = '\0';
	while (data)
	{
		if (ft_strchr(data->content, '\n') == NULL)
		{
			temp = ft_strjoin(buffer, data->content);
			free(buffer);
			buffer = temp;
		}
		else
		{
			buffer = seperate_line(data->content, temp_buffer, buffer);
			return (buffer);
		}
		data = data -> next;
	}
	return (buffer);
}

char	*seperate_line(char *data, char **temp_buffer, char *buffer)
{
	size_t	i;
	char	*buff2;
	char	*temp;

	i = 0;
	while (data[i] != '\n')
		i++;
	buff2 = ft_substr(data, 0, i + 1);
	temp = ft_strjoin(buffer, buff2);
	free(buffer);
	free(buff2);
	if (data[i + 1] != '\0')
		*temp_buffer = ft_substr(data, i + 1, ft_strlen(data) - i - 1);
	return (temp);
}

void	ft_lstaddnode_back(t_list **lst, char *content)
{
	t_list	*last_check;
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return ;
	new -> content = ft_strjoin("", content);
	new -> next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_check = *lst;
	while (last_check -> next)
		last_check = last_check -> next;
	last_check -> next = new;
}

int	read_check_data(t_list **data, int fd)
{
	t_list	*lst_buffer;
	char	*buffer;
	int		size;

	while (1)
	{
		lst_buffer = *data;
		while (lst_buffer)
		{
			if (ft_strchr (lst_buffer -> content, '\n'))
				return (1);
			lst_buffer = lst_buffer -> next;
		}
		buffer = malloc(BUFFER_SIZE + 1);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
		{
			free(buffer);
			return (size);
		}
		buffer[size] = '\0';
		ft_lstaddnode_back(data, buffer);
		free(buffer);
	}
}
