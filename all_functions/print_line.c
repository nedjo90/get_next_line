/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:59:14 by nhan              #+#    #+#             */
/*   Updated: 2023/11/07 23:11:48 by nhan             ###   ########.fr       */
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


char	*print_line(char *tab_str)
{
	size_t	i;
	char	*str;

	i = 0;
	while (tab_str[i] != '\n' && tab_str[i] != '\0')
		i++;
	if (tab_str[i] == '\n')
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (tab_str[i] != '\n' && tab_str[i] != '\0')
	{
		str[i] = tab_str[i];
		i++;
	}
	if (tab_str[i] == '\n')
	{
		str[i] = tab_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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

int main(void)
{
	char str[] = "\n\n\n\n\n\n\n\n\n\n";
	char *tab_str = strdup(str);
	char *ret;

	while (tab_str != NULL)
	{
		printf("tab_str>%s<\n", tab_str);
		ret = print_line(tab_str);
		printf("ret>%s<\n", ret);
		tab_str = clean_tab_str(tab_str);
		printf("clean>%s<\n", tab_str);
		printf("********************\n");
	}
	if (ret != NULL)
		free(ret);
	if (tab_str != NULL)
		free(tab_str);
	return (0);
}
