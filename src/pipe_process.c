/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 08:57:09 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/24 11:53:23 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
	if (d->path1 && d->c1[0] && execve(d->path1, d->c1, envp) == -1)
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
	if (d->path2 && d->c2[0] && execve(d->path2, d->c2, envp) == -1)
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

void	simple_process(t_data *d, char **envp)
{
	pid_t	pid;
	int		fd1;
	int		fd2;

	pid = fork();
	if (pid == -1)
		clean_exit(d, FAIL);
	else if (pid == 0)
	{
		fd1 = open(d->file1, O_RDONLY, 0644);
		fd2 = open(d->file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd1 == -1 || fd2 == -1)
			clean_exit(d, FAIL);
		if (dup2(fd1, STDIN_FILENO) == -1)
			clean_exit(d, FAIL);
		if (dup2(fd2, STDOUT_FILENO) == -1)
			clean_exit(d, FAIL);
		if (d->path2 && d->c2[0] && execve(d->path2, d->c2, envp) == -1)
			clean_exit(d, FAIL);
		close(fd1);
		close(fd2);
	}
	waitpid(pid, NULL, 0);
}
