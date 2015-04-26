/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmanage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:50:26 by gjensen           #+#    #+#             */
/*   Updated: 2015/04/22 18:47:46 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		sh_get_env_pos(char *find, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(find, env[i], ft_strlen(find)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*sh_get_env(char *find, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(find, env[i], ft_strlen(find)) == 0)
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

char	**sh_parse_env(char *find, char **env)
{
	char	**array_path;
	char	*path;

	if ((path = sh_get_env(find, env)) == NULL)
		return (NULL);
	array_path = ft_strsplit(path, ':');
	return (array_path);
}
