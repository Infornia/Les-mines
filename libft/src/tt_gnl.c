/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:26:26 by mwilk             #+#    #+#             */
/*   Updated: 2016/05/19 13:18:03 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		freedom(char **to_red, char **line)
{
	*line = ft_strdup(*to_red);
	free(*to_red);
	*to_red = NULL;
}

static int		send_cut_keep(char **line, char **to_red, char *mother_cutter)
{
	*line = *to_red;
	*mother_cutter = '\0';
	*to_red = ft_strdup(mother_cutter + 1);
	return (ft_strlen(*line));
}

static	void	ft_strjoin_gnl(char **to_red, char *bull)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(*to_red, bull);
	free(*to_red);
	*to_red = tmp;
}

int				tt_gnl(const int fd, char **line)
{
	char			bull[BUFF_SIZE];
	static char		*to_red;
	char			*mother_cutter;
	int				ret;

	ret = -1;
	if (fd > -1 && line && !to_red && (ret = read(fd, bull, BUFF_SIZE - 1)) > 1)
	{
		bull[ret] = 0;
		to_red = ft_strdup(bull);
	}
	if (ret == -1)
		return (ret);
	while (!ft_strchr(to_red, '\n') && (ret = read(fd, bull, BUFF_SIZE - 1)))
	{
		bull[ret] = 0;
		ft_strjoin_gnl(&to_red, bull);
	}
	if ((mother_cutter = ft_strchr(to_red, '\n')))
		return (send_cut_keep(line, &to_red, mother_cutter));
	freedom(&to_red, line);
	return (tt_slen(*line));
}
