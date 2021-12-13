/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:55:00 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/13 14:23:21 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int     check_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	close(fd);
	return (OK);
}

static int     check_command(char *cmd)
{
	if (!cmd)
		return (FAIL);
	return (OK);
}

void	clean_exit(t_data *d, int error)
{
	if (error == FAIL)
		write(1, "Error\n", 6);
/*	if (d->file1)
		free(d->file1); 
	if (d->file2)
		free(d->file2);
	if (d->cmd1)
		free(d->cmd1);*/
	if (d->cmd2)
		free(d->cmd2);
	exit(1);
}

void	read_stack(t_data *d, int argc, char **argv)
{
 //   if (argc == 2 && ft_strchr(argv[1], ' '))
//		args = ft_split(argv[1], ' ');
	if (argc < 5 /*|| ft_strncmp(argv[0], "./pipex", 7)*/)
		clean_exit(d, FAIL);
	else
	{
		if (!check_file(argv[1]) /*|| !check_file(argv[4])*/)
			clean_exit(d, FAIL);
		if (!check_command(argv[2]) || !check_command(argv[3]))
			clean_exit(d, FAIL);	
		d->file1 = argv[1];
		d->file2 = argv[4];
		d->cmd1 = argv[2];
		d->cmd2 = argv[3];
	}

//	if (argc == 2 && ft_strchr(argv[1], ' '))
//		free_double(args);
}