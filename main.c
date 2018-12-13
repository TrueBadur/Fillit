/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:32:09 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/13 23:25:23 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	get_board_size(int fc)
{
	int c;

	c = ft_sqrt(fc);
	//printf("in sqrt c = %d\n", c);
	return ((c * c == fc) ? c : c + 1);
}

int main (int ac, char **av)
{
	int		fd;
	t_list	*figs;
	t_board	*board;
	int		c;

	if (ac == 1 || ac > 2)
	{
//		pr_usage();				//TODO
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (2);
	}
	figs = read_figs(fd, &c);
//	printf("c = %d\n", c);
	c = get_board_size(c * 4);
//	printf("c = %d\n", c);
	while (1)
	{
//		printf("Board size = %d\n", c);
		if (!(board = ft_makeboard(c)))	//TODO
			return (3);
		if (workitbaby(figs, board, 0))
		{
			free_board(&board);
			ft_lstdel(&figs, NULL);
			close(fd);
			return (0);					//TODO
		}
		c++;
	}
}
