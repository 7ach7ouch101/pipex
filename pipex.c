#include "pipex.h"

char	*find_path(char **envp)
{
	char	**path;
	char	*ret;
	int		i;

	i = 0;
	while (envp[i])
	{
		path = ft_split(envp[i], '=');
		if (!ft_strncmp("PATH", path[0], 5))
		{
			ret = ft_strdup(path[1]);
			freee(path);
			return (ret);
		}
		i++;
		freee(path);
	}
	return (NULL);
}
char	*find_cmd_path(t_data *data, char *cmd)
{
	int i;
	char *tmp;
	char *cmd_path;

	i = 0;
	while (data->path[i])
	{
		tmp = ft_strjoin(data->path[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		if (!(access(cmd_path, X_OK)))
		{
			free(tmp);
			return (cmd_path);
		}
		free(tmp);
		free(cmd_path);
		i++;
	}
	return (NULL);
}
void	execu_second_cmd(t_data *data, char **envp)
{
	data->pathcmd1 = find_cmd_path(data, *data->cmd2);
	if(data->pathcmd1 == NULL)
		return ;
	
	
	
	
	execve(data->pathcmd1, data->cmd2, envp);
	
}

void	execu_fisrt_cmd(t_data *data, char **envp)
{
	data->pathcmd1 = find_cmd_path(data, *data->cmd1);
	if(data->pathcmd1 == NULL)
		return ;
	
	
	
	
	execve(data->pathcmd1, data->cmd1, envp);
}

char		execu(t_data *data, char **envp)
{
	int child;

	if(pipe(data->fd) == -1)
		 return (printf("pipe error"));
	child = fork();
	if(child == -1)
		return (printf("FORK ERROR"));
	else if(child == 0)
	{
		execu_fisrt_cmd(data, envp);
	}
	else
	{
		waitpid(child, NULL, 0);
		execu_second_cmd(data, envp);
	}
	return (printf("OK"));
}
int parsedata(t_data *data, char **argv, char **envp)
{
	char *tmp;
	char *pathenv;

    data->outfile = ft_strdup(argv[1]);
	tmp = ft_strdup(argv[2]);
	data->cmd1 = ft_split(tmp, ' ');
	free(tmp);
	tmp = ft_strdup(argv[3]);
	data->cmd2 = ft_split(tmp, ' ');
	data->infile = ft_strdup(argv[4]);
	free(tmp);
	pathenv = find_path(envp);
	if(pathenv == NULL)
		return (0);
	data->path = ft_split(pathenv, ':');
	free(pathenv);
	return (1);
}

int main(int ac, char **argv, char **envp)
{
    t_data data;

    if(ac == 5)
    {
        if(!parsedata(&data, argv, envp))
            return (printf("error"));
		execu(&data, envp);
    }
    else
        printf("error");
    return (0);
}