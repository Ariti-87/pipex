/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:59:07 by arincon           #+#    #+#             */
/*   Updated: 2023/04/11 16:13:40 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipe
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
}			t_pipe;

// Utils
void	ft_error_msn(char *str);

//

#endif
