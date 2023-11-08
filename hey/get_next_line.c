/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:31:52 by nhan              #+#    #+#             */
/*   Updated: 2023/11/07 23:51:26 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

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
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
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

	if (*buffer == '\0' || buffer == NULL)
		return (tab_str);
	else if (tab_str == NULL)
	{
		tab_str = ft_strdup(buffer);
		if (tab_str == NULL)
			return (NULL);
		return (tab_str);
	}
	else
		temp = ft_strjoin(tab_str, buffer);
	if (!temp)
	{
		if (tab_str)
			free(tab_str);
		return (NULL);
	}
	if (tab_str != NULL)
		free(tab_str);
	return (temp);
}

char	*read_line(int fd, char *tab_str, char *buffer)
{
	int	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(tab_str);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tab_str = copy_buffer(buffer, tab_str);
		if (!tab_str)
			return (NULL);
		if (bytes == 0 && check_nl(tab_str) == 1)
			return (tab_str);
	}
	return (tab_str);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buffer;
	static char	*tab_str[2048];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	tab_str[fd] = read_line(fd, tab_str[fd], buffer);
	free(buffer);
	if (!tab_str[fd])
		return (NULL);
	str = print_line(tab_str[fd]);
	if (str == NULL || *str == '\0')
		return (NULL);
	buffer = clean_tab_str(tab_str[fd]);
	free(tab_str[fd]);
	tab_str[fd] = buffer;
	return (str);
}
