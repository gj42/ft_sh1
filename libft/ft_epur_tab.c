/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 18:38:22 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/09 19:27:23 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epur_tab(char *str)
{
	char	*ret;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			n++;
		i++;
	}
	if (!(ret = (char*)malloc(sizeof(char) * ((ft_strlen(str) + 1) - n))))
		return (NULL);
	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == '\t' && str[i])
			i++;
		ret[n] = str[i];
		i++, n++;
	}
	ret[n] = 0;
	return (ret);
}
