/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 08:18:03 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/02 07:45:57 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void			sort_nodes(t_node **n, int nb_nodes)
{
	int		i;
	int		j;
	t_node	*swap;

	i = -1;
	while (++i < nb_nodes)
	{
		j = -1;
		while (++j < nb_nodes - i - 1)
			if ((n[j + 1]->weight_end
				&& n[j]->weight_end > n[j + 1]->weight_end)
				|| n[j + 1]->isend
				|| (!n[j]->isend && !n[j]->weight_end && n[j + 1]->weight_end))
			{
				swap = n[j];
				n[j] = n[j + 1];
				n[j + 1] = swap;
			}
	}
}

static void		color(int i)
{
	tt_psns("\x1B[3", i % 7 + 1, "mL");
	tt_pns(i, "-");
}

static int		move_this(t_node **in, t_node **out, int first_move, int m)
{
	static int		ant_name = 1;
	static int		move = 1;

	m && first_move ? tt_ps(CYAN) && tt_psns("Step ", move++, " : ") : 0;
	first_move ? --first_move : tt_pc(' ');
	if ((*out)->isbegin)
		(*out)->ant_name = ant_name++;
	(*in)->ant_name = (*out)->ant_name;
	++(*in)->ant_count;
	--(*out)->ant_count;
	color((*in)->ant_name);
	tt_ps((*in)->name);
	return (first_move);
}

static int		move_ants(t_node **nodes, int nb_nodes, int m, int nb_paths)
{
	int		i;
	int		j;
	int		first_move;
	t_node	**links;

	i = 0;
	first_move = 1;
	while (i < nb_nodes && (nodes[i]->weight_end || !i))
	{
		links = nodes[i]->links;
		j = 0;
		while (links[j])
		{
			if ((!nodes[i]->ant_count || nodes[i]->isend)
				&& links[j]->ant_count
				&& ((nodes[i]->weight_end < links[j]->weight_end
				&& !nodes[i]->isbegin)
				|| (links[j]->isbegin
				&& nodes[i]->weight_end < links[j]->ant_count + nb_paths - 1)))
				first_move = move_this(&nodes[i], &links[j], first_move, m);
			++j;
		}
		++i;
	}
	return (tt_ps("\n"));
}

int				solve(t_env *e)
{
	while (e->nodes[0]->ant_count != e->nb_ants)
	{
		move_ants(e->nodes, e->nb_nodes, e->move, e->path_found);
		print_result(e, 0, 0);
	}
	return (1);
}
