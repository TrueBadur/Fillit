/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workitbaby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:22:33 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/13 13:59:44 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * tries to place given figure in given pos
 * or deletes given figure from given pos
 * depending on f
 */

static int	place_fig(t_board *b, t_tet *fig, unsigned char posf, char f)
{
	char	*i;
	char	j;
	char	ro;
	char	co;
	char	c;

	i = ((char *)(fig->data)) + 8;
	ro = posf / b->w;
	co = posf % b->w;
	c = (f == 1) ? '.' : fig->l;
	while (--f > 0)
	{
		j = 10;
		while (j -= 2)
		{
			if (f == 2)
			{
				if (((char **)b->data)[ro + *(i - j)][co + *(i - j + 1)] != '.')
					return (0);
			}
			else
				((char **)b->data)[ro + *(i - j)][co + *(i - j + 1)] = c;
		}
	}
	return (1);
}

/* 
 * cicle through the board trying to put figure in each space
 * if figures width or height is in the boards boundaries
 */

static short	find_place_fig(t_board *board, t_tet *cur, unsigned short posf)
{
	char row;
	char col;

	row = posf / board->w + cur->h;
	col = posf % board->w + cur->w;
	while (row > 0 && row <= board->w)
	{
		if (col > 0 && col <= board->w)
			if (place_fig(board, cur, posf, 2))
				return (posf);
		posf++;
		row = posf / board->w + cur->h;
		col = posf % board->w + cur->w;
	}
	return (0);
}

/*
 * cicle through the board to find first free spot with at least one 
 * direction free
 */

static unsigned short find_free(t_board *b, short pf)
{
	char	ro;
	char	co;
	char	**i;

	i = (char **)b->data;
	while (pf < b->w * b->w)
	{
		ro = pf / b->w;
		co = pf % b->w;
		if (i[ro][co] != '.')
		{
			if ((ro + 1 < b->w && i[ro + 1][pf % b->w] == '.') ||
					(co + 1 < b->w && i[ro][co + 1] == '.') ||
					(ro - 1 >= 0 && i[ro - 1][co] == '.') ||
					(co - 1 >= 0 && i[ro][co - 1] == '.'))
				return (pf);
		}
		pf++;
	}
	return (0);
}

void			workitbaby(t_list *figs, t_board *board, unsigned short posf)
{
	t_list			*cur;
	t_list			*prev;
	unsigned short	posi;

	if (!figs)
	{
		print_board(board);
		free_board(&board);
		exit(0);
	}
	cur = figs;
	prev = NULL;
	while (cur)
	{
		if ((posi = find_place_fig(board, cur->content, posf)))
		{
			posf = find_free(board, posf);
			if (!prev)
				figs = cur->next;
			else
				prev->next = cur->next;
			workitbaby(figs, board, posf);
			place_fig(board, cur->content, posi, 1);
		}
		prev = cur;
		cur = cur->next;
	}
}
