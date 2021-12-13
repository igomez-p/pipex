/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:37:24 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/13 14:20:53 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char *argv[])
{
	t_data data;

	read_stack(&data, argc, argv);
	printf("FILE 1: %s\n", data.file1);
	printf("FILE 2: %s\n", data.file2);
	printf("COMMAND 1: %s\n", data.cmd1);
	printf("COMMAND 2: %s\n", data.cmd2);
	return (0);
}