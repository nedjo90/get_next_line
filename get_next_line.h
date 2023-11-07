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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

char	*clean_tab_str(char *tab_str);
char	*print_line(char *tab_str);
char	*get_line(int fd, int bytes, char *tab_str, char *buffer);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*copy_buffer(char *buffer, char *tab_str);
char	*ft_strdup(char	*str);
size_t	ft_strlen(char const *str);
int		check_nl(char *str);

#endif
