/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:11:32 by gjensen           #+#    #+#             */
/*   Updated: 2015/04/15 20:21:37 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		sh_isbin(char *path)
{
	int		state;
	t_stat	filestat;

	state = 0;
	if (lstat(path, &filestat) == -1)
		state = 0;
	else if (S_ISDIR(filestat.st_mode))
		state = 1;
	else if (S_ISREG(filestat.st_mode))
		state = 2;
	return (state);
}

int		sh_acess(char *path)
{
	if (sh_isbin(path) == 2)
	{
		if (access(path, X_OK) == 0)
			return (0);
		else
			return (-1);
	}
	return (-1);
}

char	*sh_search_bin(char *line, char *dirpath)
{
	char	*temp;
	char	*full_path;
	int		ex;

	temp = ft_strjoin(dirpath, "/");
	full_path = ft_strjoin(temp, line);
	free (temp);
	ex = sh_acess(full_path);
	if (ex == 0)
		return (full_path);
	ft_strdel(&full_path);
	return (NULL);
}

void	sh_prompt(char **env)
{
	(void)env;
	ft_putstr("$> ");
}

void	sh_execute_bin(char **av, char **env, char **paths)
{
	int		i;
	char	*cmd;
	char	*str;
	int		found;

	found = 0;
	i = 0;
	if (paths)
	{
		while (paths[i])
		{
			if ((cmd = sh_search_bin(av[0], paths[i])) != NULL)
				fork_process(cmd, env, av), ft_strdel(&cmd), found = 1;
			i++;
		}
	}
	if (sh_isbin(av[0]) == 2)
		fork_process(av[0], env, av), found = 1;
	if (found == 0 && av[0])
	{
		str = ft_strjoin("ft_minishell1 : command not found: ", av[0]);
		ft_putendl_fd(str, 2);
		ft_strdel(&str);
	}
}
