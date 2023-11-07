/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:30:47 by nhan              #+#    #+#             */
/*   Updated: 2023/11/07 16:51:12 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strdup(char	*str)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = ft_strlen(str);
	new_str = calloc(i + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	j = 0;
	while(j < i)
	{
		new_str[j] = str[j];
		j++;
	}
	return (new_str);
}

char	*copy_buffer(char *buffer, char *tab_str)
{
	char	*temp;

	if (tab_str == NULL)
		temp = ft_strdup(buffer);
	else
		temp = ft_strjoin(tab_str, buffer);	
	if (!temp)
	{
		if (tab_str)
			free(tab_str);
		return (NULL);
		free(tab_str);
	}
	tab_str = temp;
	return (temp);
}

size_t	ft_strlen(char const *str)
{	
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
