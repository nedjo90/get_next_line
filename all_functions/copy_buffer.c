/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:00:33 by nhan              #+#    #+#             */
/*   Updated: 2023/11/07 22:33:10 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

char	*ft_strdup(char	*str)
{
	size_t	i;
	char	*new_str;

	new_str = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while(str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
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

char	*copy_buffer(char *buffer, char *tab_str)
{
	char	*temp;

	if (tab_str == NULL)
		return(ft_strdup(buffer));
	else
		temp = ft_strjoin(tab_str, buffer);	
	if (!temp)
	{
		if (tab_str)
			free(tab_str);
		return (NULL);
	}
	if (tab_str == NULL)
		free(tab_str);
	return (temp);
}

int main(void)
{
	char str[] = "abcdef";
	char str2[] = "\n\n";
	char *buffer = strdup(str2);
	static char *tab_str;

	tab_str = strdup(str);
	tab_str = copy_buffer(buffer, tab_str);
	printf("%s", tab_str);
	free(buffer);
	free(tab_str);
	return (0);
}
