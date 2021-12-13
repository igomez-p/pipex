/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:37:21 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/13 14:19:21 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

# define OK     1
# define FAIL   0

typedef struct  s_data {
	char        *file1;
	char        *file2;
	char        *cmd1;
	char        *cmd2;
}               t_data;

void	clean_exit(t_data *d, int error);
void	read_stack(t_data *d, int argc, char **argv);

#endif