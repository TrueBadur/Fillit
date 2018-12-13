/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:32:09 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/14 00:19:49 by ehugh-be         ###   ########.fr       */
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
	printf("in sqrt c = %d\n", i);
	return (i);
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
	printf("c = %d\n", c);
	c = get_board_size(c * 4);
	printf("c = %d\n", c);
	while (1)
	{
		printf("Board size = %d\n", c);
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
