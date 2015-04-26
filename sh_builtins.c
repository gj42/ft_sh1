/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 19:18:34 by gjensen           #+#    #+#             */
/*   Updated: 2015/04/20 17:39:07 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"


void	sh_builtin_exit(char **av)
{
	unsigned char	val;

	val = 0;
	if (av && av[1])
	{
		if (ft_isdigit(av[1][0]))
			val = ft_atoi(av[1]);
		else
		{
			ft_putendl_fd("exit: Expression Syntax.", 2);
			return ;
		}
	}
	exit(val);
}

int		sh_search_builtin(char **av, char ***env)
{
	int state;

	state = 0;
	if (av[0])
	{
		if (ft_strcmp(av[0], "cd") == 0)
			sh_builtin_cd(av, env), state = 1;
		else if (ft_strcmp(av[0], "exit") == 0)
			sh_builtin_exit(av), state = 1;
		else if (ft_strcmp(av[0], "env") == 0)
			sh_builtin_env(av, env), state = 1;
		else if (ft_strcmp(av[0], "setenv") == 0)
			sh_builtin_setenv(av, env), state = 1;
		else if (ft_strcmp(av[0], "unsetenv") == 0)
			sh_builtin_unsetenv(av, env), state = 1;
	}
	return (state);
}
