/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:37:24 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/15 17:02:44 by igomez-p         ###   ########.fr       */
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
	pipex_process(&data, envp);
	return (0);
}
