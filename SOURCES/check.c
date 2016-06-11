/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:51:23 by spariaud          #+#    #+#             */
/*   Updated: 2016/06/11 18:33:05 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static	int	check_command(t_env *e)
{
	if (!e->begin && !e->end)
	{
		if (ft_strcmp(e->line, "##start") == 0)
			return (e->begin++);
		else if (ft_strcmp(e->line, "##end") == 0)
			return (e->end++);
		else if (ft_strcmp(e->line, "##info") == 0)
			return (e->info++);
		else if (ft_strcmp(e->line, "##move") == 0)
			return (e->move++);
		else if (ft_strcmp(e->line, "##map") == 0)
			return (e->map++);
	}
	return (0);
}

static int	no_same(t_env *e, char **split)
{
	t_node		**n;
	int			i;
	int			x;
	int			y;

	if (split[3])
		return (0);
	i = -1;
	x = atoi(split[1]);
	y = atoi(split[2]);
	n = e->nodes;
	if (n)
		while (++i < e->nb_nodes)
		{
			if (!ft_strcmp(n[i]->name, split[0])
				|| (n[i]->coord.x == x && n[i]->coord.y == y))
			{
				free_tab(split);
				return (0);
			}
		}
	free_tab(split);
	return (1);
}

static	int	check_nodeformat(t_env *e, char *line)
{
	char	**split;

	if (line && line[0] && line[0] != 'L' && line[0] != '#')
	{
		split = ft_strsplit(line, ' ');
		if (split[1] && split[2]
				&& ft_isnumber(split[1])
				&& ft_isnumber(split[2]))
			return (no_same(e, split));
		free_tab(split);
	}
	return (0);
}

int			check(t_env *e, int type)
{
	if (type == 1)
		return (check_nodeformat(e, e->line));
	else if (type == 2)
		return (check_command(e));
	return (0);
}
