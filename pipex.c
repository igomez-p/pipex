/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:37:24 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/14 19:19:40 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;

	init_struct(&data);
	read_stack(&data, argc, argv, envp);
	printf("FILE 1: %s\n", data.file1);
	printf("FILE 2: %s\n", data.file2);
	printf("PATH 1: %s\n", data.path1);
	printf("PATH 2: %s\n", data.path2);
	printf("COMMAND 1: %s\n", data.cmd1);
	printf("COMMAND 2: %s\n", data.cmd2);
	return (0);
}
