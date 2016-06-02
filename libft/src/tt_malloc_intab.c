/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_malloc_intab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 23:00:36 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 22:22:53 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**tt_malloc_intab(int j, int i)
{
	int		**tabint;
	int		bzero;

	if (!(tabint = (int **)malloc(sizeof(int *) * (size_t)j)))
		return (NULL);
	while (j != -1)
	{
		tabint[j] = (int *)malloc(sizeof(int) * (size_t)i);
		bzero = -1;
		while (++bzero < i)
			tabint[j][bzero] = 0;
	}
	return (tabint);
}
