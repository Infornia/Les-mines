/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:06:45 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 08:15:29 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	tt_sqrt(int x)
{
	int		prev;
	int		k;
	int		kmax;
	float	s;

	prev = 0;
	k = -1;
	kmax = 1000;
	s = 1;
	while (++k < kmax)
	{
		prev = (int)s;
		s = (s + x / s) / 2;
		if (prev == (int)s)
			break ;
	}
	return (s);
}
