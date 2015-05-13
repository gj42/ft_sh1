/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_buildin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 18:06:00 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/13 14:53:55 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh_builtin_cd_open(char *dir, char ***env)
{
	char pwd[1024];

	if (access(dir, F_OK) == 0)
	{
		if (sh_isbin(dir) == 1 || sh_isbin(dir) == 3)
		{
			getcwd(pwd, 1024);
			if (chdir(dir) == 0)
			{
				if (pwd)
					sh_builtin_setenv_mng("OLDPWD", pwd, env);
				if (getcwd(pwd, 1024))
					sh_builtin_setenv_mng("PWD", pwd, env);
			}
			else
				ft_putendl_fd("Error", 2);
		}
	}
	else
		(ft_putendl_fd("ft_minishell1: cd: no such file or directory", 2));
}

void	sh_builtin_cd(char **av, char ***env)
{
	char *cmd;

	cmd = av[1];
	if (ft_arrlen(av) > 2)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return ;
	}
	if (ft_arrlen(av) == 1 || (cmd && (ft_strcmp(cmd, "~") == 0)))
	{
		if (!(cmd = sh_get_env("HOME", *env)))
			return (ft_putendl_fd("ft_minishell1: cd: HOME not set", 2));
	}
	else if (cmd && (ft_strcmp(cmd, "-") == 0))
	{
		if (!(cmd = sh_get_env("OLDPWD", *env)))
			return (ft_putendl_fd("ft_minishell1: cd: OLDPWD not set", 2));
		else
			ft_putendl(cmd);
	}
	sh_builtin_cd_open(cmd, env);
}
