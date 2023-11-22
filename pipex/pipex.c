/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:33:17 by anmanuky          #+#    #+#             */
/*   Updated: 2023/11/22 15:20:35 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(char **valid_path, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	if (cmd[0] != '/')
	{
		while (valid_path[i])
		{
			path = ft_strjoin(valid_path[i], '/', cmd);
			if (access(path, X_OK) == 0)
				return (path);
			free(path);
			i++;
		}
	}
	else
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
	}
	return (NULL);
}

char	**find_valid_paths(char **envp)
{
	int		i;
	char	**path;
	char	**env;

	i = 0;
	path = NULL;
	env = envp;
	while (env[i] != NULL)
	{
		if (strncmp("PATH=", env[i], 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (path);
}

void	child1(t_pipex *var, char **argv, char **envp)
{
	var->cmd = ft_split(argv[2], ' ');
	var->cmd_path = find_cmd_path(var->valid_paths, var->cmd[0]);
	if (!var->cmd_path)
		free_c(var);
	if (close(var->pipefd[0]) < 0)
		error("SYSTEM CALL FAILED");
	if (dup2(var->infile, STDIN_FILENO) < 0)
		error("SYSTEM CALL FAILED");
	if (dup2(var->pipefd[1], STDOUT_FILENO) < 0)
		error("SYSTEM CALL FAILED");
	if (close(var->pipefd[1]) < 0)
		error("SYSTEM CALL FAILED");
	execve(var->cmd_path, var->cmd, envp);
}

void	child2(t_pipex *var, char **argv, char **envp)
{
	var->cmd = ft_split(argv[3], ' ');
	var->cmd_path = find_cmd_path(var->valid_paths, var->cmd[0]);
	if (!var->cmd_path)
		free_c(var);
	if (close(var->pipefd[1]) < 0)
		error("SYSTEM CALL FAILED");
	if (dup2(var->pipefd[0], STDIN_FILENO) < 0)
		error("SYSTEM CALL FAILED");
	if (dup2(var->outfile, STDOUT_FILENO) < 0)
		error("SYSTEM CALL FAILED");
	if (close(var->pipefd[0]) < 0)
		error("SYSTEM CALL FAILED");
	execve(var->cmd_path, var->cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	var;

	if (empty_cmd(argc, argv) != 0)
		error("UNKNOWN ERROR");
	var.infile = open(argv[1], O_RDONLY);
	var.outfile = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (var.outfile < 0 || var.infile < 0)
		error("SOMETHING WRONG WITH FILES");
	var.valid_paths = find_valid_paths(envp);
	if (pipe(var.pipefd) < 0)
		error("SYSTEM CALL FAILED");
	var.pid1 = fork();
	if (var.pid1 == -1)
		error("SYSTEM CALL FAILED");
	else if (var.pid1 == 0)
		child1(&var, argv, envp);
	var.pid2 = fork();
	if (var.pid2 == -1)
		error("SYSTEM CALL FAILED");
	else if (var.pid2 == 0)
		child2(&var, argv, envp);
	last(&var);
	waitpid(var.pid1, NULL, 0);
	waitpid(var.pid2, NULL, 0);
	return (0);
}
