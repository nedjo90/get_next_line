/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <necat.han42@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:04:00 by nhan              #+#    #+#             */
/*   Updated: 2023/11/05 18:02:44 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#define ECHEC_OUV "Echec de l'ouverture du fichier "
#define	LIGNES  " ligne(s):\n"


void	message(const char *str1, const char *str2)
{
	write(1, str1, strlen(str1));
	write(1, str2, strlen(str2));
	write(1, "\n", 2);
}

int	print_lines(const char *input_path, const char *output_path, unsigned long n)
{
	FILE *fp = fopen(input_path, "r");//input
	if (fp == NULL)
	{	
		message(ECHEC_OUV, input_path);
		return(1);
	}
	int fc = open(output_path, O_WRONLY | O_CREAT | O_TRUNC, 0777); //output
	if (fc < 0)
	{
		message(ECHEC_OUV, output_path);
		return(1);
	}
	char *line = NULL;
	size_t len = 0;
	unsigned long i = 0;
	while (getline(&line, &len, fp) > 0 & i < n)
	{
		write(fc,line, strlen(line));
		i++;
	}
	fclose(fp);
	close(fc);
	free(line);
	return (0);

}

char	*creat_command(const char *s1, const char *s2)
{
	char *command;
	char diff[] = "diff";
	int	i;
	int	j;

	command = (char *) malloc ((strlen(diff) + strlen(s1) + strlen(s2) + 4) * sizeof(char));
	if (!command)
		return (NULL);
	i = 0;
	j = 0;
	while (diff[j] != '\0')
	{
		command[i] = diff[j];
		i++;
		j++;
	}
	command[i++] = ' ';
	j = 0;
	while (s1[j] != '\0')
	{
		command[i] = s1[j];
		i++;
		j++;
	}
	command[i++] = ' ';
	j = 0;
	while (s2[j] != '\0')
	{
		command[i] = s2[j];
		i++;
		j++;
	}
	command[i] = '\0';
	return (command);
}

int	make_the_diff(const char *s1, const char *s2)
{
	
	char	*command;

	command  = creat_command(s1, s2);
	if (!command)
	{
		message("la commande diff n'a pas pu être créée.", "");
		return (1);
	}
	
	//execute la commande diff
	int status = system(command);

	if (status == 0)
	{
		free(command);
		//message("les fichiers sont identiques.", "");
		return (0);
	}
	if (WIFEXITED(status)) 
	{
        // La commande s'est exécutée, mais les fichiers sont différents
        	message("Les fichiers sont différents :", "");
		message("\t--->   ", s1);
		message("\t--->   ", s2);
		free(command);
		return (1);
    	} 
    	else 
	{
        // Erreur lors de l'exécution de la commande
        	message("Erreur lors de la comparaison des fichiers.", "");
    		free(command);
		return (2);
	}
	free(command);
	return (0);
}

int 	test_funct(const char *s1, const char *s2)
{
	size_t i = 0;
	size_t tab[] = {0, 1, 2, 4, 5, 7, 20, 100, INT_MAX, ULONG_MAX};
	char	*size[] = {"0", "1", "2", "4", "5", "7", "20", "100", "2147483647", "18446744073709551615"};

	while (i < 10)
	{
		message(size[i], LIGNES);
		if (print_lines(s1, s2, tab[i]))
		{
			message("Echec de création des lignes", ""); 
			return (1);	
		}
		if (make_the_diff(s1, s2))
		{
			message("Voir diff _^", "");
			return (1);
		}
		i++;
	}
	return (0);
}

char	*join(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!(join = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char))))
	{
		message("Echec malloc sur ", "");
		message(s1, s2);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	while (j < strlen(s2))
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
	return (join);
}



int main(void)
{
	size_t	i = 0;
	char	*s1;
	char 	*s2;
	char	star[] = "*********************************";
	char *tab[] = {
			"41_no_nl",
			"alternate_line_nl_no_nl",
			"multiple_line_no_nl",
			"41_with_nl",
			"alternate_line_nl_with_nl",
			"multiple_line_with_nl",
			"42_no_nl",
			"big_line_no_nl",
			"multiple_nlx5",
			"42_with_nl",
			"big_line_with_nl",
			"nl",
			"43_no_nl",
			"empty",
			"43_with_nl",
			NULL
			};
	while (tab[i] != NULL)
	{
		write(1, "\n", 1);
		write(1, star, strlen(star)); 
		write(1, tab[i], strlen(tab[i]));
		write(1, star, strlen(star)); 
		write(1, "\n", 1);
		s1 = join("test/", tab[i]);
		if(!s1)
			return (1);
		s2 = join("output/", tab[i]);
		if (!s2)
		{
			free(s1);
			return (1);
		}
		if (test_funct(s1,s2))
		{
			free(s1);
			free(s2);
			return (1);
		}
		free(s1);
		free(s2);
		i++;
	}
	message("FINI AVEC SUCCES !", "");
	return (0);
}
