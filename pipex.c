/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:37:24 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/24 11:39:06 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;

	init_struct(&data);
	if (argc != 5)
		clean_exit(&data, FAIL);
	read_stack(&data, argv, envp);
	if (special_case(&data, argv))
		simple_process(&data, envp);
	else
		pipex_process(&data, envp);
	clean_exit(&data, OK);
	return (0);
}
