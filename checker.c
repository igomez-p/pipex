/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:48:28 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/17 17:46:44 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_data *d)
{
	d->file1 = NULL;
	d->file2 = NULL;
	d->path1 = NULL;
	d->path2 = NULL;
	d->cmd1 = NULL;
	d->cmd2 = NULL;
	d->c1 = NULL;
	d->c2 = NULL;
}

int	check_files(t_data *d, char *file1, char *file2)
{
	int	fd1;
	int	fd2;

	fd1 = open(file1, O_RDONLY, 0644);
	if (fd1 == -1)
		return (FAIL);
	fd2 = open(file2, O_CREAT | O_RDWR, 0644);
	if (fd2 == -1)
		return (FAIL);
	d->file1 = file1;
	d->file2 = file2;
	close(fd1);
	close(fd2);
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

void	clean_exit(t_data *d, int error)
{
	if (error == FAIL)
		write(1, "Error\n", 6);
	if (d->path1)
		free(d->path1);
	if (d->path2)
		free(d->path2);
	if (d->c1)
		free_double(d->c1);
	if (d->c2)
		free_double(d->c2);
	exit(1);
}
