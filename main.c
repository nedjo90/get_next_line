/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:27:33 by nhan              #+#    #+#             */
/*   Updated: 2023/11/02 12:51:17 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define O_FAIL "Failed to open the test file\n"
#define O_SUC "Successed to open the test file\n"
#define R_FAIL "Failed to read the test file\n"
#define R_SUC "Successed to read the test file\n"
#define BUFFER_SIZE 10 


char	*get_next_line(int fd);

int main(int argc, char **argv)
{
	int	o_file;
	char 	star[] = "***********************************************\n";
	char	*str;

	(void)argc;
	o_file = open(argv[1], O_RDONLY);
	if(o_file < 0)
	{
		write(1, &O_FAIL, strlen(O_FAIL));
		return (EXIT_FAILURE);
	}
	else
	{
		write(1, O_SUC, strlen(O_SUC));
		write(1, "START\n", 6);
		str = get_next_line(o_file);
		if (str)
			write (1, str, strlen(str));
		write(1, "END\n", 5);
		free(str);
		write(1, "START\n", 6);
		str = get_next_line(o_file);
		if (str)
			write (1, str, strlen(str));
		write(1, "END\n", 5);
		free(str);
		write(1, "START\n", 6);
		str = get_next_line(o_file);
		if (str)
			write (1, str, strlen(str));
		write(1, "END\n", 5);
		write(1, star, strlen(star));
	}
	close(o_file);
	return (EXIT_SUCCESS);
}
