/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:30:47 by nhan              #+#    #+#             */
/*   Updated: 2023/11/07 23:36:23 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_tab_str(char *tab_str)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (tab_str[i] != '\n' && tab_str[i] != '\0')
		i++;
	if (tab_str[i] == '\n')
		i++;
	if (tab_str[i] == '\0')
	{
		free(tab_str);
		return (NULL);
	}
	temp = ft_strdup(tab_str + i);
	free(tab_str);
	return (temp);
}

char	*ft_strdup(char	*str)
{
	size_t	i;
	char	*new_str;

	new_str = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (count == 0 && size == 0)
		count = 1;
	else if (count == 0 || size == 0)
		return (NULL);
	else if ((((int)count < 0 && (int)size < 0) \
		|| count >= 2147483647 || size >= 2147483647))
		return (NULL);
	ptr = malloc((int)size * (int)count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size && size > 0)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}

int	check_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
