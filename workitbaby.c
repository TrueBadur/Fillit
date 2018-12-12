/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workitbaby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:22:33 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/12 20:07:46 by ehugh-be         ###   ########.fr       */
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

static unsigned short find_free(t_board *b, short posf, short posi, char di)
{
	char	ro;
	char	co;

	//check posf pos 
	while (posf < board->w * board->w)
	{
		if (((char **)b->data)[posf / b->w][posf % b->w] != '.')
		{
			if(((char **)b->data)[posf / b->w + 1][posf % b->w] == '.'
				|| ((char **)b->data)[posf / b->w][posf % b->w + 1] == '.')
				return (posf);
			if ((posf > b->w && posf % b->w 
		}
	}
	//if it's not filled
	// if at least one of directions is free 
	//  return this pos
	//move on
	return (0);
}

void			workitbaby(t_list *figs, t_board *board, unsigned short posf)
{
	t_list			*cur;
	t_list			*prev;
	unsigned short	posi;

	if (!figs)
	{
		//	print_board(board);
		exit(0);
	}
	cur = figs;
	prev = NULL;
	while (cur)
	{
		//while there are figures
		//try to place current fig somewhere on board
		//if success 
		// find first free space and store it
		// store point of insertion of curr fig
		// call recursive with trimed list of figs and first free point
		// if recursion returned
		//  remove fig from insertion point
		//  back find last free space
		if ((posi = find_place_fig(board, cur->content, posf)))
		{
			posf = find_free(board, posf, posi, 1);
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
