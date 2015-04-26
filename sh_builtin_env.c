/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 16:43:20 by gjensen           #+#    #+#             */
/*   Updated: 2015/04/12 20:05:10 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"


void	sh_builtin_env(char **av, char ***env)
{
	int		i;
	char	**varenv;

	i = 0;
	
	varenv = *env;
	if (ft_arrlen(av) == 1)
	{
		while (varenv[i])
		{
			ft_putendl(varenv[i]);
			i++;
		}
	}
}
