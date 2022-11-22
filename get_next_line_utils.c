/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:39:25 by gcherqui          #+#    #+#             */
/*   Updated: 2022/11/22 09:46:20 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	t_vrb	bob;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s1 && s2)
	{
		bob.size = ft_strlen(s1) + ft_strlen(s2);
		bob.tab = malloc(sizeof(char) * bob.size + 1);
		bob.i = -1;
		bob.j = 0;
		if (!bob.tab)
			return (NULL);
		while (s1[++bob.i])
			bob.tab[bob.i] = s1[bob.i];
		while (s2[bob.j])
			bob.tab[bob.i++] = s2[bob.j++];
		bob.tab[bob.i] = 0;
		free(s1);
		return (bob.tab);
	}
	free(s1);
	return (NULL);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}
