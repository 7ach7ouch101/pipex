/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:07:23 by mmeziani          #+#    #+#             */
/*   Updated: 2022/06/18 22:38:39 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execu_second_cmd(t_data *data, char **envp)
{
	data->pathcmd1 = find_cmd_path(data, *data->cmd2);
	if (data->pathcmd1 == NULL)
	{
		write(1, "SECOND COMMAND NOT FOUND", 24);
		exit(0);
	}
	dup2(data->fd[0], 0);
	dup2(data->fd2, 1);
	close(data->fd[1]);
	close(data->fd2);
	if (execve(data->pathcmd1, data->cmd2, envp) == -1)
	{
		write(2, "EXECVE ERROR", 12);
		exit(0);
	}
}

void	execu_fisrt_cmd(t_data *data, char **envp)
{
	data->pathcmd1 = find_cmd_path(data, *data->cmd1);
	if (data->pathcmd1 == NULL)
	{
		write(1, "FIRST COMMAND NOT FOUND", 23);
		exit(0);
	}
	dup2(data->fd1, 0);
	dup2(data->fd[1], 1);
	close(data->fd1);
	close(data->fd[0]);
	if (execve(data->pathcmd1, data->cmd1, envp) == -1)
	{
		write(2, "EXECVE ERROR", 12);
		exit(0);
	}
}

char	execu(t_data *data, char **envp)
{
	int	child;

	if (pipe(data->fd) == -1)
		return (write(1, "PIPE ERROR", 10));
	child = fork();
	if (child == -1)
		return (write(1, "FORK ERROR", 10));
	else if (child == 0)
		execu_fisrt_cmd(data, envp);
	else
	{
		if (waitpid(child, NULL, 0) == child)
			execu_second_cmd(data, envp);
	}
	return (write(1, "OK", 2));
}

void	parsedata(t_data *data, char **argv, char **envp)
{
	char	*tmp;
	char	*pathenv;

	data->infile = ft_strdup(argv[1]);
	tmp = ft_strdup(argv[2]);
	data->cmd1 = ft_split(tmp, ' ');
	free(tmp);
	tmp = ft_strdup(argv[3]);
	data->cmd2 = ft_split(tmp, ' ');
	data->outfile = ft_strdup(argv[4]);
	free(tmp);
	pathenv = find_path(envp);
	if (pathenv == NULL)
	{
		write(1, "ENVP ERROR", 10);
		exit(0);
	}
	data->path = ft_split(pathenv, ':');
	free(pathenv);
}

int	main(int ac, char **argv, char **envp)
{
	t_data	data;

	if (ac == 5)
	{
		parsedata(&data, argv, envp);
		data.fd1 = open(data.infile, O_RDWR);
		if (data.fd1 < 0)
			return (write(1, "FILE1 DOESN'T EXIST", 19));
		data.fd2 = open(data.outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data.fd2 < 0)
			return (write(1, "FILE2 DOESN'T EXIST", 19));
		execu(&data, envp);
	}
	else
		write(1, "ARGUMENTS AREN'T RIGHT", 22);
	return (0);
}
