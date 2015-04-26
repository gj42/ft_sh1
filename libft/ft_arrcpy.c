/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:05:29 by gjensen           #+#    #+#             */
/*   Updated: 2015/04/17 21:44:25 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcpy(char **arr)
{
	char 	**new_arr;
	t_uint	pos;

	if ((new_arr =(char**)malloc(sizeof(char*) * (ft_arrlen(arr) + 1))) == NULL)
		return (NULL);
	pos = 0;
	while (arr && arr[pos])
	{
		new_arr[pos] = ft_strdup(arr[pos]);
		pos++;
	}
	new_arr[pos] = NULL;
	return (new_arr);
}
