/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:32:09 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/18 11:16:33 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	pr_usage(void)
{
	ft_putendl("usage: ./fillit file_with_tetriminos");
	return (1);
}

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
	close(fd);
	c = get_board_size(c * 4);
	while (1)
	{
		if (!(board = ft_makeboard(c++)))
			return (3);
		if (workitbaby(figs, board, 0))
		{
			free_board(&board);
			ft_lstdel(&figs, NULL);
			return (0);
		}
		free_board(&board);
	}
}
