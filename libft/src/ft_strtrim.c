/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:25:22 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 22:22:02 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*ret;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = (int)ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (s[i] != '\0')
	{
		while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
			j--;
	}
	ret = ft_strsub(s, (unsigned int)i, (size_t)(j - i));
	return (ret);
}
