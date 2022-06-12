/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:07:29 by mmeziani          #+#    #+#             */
/*   Updated: 2022/06/12 12:07:30 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*tmp;
	char	*cmd_path;
	int		i;

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
