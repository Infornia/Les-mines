/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:51:23 by spariaud          #+#    #+#             */
/*   Updated: 2016/05/29 23:15:24 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static	int	check_command(t_env *env)
{
	if (!env->begin && !env->end)
	{
		if (ft_strcmp(env->line, "##start") == 0)
			return (env->begin++);
		else if (ft_strcmp(env->line, "##end") == 0)
			return (env->end++);
		else if (ft_strcmp(env->line, "##info") == 0)
			return (env->info++);
		else if (ft_strcmp(env->line, "##move") == 0)
			return (env->move++);
		else if (ft_strcmp(env->line, "##map") == 0)
			return (env->map++);
	}
	return (0);
}

static int	no_same(t_env *e, char **split)
{
	t_node		**n;
	int			i;
	int			x;
	int			y;

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
