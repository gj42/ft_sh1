/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:08:36 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/06 21:04:01 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		fork_process(char *path, char **env, char **av)
{
	pid_t	father;
	int		stat_loc;

	father = fork();
	save_cpid(&father);
	if (father != -1)
	{
		if (father == 0)
		{
			if (execve(path, av, env) == -1)
				ft_putendl_fd("Format error", 2);
			exit (0);
		}
		else
			waitpid(father, &stat_loc, 0);
	}
	if (WIFSIGNALED(stat_loc))
		sh_wrong_exit(WTERMSIG(stat_loc), path);
	father = 0;
	save_cpid(&father);
}

static void	free_memory(char *line, char **paths, char **av)
{
	if (line)
		ft_strdel(&line);
	if (av)
		ft_arrfree(&av);
	if (paths)
		ft_arrfree(&paths);
}

void		sh_loop(char **env)
{
	char	*line;
	char	**paths;
	char	**sh_env;
	char	**av;

	sh_env = ft_arrcpy(env);
	while (42)
	{
		sh_save_env(&sh_env);
		sh_prompt(sh_env);
		if (get_next_line(0, &line) <= 0)
			exit(0);
		av = ft_strsplit(line, ';');
		paths = sh_parse_env("PATH", sh_env);	
		if (!sh_search_builtin(av, &sh_env))
			sh_execute_bin(av, sh_env, paths);
		free_memory(line, av, paths);
	}
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	sh_signals();
	sh_loop(env);
	return (0);
}
