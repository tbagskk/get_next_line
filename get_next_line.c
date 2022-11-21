/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:40:02 by gcherqui          #+#    #+#             */
/*   Updated: 2022/11/20 15:40:03 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_notfishished(int fd, char *tab)
{
	char	*buff;
	int		var;

	var = 1;
	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(tab, '\n') && var != 0)
	{
		var = read(fd, buff, BUFFER_SIZE);
		if (var == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[var] = 0;
		tab = ft_strjoin(tab, buff);
	}
	free(buff);
	return (tab);
}

char	*ft_newline(char *str)
{
	char	*tab;
	int		i;

	if (!str)
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tab[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
char	*ft_tofill(char *str)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tab = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!tab)
		return (NULL);
	i++;
	while (str[i])
		tab[j++] = str[i++];
	tab[j] = '\0';
	free(str);
	return (tab);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = ft_notfishished(fd, tmp);
	//printf("%s",tmp);
	if (!stat)
		return (NULL);
//tmp = ft_newline(stat);
	//stat = ft_tofill(stat);
	return (tmp);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error");
		return (1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
