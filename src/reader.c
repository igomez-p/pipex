/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:55:00 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/13 18:43:49 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_struct(t_data *d)
{
	d->file1 = NULL;
	d->file2 = NULL;
	d->path1 = NULL;
	d->path2 = NULL;
	d->cmd1 = NULL;
	d->cmd2 = NULL;
}

static void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	read_stack(t_data *d, int argc, char **argv, char **envp)
{
	char **paths;

	if (argc != 5)
		clean_exit(d, FAIL);
	else
	{
		while (!ft_strnstr(*envp, PATH, 4))
			envp++;
		paths = ft_split(*envp + 5, ':');
		// TODO: enviar los comandos principales (por ej: de "ls -l" enviar solo "ls")
		check_command(d, argv[2], argv[3], paths);
		free_double(paths);
		if (!d->path1 || !d->path2 || !check_files(d, argv[1], argv[4]))
			clean_exit(d, FAIL);
		d->cmd1 = argv[2];
		d->cmd2 = argv[3];
	}
}