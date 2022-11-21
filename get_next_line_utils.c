/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:39:25 by gcherqui          #+#    #+#             */
/*   Updated: 2022/11/20 15:39:26 by gcherqui         ###   ########.fr       */
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
	size_t	size;
	char	*tab;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
	size = ft_strlen(s1) + ft_strlen(s2);
	tab = malloc(sizeof(char) * size + 1);
	i = -1;
	j = 0;
		if (!tab)
			return (NULL);
		while (s1[++i])
		tab[i] = s1[i];
		while (s2[j])
		{
		tab[i] = s2[j];
		i++;
		j++;
		}
	tab[i] = 0;
		return (tab);
	}
	free(s1);
	free(s2);
	return (NULL);
}

/*
char	*ft_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!line)
	{
		line = malloc(sizeof(char));
		line[0] = '\0';
	}
	if (!buff || !line)
		return (NULL);
	res = malloc((ft_strlen(line) + ft_strlen(buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (line[j])
		res[i++] = line[j++];
	j = 0;
	while (buff[j])
		res[i++] = buff[j++];
	res[i] = '\0';
	free(line);
	return (res);
}
*/
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}