/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:21:47 by nhan              #+#    #+#             */
/*   Updated: 2023/11/02 13:12:18 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_search_nl(t_list *list)
{
	t_list	*search;
	int	i;
	int	n;

	if (!list)
		return (0);
	search = list;
	n = 0;
	while(search)
	{
		i = 0;
		while (search->content[i] && i < BUFFER_SIZE)
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

char	*ft_copy_to_print(char *str, t_list *list)
{
	t_list	*puter;
	int	i;
	int	n;

	puter = list;
	n = 0;
	while (puter)
	{
		i = 0;	
		while (puter->content[i] && i < BUFFER_SIZE)
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
	str[n] = '\0';
	return (str);
}

char	*ft_put_nl(t_list *list)
{
	char	*str;

	if (list == NULL)
		return (0);	
	str = (char *) malloc ((ft_search_nl(list) + 1)  * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_copy_to_print(str, list);
	return (str);
}

void	ft_create_chained_list(int fd, t_list **list)
{
	char	*str;
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	t_list	*new;
	
	while (ft_search_nl(*list) == 0)
	{	
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return ;
		str = ft_copy_buffer(buffer, bytes_read);
		if (!str)
			return ;
		new = ft_lstnew(str);
		if (new == NULL)
			return ;
		ft_lstadd_back(list, new);	
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
		return (NULL);
	ft_create_chained_list(fd, &list);
	if (list == NULL)
		return (NULL);
	str = ft_put_nl(list);
	return (str);
}
