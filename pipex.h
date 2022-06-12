/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:17:38 by mmeziani          #+#    #+#             */
/*   Updated: 2022/06/12 12:17:39 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct info
{
	int		fd[2];
	char	*infile;
	char	*outfile;
	int		fd1;
	int		fd2;
	char	**cmd1;
	char	**cmd2;
	char	*pathcmd1;
	char	*pathcmd2;
	char	**path;
}	t_data;

char	*ft_strdup(char *s1);
char	**ft_split(const char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*freee(char **p);
char	*ft_strjoin(char *s1, char *s2);
char	*find_cmd_path(t_data *data, char *cmd);
char	*find_path(char **envp);

#endif
