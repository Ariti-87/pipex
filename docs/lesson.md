<h1 id="title" align="center">
    PIPEX
</h1>

<h3 align="center">
    <a href="#malloc">Malloc()</a>
    <span> · </span>
    <a href="#free">Free()</a>
    <span> · </span>
    <a href="#write">Write()</a>
    <span> · </span>
    <a href="#read">Read()</a>
	<span> · </span>
    <a href="#open">Open()</a>
	<span> · </span>
    <a href="#close">Close()</a>
	<span> · </span>
    <a href="#access">Access()</a>
	<span> · </span>
    <a href="#dup">Dup() and Dup2()</a>
	<span> · </span>
    <a href="#exec">Execve()</a>
	<span> · </span>
    <a href="#exit">Exit()</a>
	<span> · </span>
    <a href="#fork">Fork()</a>
	<span> · </span>
    <a href="#wait">Wait() and Waitpid()</a>
	<span> · </span>
    <a href="#pipe">Pipe()</a>
	<span> · </span>
    <a href="#unlink">Unlink()</a>
	<span> · </span>
    <a href="#perror">Perror()</a>
	<span> · </span>
    <a href="#strerror">Strerror()</a>
</h3>

<div id="malloc">

# Malloc() function

The malloc() function in the C language is used for dynamic memory allocation. It allows you to allocate a specified number of bytes from the heap memory at runtime. The term "malloc" stands for "memory allocation."

The signature of the malloc() function is as follows:
```bash
#include <stdlib.h>

void *malloc(size_t size);
```
- `size` : this represents the number of bytes to allocate. It specifies the amount of memory you want to request from the operating system. The malloc() function returns a void pointer (void *) that points to the beginning of the allocated memory block.

It is important to check the return value of malloc() to ensure that the memory allocation was successful. If malloc() returns a NULL pointer, it indicates that the requested memory allocation failed. In such cases, you should handle the error appropriately. Also, it is essential to deallocate the memory block using the free() function when you no longer need it to avoid memory leaks.

<br>
<br>
<div id="free">

# Free() Function

The free() function in the C language is used to deallocate memory that was previously allocated dynamically using functions like malloc(), calloc(), or realloc().

The signature of the free() function is as follows:
```bash
#include <stdlib.h>

void free(void *ptr);
```

- `*ptr` : this is a pointer to the memory block that needs to be freed. It should correspond to a memory block previously allocated using malloc(), calloc(), or realloc(). If ptr is a NULL pointer, the free() function does nothing.

When you call the free() function, it releases the specified memory block so that it can be reused later. Once the memory is freed, you should no longer access its content as it would result in undefined behavior.

<br>
<br>
<div id="write">

# Write() Function

The write() function in the C language is used to write data to a file or a file descriptor. It is typically used to write data to standard output (stdout) or to a file that has been opened for writing.

The signature of the write() function is as follows:

```bash
#include <unistd.h>

ssize_t write(int fd, const void *buffer, size_t count);
```

The parameters of the write() function are:

- `fd` : It represents the file descriptor or the file handle to which the data will be written. For example, 1 represents standard output (stdout), and values greater than 2 represent file descriptors obtained using functions like open().
- `buffer` : It is a pointer to the buffer containing the data that will be written.
- `count` : It specifies the number of bytes to write from the buffer.

The write() function returns the number of bytes successfully written to the file or file descriptor. If the return value is -1, it indicates an error occurred during the write operation.

<br>
<br>
<div id="read">

# Read() Function

The read() function in the C language is used to read data from a file descriptor. It is typically used with files or sockets, but it can also be used with other types of input data streams.

The signature of the read() function is as follows:
```bash
#include <unistd.h>

ssize_t read(int fd, void *buffer, size_t count);
```

The parameters of the read() function are:

- `fd` : This is the file descriptor from which the data should be read. A file descriptor is an integer that identifies an open file or another type of input data stream. For example, 0 represents standard input (stdin), 1 represents standard output (stdout), and 2 represents standard error (stderr). File descriptors are typically obtained using functions like open() or socket().
- `buffer` : This is a pointer to the buffer where the read data will be stored.
- `count` : It specifies the maximum number of bytes to read from the file descriptor.

The read() function returns the number of bytes read from the file descriptor. If the returned value is -1, it indicates a read error.

<br>
<br>
<div id="open">

# Open() Function

The open() function in the C language is used to open a file and obtain a file descriptor, which is a unique identifier for an open file. It allows you to perform various operations on the file, such as reading, writing, or modifying its attributes.

The signature of the open() function is as follows:
```bash
#include <fcntl.h>

int open(const char *pathname, int flags, mode_t mode);
```

The parameters of the open() function are:

- `pathname` : It is a string that represents the path to the file you want to open.
- `flags` : It specifies the flags that control the opening and behavior of the file. Flags can include O_RDONLY (open for reading), O_WRONLY (open for writing), O_RDWR (open for reading and writing), O_CREAT (create the file if it doesn't exist), O_TRUNC (truncate the file if it exists), and more. Multiple flags can be combined using the bitwise OR operator (|).
- `mode` : It specifies the permissions to set on the file if O_CREAT flag is used. The mode is typically specified using constants defined in the <sys/stat.h> header, such as S_IRUSR (read permission for the owner), S_IWUSR (write permission for the owner), S_IRGRP (read permission for the group), and so on.

The open() function returns a file descriptor on success, which is a non-negative integer. If an error occurs, it returns -1, indicating the failure to open the file.

<br>
<br>
<div id="close">

# Close() Function

The close() function in the C language is used to close a file descriptor. It terminates the connection between the file descriptor and the corresponding open file, releasing any resources associated with it. After closing a file, further operations on that file descriptor are not possible unless the file is opened again.

The signature of the close() function is as follows:
```bash
#include <unistd.h>

int close(int fileDescriptor);
```

The parameter of the close() function is:

- `fileDescriptor` : It is an integer representing the file descriptor of the file to be closed.

The close() function returns 0 on success. If an error occurs while closing the file, it returns -1.

It is important to note that closing a file descriptor does not necessarily imply flushing any buffered data. Therefore, it's recommended to use functions like fsync() or fclose() (for standard library file streams) if you want to ensure that any buffered data is written to the file before closing it.

<br>
<br>
<div id="access">

# Access() Function

The access() function in the C language is used to check the accessibility or permission of a file or directory. It allows you to determine whether a specific file or directory can be accessed in a specified mode.

The signature of the access() function is as follows:

```bash
#include <unistd.h>

int access(const char *pathname, int mode);
```

The parameters of the access() function are:

- `pathname` : It is a string representing the path to the file or directory you want to check.
- `mode` : It specifies the accessibility mode, which can be F_OK to check the existence of the file, R_OK to check read permission, W_OK to check write permission, and X_OK to check execute permission. Multiple modes can be combined using the bitwise OR operator (|).

The access() function returns 0 if the file or directory exists and has the specified permissions according to the mode provided. If the file or directory doesn't exist or doesn't have the specified permissions, or if an error occurs, it returns -1.

Note that the access() function is useful for checking permissions before attempting to perform operations on a file or directory. However, keep in mind that the accessibility status can change between the access() call and subsequent operations, so it's important to handle potential errors or exceptions appropriately.

<br>
<br>
<div id="dup">

# Dup() and Dup2() Functions

The dup() function in C is used to duplicate an existing file descriptor. It creates a new file descriptor that refers to the same file or socket as the original descriptor. The new file descriptor is guaranteed to be the lowest available descriptor.

The signature of the dup() function is as follows:
```bash
#include <unistd.h>

int dup(int oldfd);
```

The dup() function takes the file descriptor oldfd as an argument and returns a new file descriptor on success. If an error occurs, it returns -1.

The dup2() function in C is similar to dup(), but it allows you to specify the desired file descriptor number for the duplicated descriptor. If the specified file descriptor number is already in use, dup2() will close it before duplicating the descriptor.

The signature of the dup2() function is as follows:
```bash
#include <unistd.h>

int dup2(int oldfd, int newfd);
```

The dup2() function takes two arguments: oldfd, the file descriptor to duplicate, and newfd, the desired file descriptor number for the duplicated descriptor. It returns the new file descriptor on success and -1 on failure.

It's important to note that both dup() and dup2() functions are primarily used for redirection of file descriptors, enabling output to be redirected to files or other destinations.

<br>
<br>
<div id="exec">

# Execve() Function

The execve() function in the C language is used to execute a program in place of the currently running process. It is part of the exec family of functions and allows you to replace the current process image with a new program.

The signature of the execve() function is as follows:

```bash
#include <unistd.h>

int execve(const char *pathname, char *const argv[], char *const envp[]);
```

The parameters of the execve() function are:

- `pathname` : It is a string that represents the path to the executable file you want to execute.
- `argv[]` : It is an array of strings that represents the program arguments. The last element of the array must be a NULL pointer.
- `envp[]` : It is an array of strings that represents the environment variables. The last element of the array must be a NULL pointer. If envp is set to NULL, the current environment is used.

The execve() function returns -1 on error, and on success, it does not return at all because the current process image is replaced by the new program.

It's important to note that the execve() function is a powerful tool for process execution, as it allows you to run other programs from within your program. However, it's crucial to handle errors appropriately and ensure that the necessary permissions and file paths are correctly set for the program you want to execute.

<br>
<br>
<div id="exit">

# Exit() Function

The exit() function in the C language is used to terminate the program and return control to the operating system. It allows you to explicitly exit the program at any point during its execution.

The signature of the exit() function is as follows:
```bash
#include <stdlib.h>

void exit(int status);
```

The parameter of the exit() function is:

- `status` : It is an integer value that represents the exit status of the program. A value of 0 typically indicates a successful execution, while a non-zero value indicates an error or abnormal termination.

The exit() function does not return to the calling function. It performs the following actions before terminating the program:

- Calls functions registered with the atexit() function, if any. These functions are typically used for performing cleanup tasks or freeing resources before the program exits.
- Closes open file descriptors, including standard input, standard output, and standard error.
- Flushes buffered output.
- Terminates the program and returns control to the operating system, along with the specified exit status.

The exit() function is commonly used to gracefully terminate a program and communicate its execution status to the calling environment or script. By convention, a value of 0 often represents successful execution, while non-zero values indicate various error conditions or abnormal terminations.

<br>
<br>
<div id="fork">

# Fork() Function

The fork() function in the C language is used to create a new process by duplicating the existing process. It creates a child process that is an exact copy of the parent process, including its code, data, and stack. After the fork() call, two separate processes, the parent process and the child process, are running concurrently.

The signature of the fork() function is as follows:

```bash
#include <unistd.h>

pid_t fork(void);
```

The fork() function does not take any arguments. It returns different values for the parent and child processes:

In the parent process, fork() returns the process ID (PID) of the child process.
In the child process, fork() returns 0.
If an error occurs during the fork() call, it returns -1.

When the program is executed, it will create a child process that starts executing from the point of the fork() call. Both the parent and child processes will continue executing from that point independently, but with separate memory spaces.

The fork() function is commonly used for process creation and parallel execution in C programs. It allows you to perform tasks concurrently and is the basis for many other process-related operations.

<br>
<br>
<div id="wait">

# Wait() and Waitpid() Functions

The wait() and waitpid() functions in the C language are used to wait for the termination of child processes in a parent process.

The wait() function suspends the execution of the calling process until one of its child processes terminates. It allows the parent process to wait for the completion of any child process without specifying a particular child process.
The signature of the wait() function is as follows:

```bash
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status);
```

The wait() function takes a pointer to an integer status as an argument, which is used to retrieve the termination status of the child process. If the status information is not needed, you can pass NULL.
The wait() function returns the process ID (PID) of the terminated child process, or -1 on error.

<br>

The waitpid() function is similar to wait(), but it allows more control over which child process to wait for. It allows the parent process to wait for the termination of a specific child process or a group of child processes.

The signature of the waitpid() function is as follows:

```bash
#include <sys/types.h>
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *status, int options);
```

The parameters of the waitpid() function are:

- `pid` : It specifies which child process to wait for. The value of pid can be:
	- -1 to wait for any child process.
	- 0 to wait for any child process in the same process group as the calling process.
	- A positive value representing the process ID of a specific child process to wait for.
- `status` : It is a pointer to an integer used to retrieve the termination status of the child process. If the status information is not needed, you can pass NULL.
- `options` : It specifies additional options for controlling the behavior of waitpid(). Common options include WNOHANG (returns immediately if no child has terminated) and WUNTRACED (returns if a child has stopped, but not terminated).

The waitpid() function returns the process ID (PID) of the terminated child process, 0 if using WNOHANG and no child has terminated, -1 on error, or a negative value to indicate a specific error condition.

<br>
<br>
<div id="pipe">

# Pipe() Function

The pipe() function in the C language is used to create an interprocess communication (IPC) channel between two related processes. It establishes a unidirectional pipe that allows one process to write data to the pipe, while the other process reads the data from it.

The signature of the pipe() function is as follows:

```bash
#include <unistd.h>

int pipe(int pipefd[2]);
```
The pipe() function takes an array pipefd as an argument, which will be populated with two file descriptors: pipefd[0] for reading from the pipe and pipefd[1] for writing to the pipe.

The pipe() function returns 0 on success and -1 on failure.

The pipe acts as a conduit for communication between the parent and child processes. The parent writes a message to the pipe, and the child reads the message from the pipe and prints it.

<br>
<br>
<div id="unlink">

# Unlink() Function

The unlink() function in the C language is used to delete or remove a file from the file system. It allows you to remove a file by specifying its filename or path.

The signature of the unlink() function is as follows:
```bash
#include <unistd.h>

int unlink(const char *pathname);
```

The unlink() function takes a pathname parameter, which is a string representing the path to the file that needs to be deleted.

The unlink() function returns 0 on success and -1 on failure.

It's important to note that the unlink() function permanently removes the file from the file system. Once a file is unlinked, it cannot be recovered, so **caution** should be exercised when using this function.

The unlink() function is commonly used in situations where you need to programmatically delete files in a C program, such as during file management or cleanup operations.

<br>
<br>
<div id="perror">

# Perror() Function

The perror() function in the C language is used to print a descriptive error message to the standard error stream (stderr). It takes a string argument that is typically a custom error message or a label associated with the error. The perror() function then appends a colon and space, followed by the corresponding error message based on the value of the global variable errno.

The signature of the perror() function is as follows:

```bash
#include <stdio.h>

void perror(const char *s);
```

The perror() function takes a const char* argument s, which is the custom error message or label to be printed. If s is not NULL, the error message will be preceded by s:.

The perror() function is a convenient way to display meaningful error messages along with system-specific error descriptions. It helps in diagnosing and debugging errors in C programs by providing more information about the cause of the error.

<br>
<br>
<div id="strerror">

# Strerror() Function

The strerror() function in the C language is used to obtain a human-readable error message corresponding to a given error number. It converts the value of the errno variable into a descriptive error string.

The signature of the strerror() function is as follows:

```bash
#include <string.h>

char *strerror(int errnum);
```

The strerror() function takes an integer argument errnum, which represents the error number for which the error message is to be obtained.

The strerror() function returns a pointer to a string containing the error message associated with the given error number. This string is typically a static string within the implementation, and it should not be modified.

The strerror() function is helpful in scenarios where you want to obtain a human-readable error message based on the error number. It allows you to provide more detailed error information to users or for diagnostic purposes.

En résumé, utilisez perror() lorsque vous souhaitez afficher immédiatement un message d'erreur avec le libellé personnalisé suivi du message d'erreur correspondant à errno. Utilisez strerror() lorsque vous avez besoin de la chaîne de caractères du message d'erreur pour un traitement ou une manipulation supplémentaire, comme l'enregistrement dans un fichier journal ou une personnalisation de l'affichage de l'erreur.

<br>
<br>
<a href="#title">Return ↑</a>
<br>
<br>
