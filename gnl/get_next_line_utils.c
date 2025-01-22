/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:04:51 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/08/18 15:06:50 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->content);
		free(temp);
	}
	*lst = NULL;
}

char	*ft_strchr(const char *s, int c)
{
	const char	*s_p;

	s_p = s;
	while (*s_p)
	{
		if (*s_p == (char)c)
			return ((char *)s_p);
		s_p++;
	}
	if (*s_p == (char)c)
		return ((char *)s_p);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	long	len_s1;
	long	len_s2;
	char	*dest;
	char	*dest_ptr;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(((len_s1 + len_s2) * sizeof(char)) + 1);
	if (!dest)
		return (NULL);
	dest_ptr = dest;
	while (*s1)
		*dest ++ = *s1++;
	while (*s2)
		*dest ++ = *s2++;
	*dest = '\0';
	return (dest_ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	char	*temp_ptr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	temp = (char *)malloc ((len * sizeof(char)) + 1);
	if (!temp)
		return (NULL);
	s += start;
	temp_ptr = temp;
	*(temp + len) = '\0';
	while (len-- && *s)
		*temp++ = *s++;
	return (temp_ptr);
}
