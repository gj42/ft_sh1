/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:11:32 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/06 12:42:41 by gjensen          ###   ########.fr       */
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
	else if (S_ISLNK(filestat.st_mode))
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
	char buf[1024];

	if (env && *env)
	{
		ft_putstr("--Minishell% ");
		if (getcwd(buf, 1024))
			ft_putstr(sh_replace_home(buf, env)),ft_putstr("% ");
		ft_putchar('\n');
		ft_putstr("$> ");
	}
}

void	sh_execute_bin(char **av, char **env, char **paths)
{
	int		i;
	char	*cmd;
	char	*str;
	int		found;
	char	**option;
	int		n;

	n = 0;
	if (!av || !env || !(*av))
		return ;
	while (av[n])
	{
		found = 0;
		i = 0;
		option = ft_strsplit(av[n], ' ');
		if (paths)
		{
			while (paths[i])
			{
				if ((cmd = sh_search_bin(option[0], paths[i])) != NULL)
					fork_process(cmd, env, option), ft_strdel(&cmd), found = 1;
				i++;
			}
		}
		if (sh_isbin(option[0]) == 2)
			fork_process(option[0], env, option), found = 1;
		if (found == 0 && option[0])
		{
			str = ft_strjoin("ft_minishell1: command not found: ", option[0]);
			ft_putendl_fd(str, 2);
			ft_strdel(&str);
		}
		n++;
		ft_arrfree(&option);
	}	
}
