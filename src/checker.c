/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:48:28 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/15 17:46:19 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_files(t_data *d, char *file1, char *file2)
{
	d->fd1 = open(file1, O_RDONLY);
	if (d->fd1 == -1)
		return (FAIL);
	d->fd2 = open(file2, O_CREAT | O_RDWR, 0775);
	if (d->fd2 == -1)
		return (FAIL);
	d->file1 = file1;
	d->file2 = file2;
	return (OK);
}

void	check_command(t_data *d, char *cmd1, char *cmd2, char **paths)
{
	char	*tmp;
	int		i;

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
			free(d->path1);
			d->path1 = NULL;
		}
		if (access(d->path2, F_OK))
		{
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
	if (d->path1)
		free(d->path1);
	if (d->path2)
		free(d->path2);
	if (d->fd1)
		close(d->fd1);
	if (d->fd2)
		close(d->fd2);
	if (d->c1)
		free_double(d->c1);
	if (d->c2)
		free_double(d->c2);
	exit(1);
}
