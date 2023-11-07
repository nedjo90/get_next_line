/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:30:22 by nhan              #+#    #+#             */
/*   Updated: 2023/11/07 16:50:00 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_tab_str(char *tab_str)
{
	size_t	i;
	size_t	j;
	char	*temp;

	while (tab_str[i] != '\n' && tab_str[i] != '\0')
		i++;
	if (tab_str[i] == '\n')
		i++;
	if (tab_str[i] == '\0')
	{
		free(tab_str);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(tab_str + 1) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i--;
	j = 0;
	while (tab_str[i] != '\0')
	{
		temp[j] = tab_str[j];
		i++;
		j++;
	}
	temp[j] = '\0';
	free(tab_str);
	return (temp);
}

char	*print_line(char *tab_str)
{
	size_t	i;
	char	*str;

	while (tab_str[i] != '\n' && tab_str[i] != '\0')
		i++;
	if (tab_str[i] == '\n')
		i++;
	str = calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	i--;
	while (i > 0)
	{
		str[i] = tab_str[i];
		i--;
	}
	str[i] = tab_str[i];
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)(b + i) = c;
		i++;
	}
	return (b);
}

char	*get_line(int fd, char *tab_str, char *buffer)
{
	int	bytes;

	bytes = 1;
	while(bytes >= 0)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(tab_str);
			return (NULL);
		}
		write(1, "\t", 1);
		write(1, buffer, bytes);

		write(1, "\n", 1);
		tab_str = copy_buffer(buffer, tab_str);
		write(1, tab_str, strlen(tab_str));

		write(1, "\n", 1);
		if (!tab_str)
			return (NULL);
		if (bytes == 0 || check_nl(tab_str) == 1)
			return (tab_str);
	}
	return (tab_str);
}

char	*get_next_line(int fd)
{
	static char	*tab_str[2048];
	//char	*str;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);	
	tab_str[fd] = get_line(fd, tab_str[fd], buffer);
	free(buffer);
	write(1, "ok!", 3);
	/*if (!tab_str[fd])
		return (NULL);
	str = print_line(tab_str[fd]);
	tab_str[fd] = clean_tab_str(tab_str[fd]);*/
	return (tab_str[fd]);
}
