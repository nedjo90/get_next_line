/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:33:42 by nhan              #+#    #+#             */
/*   Updated: 2023/11/07 16:16:49 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main(void)
{
	int fd = open("first_test", O_RDONLY);
	if (fd < 0)
	{
		write(1, "error open", 10);
		return (1);
	}
	char *str = get_next_line(fd);
	write(1, str, strlen(str));
	close(fd);
	return (0);
}
