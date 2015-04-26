/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_buildin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 18:06:00 by gjensen           #+#    #+#             */
/*   Updated: 2015/04/12 16:50:05 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"


void	sh_builtin_cd_open(char *dir, char ***env)
{
	(void)env;

	if (chdir(dir) != 0)
		ft_putendl_fd("Error", 2);
}

void	sh_builtin_cd(char **av, char ***env)
{
	char *cmd;

	cmd = av[1];
	if (ft_arrlen(av) == 1 || (av[1] && (ft_strcmp(av[1],"~") == 0)))
	{
		if (!(cmd = sh_get_env("HOME", *env)))
			return (ft_putendl_fd("ft_minishell1: cd: HOME not set", 2));
	}
	else if (ft_arrlen(av) > 2)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return ;
	}

	if (sh_isbin(cmd) == 1)
		sh_builtin_cd_open(cmd, env);
	else
		ft_putendl_fd("ft_minishell1: cd: no such file or directory", 2);
}
