/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:55:00 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/15 17:47:29 by igomez-p         ###   ########.fr       */
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
	d->fd1 = 0;
	d->fd2 = 0;
	d->c1 = NULL;
	d->c2 = NULL;
}

void	free_double(char **str)
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

	if (argc != 5)
		clean_exit(d, FAIL);
	else
	{
		while (!ft_strnstr(*envp, PATH, 4))
			envp++;
		paths = ft_split(*envp + 5, ':');
		d->c1 = ft_split(argv[2], ' ');
		d->c2 = ft_split(argv[3], ' ');
		check_command(d, d->c1[0], d->c2[0], paths);
		free_double(paths);
		if (!d->path1 || !d->path2 || !check_files(d, argv[1], argv[4]))
			clean_exit(d, FAIL);
		d->cmd1 = argv[2];
		d->cmd2 = argv[3];
	}
}

void	pipex_process(t_data *d, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		clean_exit(d, FAIL);
	pid = fork();
	if (pid == -1)
		clean_exit(d, FAIL);
	else if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(d->fd1, STDIN_FILENO);
		close(fd[0]);
		if (execve(d->path1, d->c1, envp) == -1)
			clean_exit(d, FAIL);
	}
	waitpid(pid, NULL, 0);
	dup2(fd[0], STDIN_FILENO);
	dup2(d->fd2, STDOUT_FILENO);
	close(fd[1]);
	if (execve(d->path2, d->c2, envp) == -1)
		clean_exit(d, FAIL);
	clean_exit(d, OK);
}
