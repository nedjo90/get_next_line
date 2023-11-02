/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:22:24 by nhan              #+#    #+#             */
/*   Updated: 2023/11/02 13:11:33 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_copy_buffer(char *buffer, int bytes_read)
{
	char *str;
	int	i;

	str = (char *) malloc ((bytes_read + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < bytes_read && i < BUFFER_SIZE)
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


t_list	*ft_lstnew(char *content)
{
	t_list	*new_lst;

	new_lst = (t_list *) malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst[0].content = strdup(content);
	new_lst[0].next = NULL;
	return (new_lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!last)
		*lst = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

