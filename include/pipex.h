/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:59:07 by arincon           #+#    #+#             */
/*   Updated: 2023/04/28 15:10:46 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		file1;
	int		file2;
	int		fd[2];
	char	*path;
	char	**paths;
	char	*cmd1;
	char	*cmd2;
	char	**cmds1;
	char	**cmds2;
	pid_t	pid1;
	pid_t	pid2;
}			t_data;

// Utils
void	ft_error_msn(char *str, t_data *data);
char	*ft_env_path(char **envp);
char	*ft_find_cmd(char **paths, char *cmd);
void	ft_free_tab(char **tab);
void	ft_close_and_free(t_data *data);

// Utils2
void	ft_pipex_init(t_data *data, char **envp);
void	ft_first_child(t_data *data, char **argv, char **envp);
void	ft_second_child(t_data *data, char **argv, char **envp);
void	ft_waitpid(t_data *data);

#endif
