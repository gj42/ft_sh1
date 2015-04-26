/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:46:12 by gjensen           #+#    #+#             */
/*   Updated: 2015/04/02 19:21:29 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	if (str)
	{
		while (*str)
		{
			if (*str == (char)c)
				return (str);
			++str;
		}
		if ((char)c == 0)
			return (str);
	}
	return (NULL);
}
