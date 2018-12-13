/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workitbaby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:22:33 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/13 23:19:01 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
	while (f-- > 0)
	{
		j = 10;
		while (j -= 2)
		{
			if (f == 1)
			{
				if ((b->data)[ro + *(i - j)][co + *(i - j + 1)] != '.')
					return (0);
			}
			else
				(b->data)[ro + *(i - j)][co + *(i - j + 1)] = c;
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
	while (row <= board->w && posf < board->w * board->w)
	{
		//printf("Checking row = %d, col = %d for fig %c\n", row, col, cur->l);
		if (row >= -1 && col >= -1 && col <= board->w)
		{
			if (place_fig(board, cur, posf, 2))
			{
				return (posf);
			}
		}
		posf++;
		row = posf / board->w + cur->h;
		col = posf % board->w + cur->w;
	}
	return (-1);
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

	i = b->data;
	while (pf < b->w * b->w)
	{
		ro = pf / b->w;
		co = pf % b->w;
		if (i[(int)ro][(int)co] == '.')
		{
			if ((ro + 1 < b->w && i[ro + 1][(int)co] == '.') ||
					(co + 1 < b->w && i[(int)ro][co + 1] == '.') ||
					(ro - 1 >= 0 && i[ro - 1][(int)co] == '.') ||
					(co - 1 >= 0 && i[(int)ro][co - 1] == '.'))
				return (pf);
		}
		pf++;
	}
	return (0);
}

int			tet_cmp(t_tet *t1, t_tet *t2)
{
	int i;
	if (t1->w != t2->w || t1->h != t2->h)
		return (0);
	i = -1;
	while (++i < 8)
	{
		if ((t1->data)[i] != (t2->data)[i])
			return (0);
	}
	return (1);
}

int			workitbaby(t_list *figs, t_board *board, unsigned short posf)
{
	t_list			*cur;
	t_list			*prev;
	short	posi;
	short	posf_c;

	if (!figs)
	{
		print_board(board);
		return (1);
	}
	cur = figs;
	prev = NULL;
	posf_c = posf;
	while (cur)
	{
		//printf("In while testing %c\n", ((t_tet*)(cur->content))->l);
		/*if (((t_tet*)(cur->content))->l > 'Q')
		{
			print_board(board);
			printf("\n");
		}*/
		if ((posi = find_place_fig(board, cur->content, posf)) != -1)
		{
			posf = find_free(board, posf);
			if (!prev)
				figs = cur->next;
			else
				prev->next = cur->next;
		//	printf("posf = %d\n", posf);
			if (workitbaby(figs, board, posf))
				return (1);
			place_fig(board, cur->content, posi, 1);
			if (!prev)
				figs = cur;
			else
				prev->next = cur;
			posf = posf_c;
			while (cur->next && tet_cmp((t_tet *)cur->content, (t_tet *)cur->next->content))
			{
				//printf("In tet_cmp\n");
				cur = cur->next;
			}
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}
