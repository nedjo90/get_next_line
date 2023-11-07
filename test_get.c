/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:33:42 by nhan              #+#    #+#             */
/*   Updated: 2023/11/08 00:07:42 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main(void)
{
	int fd = open("test_files/42_with_nl", O_RDONLY);
	if (fd < 0)
	{
		write(1, "error open", 10);
		return (1);
	}
	char *str;
	while((str = get_next_line(fd)) != NULL)
	{
		write(1, str, strlen(str));
		free(str);
	}
	close(fd);
	return (0);
}
