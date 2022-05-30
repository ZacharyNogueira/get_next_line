/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:23:25 by znogueir          #+#    #+#             */
/*   Updated: 2022/05/19 19:13:59 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*buff_create(char *buffer, int bsize)
{
	char	*result;
	int		i;

	if (!buffer || !bsize)
		return (NULL);
	result = malloc(sizeof(char) * (bsize +1));
	if (!result)
		return (NULL);
	result[bsize] = '\0';
	i = 0;
	while (i < bsize)
	{
		result[i] = buffer[i];
		i++;
	}
	return (result);
}

/*char	*line_free(char *line, char *buff)
{
	char	*result;

	result = ft_strjoin(line, buff);
	free(line);
	return (result);
}*/

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*buff;
	char		*line;
	static char	*save;
	int			ret;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (save)
		line = save;
	save = NULL;
	ret = 1;
	while (ret && ft_strchr(line, '\n') == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buff = buff_create(buffer, ret);
		if (!buff)
			return (line);
		if (ret == -1)
		{
			//free(buff);
			//free(line);
			//free(save);
			return (NULL);
		}
		line = ft_strjoin(line, buff);
		free(buff);
	}
	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	save = ft_substr(line, i, ft_strlen(line + i));
	//printf("%s", save);
	while (line[i])
	{
		line[i] = '\0';
		i++;
	}
	return (line);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	f;
	char	*line;

	f = open("test2.txt", O_RDONLY);
	//printf("%d\n", f);
	line = get_next_line(f);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(f);
	}
	printf("%s", line);
	line = get_next_line(f);
	printf("%s", line);
	line = get_next_line(f);
	printf("%s", line);
	free(line);
	//get_next_line(1);
	return (0);
}*/