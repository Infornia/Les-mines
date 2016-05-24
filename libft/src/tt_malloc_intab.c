/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_malloc_intab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 23:00:36 by mwilk             #+#    #+#             */
/*   Updated: 2016/04/01 23:18:11 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**tt_malloc_intab(int j, int i)
{
	int		**tabint;
	int		bzero;

	tabint = (int **)malloc(sizeof(int *) * j);
	while (--j != -1)
	{
		tabint[j] = (int *)malloc(sizeof(int) * i);
		bzero = -1;
		while (++bzero < i)
			tabint[j][bzero] = 0;
	}
	return (tabint);
}
