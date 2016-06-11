/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:50:58 by spariaud          #+#    #+#             */
/*   Updated: 2016/06/11 16:59:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

void			print_result(t_env *env, int i, int after)
{
	if (!env->info)
		return ;
	if (!after)
		tt_psss(RED, "\nCurrent data :\n", BLUE);
	else
		tt_psss(RED, "\nAfter solving :\n", BLUE);
	tt_psns("Ants: ", env->nb_ants, "\n");
	while (env->nodes && i < env->nb_nodes)
	{
		tt_psss(GRN, "name : ", env->nodes[i]->name);
		tt_pssn(MAG, "\t START: ", env->nodes[i]->isbegin);
		tt_psn(" | END: ", env->nodes[i]->isend);
		tt_psn(" | weight: ", env->nodes[i]->weight_end);
		tt_psn(" | ants: ", env->nodes[i]->ant_count);
		tt_pssn(CYAN, "\t coord x,y: (", env->nodes[i]->coord.x);
		tt_psn(", ", env->nodes[i]->coord.y);
		tt_ps(")\n");
		i++;
	}
	if (after)
		print_links(env->nodes, env->nb_nodes);
}

static t_env	*init_env(void)
{
	static t_env	env;

	env.nodes = NULL;
	env.ants = NULL;
	env.nb_ants = 0;
	env.nb_nodes = 0;
	env.fd = 0;
	env.line = NULL;
	env.begin = 0;
	env.end = 0;
	env.path_found = 0;
	env.info = 0;
	env.move = 0;
	env.color = 0;
	env.map = 0;
	return (&env);
}

static int		error(void)
{
	tt_pss(RED, "ERROR");
	exit(0);
}

int				main(void)
{
	t_env	*env;

	env = init_env();
	parse(env) ? tt_pl("") : error();
	if (env->nodes)
	{
		set_weight_end(env, find_end(env), 0) ? 0 : error();
		sort_nodes(env->nodes, env->nb_nodes);
		print_result(env, 0, 0);
		env->path_found ? solve(env) : error();
		print_result(env, 0, 1);
	}
	else
		error();
	free_env(env);
	return (0);
}
