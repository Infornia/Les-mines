/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:04:16 by spariaud          #+#    #+#             */
/*   Updated: 2016/06/12 17:16:18 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

int			set_nb_ants(t_env *env)
{
	if (ft_isnumber(env->line))
		if ((env->nb_ants = ft_atoi(env->line)) > 0)
			return (1);
	return (0);
}

t_coord		set_coord(char **split)
{
	t_coord		coord;

	coord.x = -1;
	coord.y = -1;
	if (split && split[1] && split[2]
		&& ft_isnumber(split[1])
		&& ft_isnumber(split[2]))
	{
		coord.x = ft_atoi(split[1]);
		coord.y = ft_atoi(split[2]);
	}
	free_tab(split);
	return (coord);
}

int			set_link(t_env *e, char **split)
{
	int		ret;
	int		i;
	t_node	*node1;
	t_node	*node2;

	ret = 0;
	i = -1;
	node1 = NULL;
	node2 = NULL;
	if (split && split[0] && split[1] && split[2] == NULL)
	{
		while (++i < e->nb_nodes)
		{
			if (!ft_strcmp(e->nodes[i]->name, split[0]))
				node1 = e->nodes[i];
			else if (!ft_strcmp(e->nodes[i]->name, split[1]))
				node2 = e->nodes[i];
		}
		if (node1 && node2 && add_link(e, node1, node2))
			add_link(e, node2, node1);
		ret = 1;
	}
	free_tab(split);
	return (ret);
}

int			set_weight_end(t_env *e, t_node *n, int w)
{
	int	i;

	i = -1;
	if (!n || !n->links)
		return (0);
	if ((!n->weight_end && !n->isend) || n->weight_end > w)
		n->weight_end = w;
	n->ant_count = n->isbegin ? e->nb_ants : 0;
	if (n->isbegin && ++e->path_found)
		return (1);
	n->viewed = 1;
	while (n->links && n->links[++i])
		if (!n->links[i]->viewed)
			set_weight_end(e, n->links[i], w + 1);
	return (1);
}
