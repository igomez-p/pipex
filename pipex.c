/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:37:24 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/17 17:42:50 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_stack(t_data *d, int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc != 5)
		clean_exit(d, FAIL);
	else
	{
		while (*envp && !ft_strnstr(*envp, PATH, 4))
			envp++;
		if (*envp)
		{
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
		else
			clean_exit(d, FAIL);
	}
}

static void	child_process(t_data *d, int *fd, char **envp)
{
	int	fd1;

	fd1 = open(d->file1, O_RDONLY, 0644);
	if (fd1 == -1)
		clean_exit(d, FAIL);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		clean_exit(d, FAIL);
	if (dup2(fd1, STDIN_FILENO) == -1)
		clean_exit(d, FAIL);
	close(fd[0]);
	close(fd1);
	close(fd[1]);
	if (execve(d->path1, d->c1, envp) == -1)
		clean_exit(d, FAIL);
}

static void	parent_process(t_data *d, int *fd, char **envp)
{
	int	fd2;

	fd2 = open(d->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 == -1)
		clean_exit(d, FAIL);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		clean_exit(d, FAIL);
	if (dup2(fd2, STDOUT_FILENO) == -1)
		clean_exit(d, FAIL);
	close(fd[1]);
	close(fd2);
	close(fd[0]);
	if (execve(d->path2, d->c2, envp) == -1)
		clean_exit(d, FAIL);
}

void	pipex_process(t_data *d, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		clean_exit(d, FAIL);
	pid1 = fork();
	if (pid1 == -1)
		clean_exit(d, FAIL);
	else if (pid1 == 0)
		child_process(d, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		clean_exit(d, FAIL);
	else if (pid2 == 0)
		parent_process(d, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;

	init_struct(&data);
	read_stack(&data, argc, argv, envp);
	pipex_process(&data, envp);
	clean_exit(&data, OK);
	return (0);
}
