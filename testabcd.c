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


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>

# define BUFFER_SIZE 42

char	*clean_tab_str(char *tab_str);
char	*print_line(char *tab_str);
char	*read_line(int fd, int bytes, char *tab_str, char *buffer);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*copy_buffer(char *buffer, char *tab_str);
char	*ft_strdup(char	*str);
size_t	ft_strlen(char const *str);
int		check_nl(char *str);

int main(void)
{
	char *tab_str = ("abc");
	char *src = strdup("0123456789");
	
	tab_str = copy_buffer(src, tab_str);
	if (src != NULL)
		free(src);
	if (tab_str != NULL)
	{
		printf("%s", tab_str);
		free(tab_str);
	}
	return (0);
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
	if (tab_str == NULL)
		free(tab_str);
	return (temp);
}

char	*read_line(int fd, int bytes, char *tab_str, char *buffer)
{
	while (bytes >= 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (bytes < 0)
		{
			free(buffer);
			free(tab_str);
			return (NULL);
		}
		tab_str = copy_buffer(buffer, tab_str);
		if (!tab_str)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes == 0 || check_nl(tab_str) == 1)
		{
			free(buffer);
			return (tab_str);
		}
		free(buffer);
	}
	return (tab_str);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buffer;
	static char	*tab_str[2048];
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	buffer = NULL;
	tab_str[fd] = read_line(fd, bytes, tab_str[fd], buffer);
	if (tab_str[fd] == NULL || *tab_str[fd] == '\0')
		return (NULL);
	str = print_line(tab_str[fd]);
	if (str == NULL || *str == '\0')
		return (NULL);
	tab_str[fd] = clean_tab_str(tab_str[fd]);
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
