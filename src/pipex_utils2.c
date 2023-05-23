/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:50:45 by arincon           #+#    #+#             */
/*   Updated: 2023/05/23 18:14:14 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Initialize structure variables
// Put all paths in data->path (*str format)
// Put all paths in data->paths (**tab format)
void	ft_pipex_init(t_data *data, char **envp)
{
	data->paths = 0;
	data->file1 = 0;
	data->file2 = 0;
	data->fd[0] = 0;
	data->fd[1] = 0;
	data->path = ft_env_path(envp);
	if (data->path == 0)
		ft_error_msn ("Path not find in env\n", data);
	data->paths = ft_split(data->path, ':');
}

// With ft_find_cmd, find the first cmd in ./bin
// dup fd and close, and exec if cmd was found
void	ft_first_child(t_data *data, char **argv, char **envp)
{
	close(data->fd[0]);
	dup2(data->file1, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	data->cmds1 = ft_split(argv[2], ' ');
	data->cmd1 = ft_find_cmd(data->paths, data->cmds1[0]);
	if (data->cmd1 == NULL)
	{
		ft_free_tab(data->cmds1);
		ft_error_msn("Command doesn't exist\n", data);
	}
	execve(data->cmd1, data->cmds1, envp);
}

// With ft_find_cmd, find the second cmd in ./bin
// dup fd and close, and exec if cmd was found
void	ft_second_child(t_data *data, char **argv, char **envp)
{
	close(data->fd[1]);
	dup2(data->file2, STDOUT_FILENO);
	dup2(data->fd[0], STDIN_FILENO);
	data->cmds2 = ft_split(argv[3], ' ');
	data->cmd2 = ft_find_cmd(data->paths, data->cmds2[0]);
	if (data->cmd2 == NULL)
	{
		ft_free_tab(data->cmds2);
		ft_error_msn("Command doesn't exist\n", data);
	}
	execve(data->cmd2, data->cmds2, envp);
}

void	ft_waitpid(t_data *data)
{
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
}
