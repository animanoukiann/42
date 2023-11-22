/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:32:19 by anmanuky          #+#    #+#             */
/*   Updated: 2023/11/22 15:08:39 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_c(t_pipex *var)
{
	int	i;

	i = 0;
	if (close(var->infile) < 0 || close(var->outfile) < 0)
		error("SYSTEM CALL FAILED");
	free(var->cmd_path);
	while (var->cmd[i])
	{
		free(var->cmd[i]);
		i++;
	}
	free(var->cmd);
	exit (1);
}

void	free_p(t_pipex *var)
{
	int	i;

	i = 0;
	if (close(var->infile) < 0 || close(var->outfile) < 0)
		error("SYSTEM CALL FAILED");
	while (var->valid_paths[i])
	{
		free(var->valid_paths[i]);
		i++;
	}
	free(var->valid_paths);
	return ;
}

void	last(t_pipex *var)
{
	if (close(var->pipefd[0]) || close(var->pipefd[1]))
		error("SYSTEM CALL FAILED");
	free_p(var);
	return ;
}

int	empty_cmd(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5)
		error("INVALID ARGUMENTS");
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
		error("EMPTY COMMAND");
	while (argv[2][i] == ' ')
		i++;
	if (argv[2][i] == '\0')
		error("EMPTY COMMAND");
	i = 0;
	while (argv[3][i] == ' ')
		i++;
	if (argv[3][i] == '\0')
		error("EMPTY COMMAND");
	return (0);
}
