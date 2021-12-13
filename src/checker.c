/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:48:28 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/13 18:43:41 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_files(t_data *d, char *file1, char *file2)
{
	int fd;

	fd = open(file1, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	close(fd);
	fd = open(file2, O_CREAT | O_RDWR, 0775);
	if (fd == -1)
		return (FAIL);
	close(fd);
	d->file1 = file1;
	d->file2 = file2;
	return (OK);
}

void	check_command(t_data *d, char *cmd1, char *cmd2, char **paths)
{
	char *tmp;
	int i;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!d->path1)
			d->path1 = ft_strjoin(tmp, cmd1);
		if (!d->path2)
			d->path2 = ft_strjoin(tmp, cmd2);
		free(tmp);
		if (access(d->path1, F_OK))
		{
			printf("error cmd1: %s\n", d->path1);
			free(d->path1);
			d->path1 = NULL;
		}
		if (access(d->path2, F_OK))
		{
			printf("error cmd2: %s\n", d->path2);
			free(d->path2);
			d->path2 = NULL;
		}
		if (d->path1 && d->path2)
			break ;
	}
}

void	clean_exit(t_data *d, int error)
{
	if (error == FAIL)
		write(1, "Error\n", 6);
	if (d->cmd1)
		free(d->cmd1);
	if (d->cmd2)
		free(d->cmd2);
	exit(1);
}