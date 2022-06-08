#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct info
{
    int fd[2];
    char *infile;
    char *outfile;
    int infd;
    int outfd;
    char **cmd1;
    char **cmd2;
    char *pathcmd1;
    char *pathcmd2;
    char **path;
} t_data;

char	*ft_strdup(char *s1);
char	**ft_split(const char *s, char c);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
void	*freee(char **p);
char	*ft_strjoin(char *s1, char *s2);

#endif