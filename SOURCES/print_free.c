/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 06:44:13 by mwilk             #+#    #+#             */
/*   Updated: 2016/05/25 00:15:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void	tt_printab(char **split)
{
	char **tmp;

	tmp = split;
	if (tmp--)
		while (++tmp && *tmp && **tmp)
		{
			ft_putstr(" [");
			ft_putstr(*tmp);
			ft_putstr("] ");
		}
}

void	print_links(t_node **nodes, int nb_nodes)
{
	int	i;
	int	j;

	j = -1;
	tt_pss(RED, "\nPrinting Links\n");
	if (nodes)
		while (++j < nb_nodes)
		{
			i = -1;
			while (++i < nodes[j]->links_count)
			{
				tt_pss(BLUE, nodes[j]->name);
				tt_pss(MAG, "\t<-is linked with->\t\t");
				tt_psl(GRN, nodes[j]->links[i]->name);
			}
		}
	else
		tt_ps("No Fucking Links");
	tt_pl("");
}

void	free_tab(char **t)
{
	int	i;

	i = 0;
	if (t)
		while (t[i])
			free(t[i++]);
	free(t);
}

void	free_env(t_env *e)
{
	int	i;

	i = -1;
	if (e->nodes)
		while (++i < e->nb_nodes)
		{
			free(e->nodes[i]->links);
			free(e->nodes[i]->name);
			free(e->nodes[i]);
		}
	free(e->nodes);
}
