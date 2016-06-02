/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:06:11 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 08:12:58 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tt_del_tab(char **t, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(t[i++]);
	free(t);
}
