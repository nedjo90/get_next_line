/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tab_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:58:16 by nhan              #+#    #+#             */
/*   Updated: 2023/11/07 21:06:56 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char	*clean_tab_str(char *tab_str)
{
	size_t	i;
	size_t	j;
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
	temp = ft_calloc(ft_strlen(tab_str + i) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	j = 0;
	while (tab_str[i] != '\0')
	{
		temp[j] = tab_str[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	free(tab_str);
	return (temp);
}
