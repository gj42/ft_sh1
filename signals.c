/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 20:29:35 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/04 21:42:47 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

pid_t	save_cpid(pid_t *father)
{
	static pid_t save;

	if (father)
	{
		save = *father;
		return (0);
	}
	else
		return (save);
}

char	**sh_save_env(char ***env)
{
	static char	**save;

	if (env && *env)
	{
		save = *env;
		return (NULL);
	}
	else
		return (save);
}

static	void	sh_signal_handle(int signum)
{
	char	**env;
	pid_t	cpid;

	env = sh_save_env(NULL);
	cpid = save_cpid(NULL);
	if (signum == SIGINT)
	{
		if (!cpid)
		{
			if (env)
			{
				ft_putchar('\n');
				sh_prompt(env);
			}
		}
	}	
}

void	sh_signals(void)
{
	signal(SIGINT, sh_signal_handle);

}
