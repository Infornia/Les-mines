/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 06:44:52 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/01 16:11:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			add_link(t_env *e, t_node *node, t_node *add)
{
	int	i;

	i = 0;
	if (node->links == NULL)
	{
		node->links = malloc(sizeof(t_node *) * e->nb_nodes);
		ft_bzero(node->links, sizeof(t_node *) * e->nb_nodes);
	}
	while (i < node->links_count && ft_strcmp(node->links[i]->name, add->name))
		i++;
	if (!(i < node->links_count))
	{
		node->links[i] = add;
		node->links_count++;
	}
	return (1);
}

t_node		*find_end(t_env *e)
{
	int			i;
	t_node		**n;

	i = 0;
	n = e->nodes;
	while (i < e->nb_nodes && !n[i]->isend)
		++i;
	return (i < e->nb_nodes && n[i]->isend && ++n[i]->viewed ? n[i] : NULL);
}
