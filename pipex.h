/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:37:21 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/24 11:27:14 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

# define OK2	2
# define OK     1
# define FAIL   0
# define PATH	"PATH"
# define CMD1	1
# define CMD2	0

typedef struct s_data {
	char		*file1;
	char		*file2;
	char		*path1;
	char		*path2;
	char		*cmd1;
	char		*cmd2;
	char		**c1;
	char		**c2;
	int			relative;
}				t_data;

void	init_struct(t_data *d);
int		check_files(t_data *d, char *file1, char *file2);
void	check_command(t_data *d, char **cmd1, char **cmd2, char **paths);
void	clean_exit(t_data *d, int error);
void	read_stack(t_data *d, char **argv, char **envp);
void	pipex_process(t_data *d, char **envp);
void	free_double(char **str);
int		special_case(t_data *d, char **argv);
void	simple_process(t_data *d, char **envp);

char	*ft_strnstr(const char *haystack, const char *needle, size_t l);
char	**ft_split(char const *s1, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
