/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_printab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:06:45 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 08:14:44 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tt_printab(char **t)
{
	int		i;

	i = 0;
	while (t && t[i])
		ft_putendl(t[i++]);
}
