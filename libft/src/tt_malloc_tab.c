/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_malloc_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:06:45 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 22:18:30 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tt_malloc_tab(int size_1, int size_2)
{
	char		**ret;
	int			i;

	if (!(ret = (char **)malloc(sizeof(char *) * (size_t)(size_1 + 1))))
		return (NULL);
	i = -1;
	while (++i < size_1)
		ret[i] = ft_strnew((size_t)size_2);
	return (ret);
}
