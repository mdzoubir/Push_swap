/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:46:04 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/13 16:29:43 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

static char	*quit(char *line)
{
	if (line)
		free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buf[2];
	int		ret;

	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	buf[1] = '\0';
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, 1);
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (buf[0] == '\n')
			break ;
	}
	if (ret == -1 || *line == '\0')
		return (quit(line));
	return (line);
}
