/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 08:59:07 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/24 09:29:11 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	relative_path(t_data *d, char **argv)
{
	char	**tmp;

	if (argv[2][0] == '/' || (argv[2][0] == '.' && argv[2][1] == '/'))
	{
		tmp = ft_split(argv[2], ' ');
		d->path1 = ft_strdup(tmp[0]);
		d->cmd1 = argv[2];
		free_double(tmp);
	}	
	if (argv[3][0] == '/' || (argv[3][0] == '.' && argv[3][1] == '/'))
	{
		tmp = ft_split(argv[3], ' ');
		d->path2 = ft_strdup(tmp[0]);
		d->cmd2 = argv[3];
		free_double(tmp);
	}
}

void	read_stack(t_data *d, char **argv, char **envp)
{
	char	**paths;

	relative_path(d, argv);
	while (*envp && !ft_strnstr(*envp, PATH, 4))
		envp++;
	if (*envp)
	{
		paths = ft_split(*envp + 5, ':');
		d->c1 = ft_split(argv[2], ' ');
		d->c2 = ft_split(argv[3], ' ');
		check_command(d, d->c1[0], d->c2[0], paths);
		free_double(paths);
		if ((!d->path1 && d->c1[0]) || (!d->path2 && d->c2[0]))
			clean_exit(d, FAIL);
		if (!check_files(d, argv[1], argv[4]))
			clean_exit(d, FAIL);
		if (!d->cmd1)
			d->cmd1 = argv[2];
		if (!d->cmd2)
			d->cmd2 = argv[3];
	}
	else
		clean_exit(d, FAIL);
}

static void	copy_case(t_data *d)
{
	if (d->c2 && d->c2[0])
		free_double(d->c2);
	else if (d->c2)
		free(d->c2);
	d->c2 = (char **)malloc(sizeof(char *) * 4);
	if (!d->c2)
		clean_exit(d, FAIL);
	d->c2[0] = ft_strdup("/bin/cp");
	d->c2[1] = ft_strdup(d->file1);
	d->c2[2] = ft_strdup(d->file2);
	d->c2[3] = NULL;
	d->path2 = ft_strdup("/bin/cp");
}

static int	is_command(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (FAIL);
	return (OK);
}

int	special_case(t_data *d)
{
	char	**tmp;

	if ((!is_command(d->cmd1)) && is_command(d->cmd2))
		return (OK);
	else if ((!is_command(d->cmd2)) && is_command(d->cmd1))
	{
		if (!d->path2 && d->path1)
			d->path2 = ft_strdup(d->path1);
		tmp = d->c1;
		d->c1 = d->c2;
		d->c2 = tmp;
		return (OK);
	}
	else if (!is_command(d->cmd1) && !is_command(d->cmd2))
	{
		copy_case(d);
		return (OK);
	}
	return (FAIL);
}
