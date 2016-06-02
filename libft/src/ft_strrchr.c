/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:42:17 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 22:26:41 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = (int)ft_strlen(str);
	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return ((str + i));
	while (i >= 0)
	{
		if (str[i] == ((char)c))
			return (str + i);
		i--;
	}
	return (NULL);
}
