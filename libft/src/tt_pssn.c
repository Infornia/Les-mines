/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_pssn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 00:18:55 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 08:15:16 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		tt_pssn(char *s, char *s2, int n)
{
	write(1, s, tt_slen(s));
	write(1, s2, tt_slen(s2));
	tt_pn(n);
	return (1);
}
