# pipex
This project made me discover in detail a UNIX mechanism that i already know
by using it in my program.

The program named "pipex" handles pipes and is required to be implemented with the following files: Makefile, *.h, and *.c. The Makefile should include rules for "NAME," "all," "clean," "fclean," and "re" targets.

The program takes four arguments: file1, cmd1, cmd2, and file2. It utilizes various external functions, such as open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, and waitpid. Additionally, it requires a function similar to ft_printf.

The use of the Libft library is authorized. The program is executed as follows: "./pipex file1 cmd1 cmd2 file2". It aims to replicate the functionality of the shell command: "< file1 cmd1 | cmd2 > file2".

The document provides examples of the expected behavior and requirements for the project. A Makefile should be included, ensuring the compilation of source files without relinking. Error handling must be thorough to prevent unexpected program termination, segmentation faults, bus errors, double frees, etc. The program should not have memory leaks. Any doubts should be resolved by following the error handling approach of the shell command: "< file1 cmd1 | cmd2 > file2".
