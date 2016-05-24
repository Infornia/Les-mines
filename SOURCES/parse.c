/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:51:39 by spariaud          #+#    #+#             */
/*   Updated: 2016/05/22 23:16:30 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static	t_node	*new_node(t_env *e, char **split)
{
	t_node		*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->links = NULL;
	new->links_count = 0;
	new->name = ft_strdup(split[0]);
	new->coord = set_coord(split);
	new->isbegin = e->begin;
	new->isend = e->end;
	new->isoccuped = 0;
	new->ant_count = 0;
	new->weight_end = 0;
	new->viewed = 0;
	e->nb_nodes++;
	e->begin = 0;
	e->end = 0;
	return (new);
}

static	int		add_node(t_env *e)
{
	int			i;
	char		**split;
	t_node		**tmp_nodes;

	split = ft_strsplit(e->line, ' ');
	i = e->nb_nodes + 1;
	if (!(tmp_nodes = (t_node **)malloc((sizeof(t_node *) * i))))
		return (0);
	i = -1;
	while (++i < e->nb_nodes)
		tmp_nodes[i] = e->nodes[i];
	tmp_nodes[i] = new_node(e, split);
	free(e->nodes);
	e->nodes = tmp_nodes;
	return (1);
}

int				parse(t_env *e)
{
	int		ret;
	int		ret_gnl;
	int		parse_step;

	ret = -1;
	parse_step = 0;
	while (ret && (ret_gnl = get_next_line(e->fd, &e->line)) > 0)
	{
		ft_putendl(e->line);
		if (e->line[0] == '#' && e->line[1] != '#')
			 ;
		else if (e->line[0] == '#' && e->line[1] == '#')
			check(e, COMMANDS);
		else if (!parse_step && ++parse_step)
			ret = set_nb_ants(e);
		else if (parse_step == 1 && check(e, NODE_FORMAT))
			ret = add_node(e);
		else if (parse_step == 2 || (parse_step == 1 && parse_step++))
			ret = set_link(e, ft_strsplit(e->line, '-'));
		free(e->line);
	}
	return (ret > 0);
}
