/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:30:47 by nhan              #+#    #+#             */
/*   Updated: 2023/12/08 21:11:26 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_tab_str(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*clean_tab_str(char *tab_str)
{
	char	*ptr;
	char	*new_tab_str;
	int		size;

	ptr = ft_strchr(tab_str, '\n');
	if (!ptr)
	{
		new_tab_str = NULL;
		return (free_tab_str(&tab_str));
	}
	else
		size = (ptr - tab_str) + 1;
	if (!tab_str[size])
		return (free_tab_str(&tab_str));
	new_tab_str = ft_substr(tab_str, size, ft_strlen(tab_str) - size);
	free_tab_str(&tab_str);
	if (!new_tab_str)
		return (NULL);
	return (new_tab_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (0);
	i = 0;
	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
