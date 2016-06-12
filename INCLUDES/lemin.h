/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:53:05 by spariaud          #+#    #+#             */
/*   Updated: 2016/06/12 17:20:32 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define NODE_FORMAT 1
# define COMMANDS 2

typedef	struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef	struct		s_node
{
	t_coord			coord;
	struct s_node	**links;
	char			*name;
	int				weight_end;
	int				viewed;
	int				links_count;
	int				ant_count;
	int				ant_name;
	int				isoccuped;
	int				isbegin;
	int				isend;
}					t_node;

typedef	struct		s_ant
{
	char			*node;
	char			**nodes_viewed;
}					t_ant;

typedef	struct		s_env
{
	t_node			**nodes;
	t_ant			**ants;
	int				nb_ants;
	int				nb_nodes;
	int				fd;
	int				begin;
	int				end;
	int				info;
	int				move;
	int				path_found;
	char			*line;
}					t_env;

int					set_nb_ants(t_env *env);
t_coord				set_coord(char **split);
int					set_link(t_env *e, char **split);
int					set_weight_end(t_env *env, t_node *n, int weight);

int					parse(t_env *env);
int					check(t_env *env, int type);
int					solve(t_env *env);
void				sort_nodes(t_node **n, int nb_nodes);

void				tt_printab(char **t);
void				print_links(t_node **t, int nb_nodes);
void				print_result(t_env *e, int i, int after);

void				free_env(t_env *e);
void				free_tab(char **t);

int					add_link(t_env *e, t_node *link, t_node *add);
t_node				*find_end(t_env *e);
#endif
