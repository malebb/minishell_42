/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:57:07 by mlebrun           #+#    #+#             */
/*   Updated: 2021/03/08 17:08:01 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "ft.h"

static int	find_path_id(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	*create_path(char *sub_path, char *cmd)
{
	int		size_cmd;
	int		size_sub_path;
	char	*path;
	int		slash_ended;

	size_sub_path = ft_strlen(sub_path);
	size_cmd = ft_strlen(cmd);
	slash_ended = 1;
	if (sub_path[size_sub_path - 1] == '/')
		slash_ended = 0;
	path = malloc(sizeof(char) * (size_sub_path + size_cmd + slash_ended + 1));
	if (!path)
		return (NULL);
	ft_strcpy(path, sub_path);
	if (slash_ended)
		ft_strcat(path, "/");
	ft_strcat(path, cmd);
	return (path);
}

static int	try_path(char *sub_path, char **argv, char **envp, char *cmd)
{
	char	*path;
	int		fd;

	path = create_path(sub_path, cmd);
	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		return (0);
	}
	close(fd);
	execve(path, argv, envp);
	free(path);
	return (-1);
}

static char	*create_sub_path(char **envp, int i, int path_id,
		int *size_sub_path)
{
	char	*sub_path;

	*size_sub_path = 0;
	while (envp[path_id][i + *size_sub_path] != ':' && envp[path_id][i
		+ *size_sub_path] != '\0')
		*size_sub_path = *size_sub_path + 1;
	sub_path = malloc(sizeof(char) * (*size_sub_path + 1));
	return (sub_path);
}

int	find_exec(t_cmd const *cmd, char *envp[])
{
	int		path_id;
	int		size_sub_path;
	char	*sub_path;
	int		i;

	path_id = find_path_id(envp);
	if (path_id == -1)
		return (0);
	i = 4;
	while (envp[path_id][i] != '\n' && envp[path_id][i] != '\0')
	{
		sub_path = create_sub_path(envp, i, path_id, &size_sub_path);
		if (!sub_path)
			return (-1);
		ft_strncpy(sub_path, envp[path_id] + i, size_sub_path);
		if (try_path(sub_path, cmd->args, envp, cmd->exe))
		{
			free(sub_path);
			return (1);
		}
		if (envp[path_id][i + size_sub_path] == '\0')
			i += size_sub_path;
		else
			i += size_sub_path + 1;
		free(sub_path);
	}
	return (0);
}
