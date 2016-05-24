/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:50:58 by spariaud          #+#    #+#             */
/*   Updated: 2016/05/23 00:39:35 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static void		print_result(t_env *env, int i, int after)
{
	if (!env->info)
		return ;
	if (!after)
		tt_pss(GRN, "\nBefore : \n\nNombre de fourmis: ");
	else
		tt_pss(GRN, "\nAfter : \n\nNombre de fourmis: ");
	tt_pns(env->nb_ants, "\n");
	while (env->nodes && i < env->nb_nodes)
	{
		tt_pss("name : ", env->nodes[i]->name);
		tt_psn("\t START: ", env->nodes[i]->isbegin);
		tt_psn(" | END: ", env->nodes[i]->isend);
		tt_psn(" | weight: ", env->nodes[i]->weight_end);
		tt_psn(" | ants: ", env->nodes[i]->ant_count);
		tt_psn("\t coord x,y: (", env->nodes[i]->coord.x);
		tt_psn(", ", env->nodes[i]->coord.y);
		tt_ps(")\n");
		i++;
	}
	if (!after)
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

static void	error()
{
	ft_putendl("ERROR");
	exit(0);
}

int				main(void)
{
	t_env	*env;

	env = init_env();
	parse(env) ? ft_putendl("") : tt_ps("ERROR: Not enough data to work with\n");
	if (env->nodes)
	{
		set_weight_end(env, find_end(env), 0) ? 0 : tt_ps(RED "ERROR: Can't put nodes's weight properly\n");
		sort_nodes(env->nodes, env->nb_nodes);
		print_result(env, 0, 0);
		env->path_found ? solve(env) : tt_ps(RED "ERROR: Start and end not linked\n");
		print_result(env, 0, 1);
//		tt_pn(env->path_found);
	}
	else
		error();
	free_env(env);
	return (0);
}
