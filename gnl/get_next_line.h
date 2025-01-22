/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:05:04 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/08/25 12:13:25 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

void	ft_lstaddnode_back(t_list **lst, char *content);
void	ft_lstclear(t_list **lst);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

char	*get_next_line(int fd);
char	*process_the_line(t_list *data, char **temp_buffer);
char	*seperate_line(char *data, char **temp_buffer, char *buffer);
int		read_check_data(t_list **data, int fd);
#endif
