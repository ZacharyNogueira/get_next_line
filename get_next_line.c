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

/*char	*read_line(int fd, char *buffer)
{
}*/

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*save;
	int			i;

	line = NULL;
	if (save)
		line = save;
	int ret = 1;
	while (ret && ft_strchr(line, '\n') == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		line = ft_strjoin(line, buffer);
	}
	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	save = ft_substr(line, i, ft_strlen(line + i));
	printf("((%s))", save);
	line[i] = '\0';
	return (line);
}

int	main(int ac, char **av)
{
	(void)ac;
	//(void)av;
	int	f;
	char	*line;

	f = open("test.txt", O_RDONLY);
	//printf("%d\n", f);
	line = get_next_line(f);
	printf("%s", line);
	line = get_next_line(f);
	printf("%s", line);
	line = get_next_line(f);
	printf("%s", line);
	line = get_next_line(f);
	printf("%s", line);
	free(line);
	//get_next_line(1);
	return (0);
}