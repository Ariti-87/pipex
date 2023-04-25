/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:01:46 by arincon           #+#    #+#             */
/*   Updated: 2023/04/24 19:24:02 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_pipex_init(&data, envp);
	if (argc != 5)
		ft_error_msn("you need file1, cmd1, cmd2, file2 only\n", &data);
	data.file1 = open(argv[1], O_RDWR);
	if (data.file1 == -1)
		ft_error_msn("File descriptor error, infile\n", &data);
	data.file2 = open(argv[4], O_RDWR);
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

/*
int	i;
i = 0;
while (envp[i])
{
	printf("%s\n", envp[i]);
	i++;
}

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

int access(const char *pathname, int mode)
access() checks whether the calling process can access the file pathname.
If pathname is a symbolic link, it is dereferenced.

int execve(const char *pathname, char *const argv[], char *const envp[]);
execv() executes the program referred to by pathname.This causes the program that is currently being run
by the calling process to be replaced with a new program, with newly initialized stack, heap,
and (initialized and uninitialized) data segments.
execl (ist) or execv (vector) and p (path) / e (environment) are options
*/
