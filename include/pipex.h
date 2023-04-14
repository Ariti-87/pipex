/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:59:07 by arincon           #+#    #+#             */
/*   Updated: 2023/04/14 18:07:42 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

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
	char	*cmd1;
	char	*cmd2;
}			t_data;

// Utils
void	ft_error_msn(char *str);

//

#endif
