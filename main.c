/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:32:09 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/11 16:15:18 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int ac, char **av)
{
	int fd;
	t_vector *figs;
	char **board;
	int i;

	if (ac == 1 || ac > 2)
	{
		pr_usage();				//TODO
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (2);
	}
	figs = read_figs(fd);				//TODO
	if (!(board = ft_makeboard(figs)))	//TODO
		return (3);
	workitbaby(figs, board);					//TODO
	free_board(board);
	ft_vecdel(&figs);
	close(fd);
}
