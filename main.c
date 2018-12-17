/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:32:09 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/17 16:42:21 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	get_board_size(int fc)
{
	int i;

	i = 2;
	while (i * i < fc)
		i++;
	return (i);
}

int			main(int ac, char **av)
{
	int		fd;
	t_list	*figs;
	t_board	*board;
	int		c;

	if (ac == 1 || ac > 2)
		return (pr_usage());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (put_er(2, NULL, NULL));
	figs = read_figs(fd, &c);
	c = get_board_size(c * 4);
	while (1)
	{
		if (!(board = ft_makeboard(c++)))
			return (3);
		if (workitbaby(figs, board, 0))
		{
			free_board(&board);
			ft_lstdel(&figs, NULL);
			close(fd);
			return (0);
		}
	}
}
