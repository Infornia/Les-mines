/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:51:23 by spariaud          #+#    #+#             */
/*   Updated: 2016/05/23 00:29:36 by mwilk            ###   ########.fr       */
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

static	int	check_nodeformat(char *line)
{
	char	**split;

	if (line && line[0] && line[0] != 'L' && line[0] != '#')
	{
		split = ft_strsplit(line, ' ');
		if (split[1] && split[2]
			&& ft_isnumber(split[1])
			&& ft_isnumber(split[2]))
		{
			free_tab(split);
			return (1);
		}
		free_tab(split);
	}
	return (0);
}

int			check(t_env *env, int type)
{
	if (type == 1)
		return (check_nodeformat(env->line));
	else if (type == 2)
		return (check_command(env));
	return (0);
}
