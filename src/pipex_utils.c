/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:04:48 by arincon           #+#    #+#             */
/*   Updated: 2023/05/04 19:11:13 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_msn(char *str, t_data *data)
{
	write (2, str, ft_strlen(str));
	ft_close_and_free(data);
	exit (EXIT_FAILURE);
}

// Copy PATH string without "PATH="
char	*ft_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

// Look for Cmd in all paths
char	*ft_find_cmd(char **paths, char *cmd)
{
	int		i;
	char	*find_cmd;
	char	*v_cmd;

	i = 0;
	v_cmd = ft_strjoin_gnl("/", cmd);
	while (paths[i])
	{
		find_cmd = ft_strjoin_gnl(paths[i], v_cmd);
		if (access(find_cmd, 0) == 0)
			return (free(v_cmd), find_cmd);
		free(find_cmd);
		i++;
	}
	free(v_cmd);
	return (NULL);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_close_and_free(t_data *data)
{
	if (data->fd[0])
		close(data->fd[0]);
	if (data->fd[1])
		close(data->fd[1]);
	if (data->file1)
		close(data->file1);
	if (data->file2)
		close(data->file2);
	if (data->paths)
		ft_free_tab(data->paths);
}
