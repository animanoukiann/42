/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:33:23 by anmanuky          #+#    #+#             */
/*   Updated: 2023/11/22 14:55:15 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/syscall.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd;
	char	*cmd_path;
	char	**valid_paths;
	int		pipefd[2];
}		t_pipex;

void	error(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char a, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	free_c(t_pipex *var);
void	free_p(t_pipex *var);
void	last(t_pipex *var);
int		empty_cmd(int argc, char **argv);

#endif
