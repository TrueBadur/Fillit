/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:32:09 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/13 20:12:58 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_board_size(int fc)
{
	int c;

	c = ft_sqrt(fc);
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
	c = get_board_size(c * 4);
	while (1)
	{
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
