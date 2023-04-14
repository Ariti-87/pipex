/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:01:46 by arincon           #+#    #+#             */
/*   Updated: 2023/04/14 18:40:09 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv/*, char **envp */)
{
	t_data	data;
	pid_t	pid1;
	pid_t	pid2;
	/* int		i; */

	if (argc != 5)
		ft_error_msn("you need file1, cmd1, cmd2, file2 only\n");
	data.file1 = open(argv[1], O_RDWR);
	if (data.file1 < 0)
		ft_error_msn("File descriptor error, infile\n");
	data.file2 = open(argv[4], O_RDWR);
	if (data.file2 < 0)
		ft_error_msn("File descriptor error, outfile\n");
	if (pipe(data.fd) == -1)
		ft_error_msn("An error occured with opening the pipe\n");
	pid1 = fork();
	if (pid1 == -1)
		ft_error_msn("An error occured with the first fork\n");
	if (pid1 == 0)
	{
		dup2(data.fd[1], STDOUT_FILENO);
		close(data.fd[0]);
		dup2(data.file1, STDIN_FILENO);
	}
	pid2 = fork();
	if (pid2 == -1)
		ft_error_msn("An error occured with the second fork\n");
	if (pid2 == 0)
	{
		dup2(data.fd[0], STDIN_FILENO);
		close(data.fd[1]);
		dup2(data.file2, STDOUT_FILENO);
	}

	close(data.fd[0]);
	close(data.fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	/* i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	} */
	return (0);
}



/*
int pipe(int pipefd[2]);

int dup(int oldfd);
int dup2(int oldfd, int newfd);
dup() et dup2() creates a copy of a file descriptor (oldfd)
dup() utilise le plus petit numéro inutilisé pour le nouveau descripteur.
dup2() transforme newfd en une copie de oldfd, fermant auparavant newfd si besoin est,

fork() is used for creating a new process, which is called child process

pid_t wait(int *wstatus);
wait() suspends execution of the calling thread until one of its children terminates.

pid_t waitpid(pid_t pid, int *wstatus, int options);
waitpid() suspends execution of the calling thread until a child specified by pid argument has changed state.

int unlink(const char *path);
unlink() You can delete a file with unlink or remove.

int execv( const char *path, char *const argv[]);
execv() function executes a process from another process or program. This function executes the file
or executable which is specified in the *path argument.
*/
