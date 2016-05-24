/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 06:44:52 by mwilk             #+#    #+#             */
/*   Updated: 2016/05/11 20:06:42 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void	add_link(t_env *e, t_node *node, t_node *add)
{
	int	i;

	i = node->links_count;
	if (node->links == NULL)
	{
		node->links = malloc(sizeof(t_node *) * e->nb_nodes);
		ft_bzero(node->links, sizeof(t_node *) * e->nb_nodes);
	}
	node->links[i] = add;
	node->links_count++;
}

t_node		*find_end(t_env *e)
{
	int			i;
	t_node		**n;

	i = -1;
	n = e->nodes;
	while (++i < e->nb_nodes && n[i] && !n[i]->isend)
		;
	return (n[i] && n[i]->isend && ++n[i]->viewed ? n[i] : NULL);
}
