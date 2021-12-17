/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:37:21 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/16 20:34:38 by igomez-p         ###   ########.fr       */
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

# define OK     1
# define FAIL   0
# define PATH	"PATH"

typedef struct s_data {
	char		*file1;
	char		*file2;
	char		*path1;
	char		*path2;
	char		*cmd1;
	char		*cmd2;
	char		**c1;
	char		**c2;
}				t_data;

void	init_struct(t_data *d);
int		check_files(t_data *d, char *file1, char *file2);
void	check_command(t_data *d, char *cmd1, char *cmd2, char **paths);
void	clean_exit(t_data *d, int error);
void	read_stack(t_data *d, int argc, char **argv, char **envp);
void	pipex_process(t_data *d, char **envp);
void	free_double(char **str);

char	*ft_strnstr(const char *haystack, const char *needle, size_t l);
char	**ft_split(char const *s1, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
