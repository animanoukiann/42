/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:08:03 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/18 18:58:16 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	checker(char **line)
{
	char	*for_free;

	if (ft_strlen_gnl(*line) == 0)
	{
		for_free = *line;
		*line = NULL;
		free(for_free);
	}
}

char	*helper_gnl(char **line)
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
			(ft_strlen_gnl(*line) - char_place - 1));
	free(for_free);
	return (ret_val);
}

char	*get_next_line(int fd)
{
	static char	*line;
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
		if (!line)
			line = ft_substr(buffer, 0, ft_strlen_gnl(buffer));
		else
			line = ft_strjoin(line, buffer);
	}
	if (end != 0 || ft_strlen_gnl(line) != 0)
		return (helper_gnl(&line));
	checker(&line);
	return (line);
}
