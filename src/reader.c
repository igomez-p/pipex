/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:55:00 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/14 19:54:58 by igomez-p         ###   ########.fr       */
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
	char	**paths;
	char	**tmp_cmd1;
	char	**tmp_cmd2;

	if (argc != 5)
		clean_exit(d, FAIL);
	else
	{
		while (!ft_strnstr(*envp, PATH, 4))
			envp++;
		paths = ft_split(*envp + 5, ':');
		tmp_cmd1 = ft_split(argv[2], ' ');
		tmp_cmd2 = ft_split(argv[3], ' ');
		check_command(d, tmp_cmd1[0], tmp_cmd2[0], paths);
		free_double(paths);
		free_double(tmp_cmd1);
		free_double(tmp_cmd2);
		if (!d->path1 || !d->path2 || !check_files(d, argv[1], argv[4]))
			clean_exit(d, FAIL);
		d->cmd1 = argv[2];
		d->cmd2 = argv[3];
	}
}

void	pipex_process(t_data *d)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		clean_exit(d, FAIL);
	pid = fork();
}
