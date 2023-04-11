/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:01:46 by arincon           #+#    #+#             */
/*   Updated: 2023/04/11 18:23:50 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipe	pipe;

	if (argc != 5)
		ft_error_msn("you need file1, cmd1, cmd2, file2 only");
	pipe.file1 = open(argv[1], O_RDONLY);
	pipe.file2 = open(argv[4], O_RDONLY);
	return (0);
}

/*
int pipe(int pipefd[2]);

int dup(int oldfd);
int dup2(int oldfd, int newfd);
dup() et dup2() créent une copie du descripteur de fichier oldfd.
dup() utilise le plus petit numéro inutilisé pour le nouveau descripteur.
dup2() transforme newfd en une copie de oldfd, fermant auparavant newfd si besoin est,

fork();

*/
