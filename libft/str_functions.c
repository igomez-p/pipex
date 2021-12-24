/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:55:26 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/24 07:58:59 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		p;
	int		p2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	p = 0;
	while (s1[p])
	{
		s[p] = s1[p];
		p++;
	}
	p2 = 0;
	while (s2[p2])
	{
		s[p] = s2[p2];
		p++;
		p2++;
	}
	s[p] = '\0';
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (s1[pos] && s2[pos] && s1[pos] == s2[pos] && pos < n)
		pos++;
	if (s1[pos] != s2[pos] && pos < n)
		return (((unsigned char)s1[pos] - (unsigned char)s2[pos]));
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	size_t	len_ned;
	size_t	k;

	k = 0;
	len_ned = ft_strlen(needle);
	if (ft_strlen(haystack) < len_ned)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	while ((k + len_ned) <= l && *haystack)
	{
		if (ft_strncmp(haystack, needle, len_ned) == 0)
			return ((char *)haystack);
		haystack++;
		k++;
	}
	return (NULL);
}
