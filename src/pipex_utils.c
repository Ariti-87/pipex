/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:04:48 by arincon           #+#    #+#             */
/*   Updated: 2023/04/21 19:03:28 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_msn(char *str)
{
	write (2, str, ft_strlen(str));
	exit (EXIT_FAILURE);
}

char	*ft_pipex_path(char **envp)
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


void	ft_pipex_cmd()
{

}
