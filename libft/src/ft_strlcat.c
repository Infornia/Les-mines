/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 21:23:13 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 22:47:34 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	char		*dst_cp;
	const char	*src_cp;
	size_t		i;
	size_t		dlen;

	dst_cp = dst;
	src_cp = src;
	i = size;
	while (i-- != 0 && *dst_cp != '\0')
		++dst_cp;
	dlen = (size_t)(dst_cp - dst);
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(src_cp));
	while (*src_cp != '\0')
	{
		if (i != 1)
		{
			*dst_cp++ = *src_cp;
			--i;
		}
		++src_cp;
	}
	*dst_cp = '\0';
	return (dlen + (size_t)(src_cp - src));
}
