/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:21:47 by nhan              #+#    #+#             */
/*   Updated: 2023/10/31 16:54:05 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(char *content)
{
	t_list	*new_lst;

	new_lst = (t_list *) malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst[0].content = strdup(content);;
	new_lst[0].next = NULL;
	return (new_lst);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while (i < dstsize - 1 && dstsize != 0 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (size);
}

int	ft_search_nl(t_list *list)
{
	t_list	*search;
	int	n;
	int	i;

	n = 0;
	search = list;
	while(search->next != NULL)
	{
		i = 0;
		while (search->content[i])
		{
			if (search->content[i] == '\n')
				return (n);
			i++;
			n++;
		}
		search = search->next;
	}
	return (0);
}


char	*ft_put_nl(char *str, t_list *list)
{
	t_list	*puter;
	int	i;
	int	n;

	str = (char *) malloc ((ft_search_nl(list) + 1)  * sizeof(char));
	if (str ==NULL)
		return (NULL);
	puter = list;
	n = 0;
	while (puter->next != NULL)
	{
		i = 0;	
		while (puter->content[i])
		{
			str[n] = puter->content[i];
			if (puter->content[i] == '\n')
			{
				str[++n] = '\0';
				return (str);
			}
			n++;
			i++;
		}
		puter = puter->next;
	}
	return (str);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!last)
		*lst = new;
	else
	{
		last = ft_lstlast(last);
		last->next = new;
	}
}

char	*get_next_line(int fd)
{
	char	*str;
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	t_list	*new;
	static t_list	*list;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		str = (char *) malloc ((bytes_read + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, buffer, bytes_read + 1);	
		new = ft_lstnew(str);
		free(str);
		if (new == NULL)
			return (NULL);
		ft_lstadd_back(&list, new);	
		if (ft_search_nl(list))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	str = ft_put_nl(str, list);
	return (str);
}
