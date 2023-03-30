/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:08:03 by anmanuky          #+#    #+#             */
/*   Updated: 2023/03/22 19:42:07 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	checker(char **line)
{
	char	*for_free;

	if (ft_strlen(*line) == 0)
	{
		for_free = *line;
		*line = NULL;
		free(for_free);
	}
}

char	*helper(char **line)
{
	int		char_place;
	char	*ret_val;
	char	*for_free;

	char_place = find_nl(*line);
	if (char_place == -1)
	{
		ret_val = *line;
		*line = NULL;
		return (ret_val);
	}
	ret_val = ft_substr(*line, 0, (char_place + 1));
	for_free = *line;
	*line = ft_substr(*line, (char_place + 1),
			(ft_strlen(*line) - char_place - 1));
	free(for_free);
	return (ret_val);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			end;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	end = -1;
	while (++end < BUFFER_SIZE + 1)
		buffer[end] = '\0';
	while (find_nl(buffer) == -1)
	{
		end = read (fd, buffer, BUFFER_SIZE);
		if (end == 0)
			break ;
		buffer[end] = '\0';
		if (!line[fd])
			line[fd] = ft_substr(buffer, 0, ft_strlen(buffer));
		else
			line[fd] = ft_strjoin(line[fd], buffer);
	}
	if (end != 0 || ft_strlen(line[fd]) != 0)
		return (helper(&line[fd]));
	checker(&line[fd]);
	return (line[fd]);
}
