/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_psn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 11:45:49 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 08:15:02 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tt_psn(char *s, int nb)
{
	write(1, s, tt_slen(s));
	tt_pn(nb);
	return (1);
}
