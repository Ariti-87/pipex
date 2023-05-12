/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:01:46 by arincon           #+#    #+#             */
/*   Updated: 2023/04/28 15:00:21 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_pipex_init(&data, envp);
	if (argc != 5)
		ft_error_msn("you need file1, cmd1, cmd2, file2 only\n", &data);
	data.file1 = open(argv[1], O_RDONLY);
	if (data.file1 == -1)
		ft_error_msn("File descriptor error, infile\n", &data);
	data.file2 = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 00777);
	if (data.file2 == -1)
		ft_error_msn("File descriptor error, outfile\n", &data);
	if (pipe(data.fd) == -1)
		ft_error_msn("An error occured with opening the pipe\n", &data);
	data.pid1 = fork();
	if (data.pid1 == -1)
		ft_error_msn("An error occured with the first fork\n", &data);
	if (data.pid1 == 0)
		ft_first_child(&data, argv, envp);
	data.pid2 = fork();
	if (data.pid2 == -1)
		ft_error_msn("An error occured with the second fork\n", &data);
	if (data.pid2 == 0)
		ft_second_child(&data, argv, envp);
	ft_close_and_free(&data);
	ft_waitpid(&data);
}
