/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:55:02 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/13 17:42:09 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdlib.h>

static int	cont_char(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	if (s[0] && s[0] != c)
		cont++;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			cont++;
		i++;
	}
	return (cont);
}

static char	*ft_word(char const *s, char c, int i)
{
	int		p;
	int		k;
	char	*w;

	p = i;
	while (s[i] && s[i] != c)
		i++;
	w = (char *)malloc(sizeof(char) * ((i - p) + 1));
	if (!w)
		return (NULL);
	k = 0;
	while (p != i)
	{
		w[k] = s[p];
		k++;
		p++;
	}
	w[k] = '\0';
	return (w);
}

char	**ft_split(char const *s1, char c)
{
	int		i[2];
	char	*aux;
	char	**num;

	num = (char **)malloc(sizeof(char *) * (cont_char(s1, c) + 1));
	if (!num || !s1)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (i[0] <= (int)ft_strlen(s1) && cont_char(s1, c))
	{
		aux = ft_word(s1, c, i[0]);
		if (ft_strlen(aux))
		{
			num[i[1]] = ft_strdup(aux);
			i[0] += (ft_strlen(num[i[1]]) + 1);
			i[1]++;
		}
		else
			i[0]++;
		free(aux);
		aux = NULL;
	}
	num[i[1]] = NULL;
	return (num);
}
