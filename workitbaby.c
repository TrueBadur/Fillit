/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workitbaby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:22:33 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/15 14:20:39 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#define T_ROW (posf / board->w + ((t_tet *)(figs->content))->h)
#define T_COL (posf % board->w + ((t_tet *)(figs->content))->w)
#define T_TET ((t_tet *)(figs->content))

/*
** tries to place given figure in given pos
** or deletes given figure from given pos
** depending on f
*/

static int		place_fig(t_board *b, t_tet *fig, unsigned char posf, char f)
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
** cicle through the board to find first free spot with at least one
** direction free
*/

static short	find_free(t_board *b, short pf)
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

int				tet_cmp(t_tet *t1, t_tet *t2)
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

int				workitbaby(t_list *figs, t_board *board, unsigned short posi)
{
	short	posf;
	short	posi_c;

	if (!figs)
		return (print_board(board));
	posi_c = posi;
	posf = posi;
	while (T_ROW <= board->w && posf < board->w * board->w)
	{
		if (T_ROW >= -1 && T_COL >= -1 && T_COL <= board->w)
		{
			if (place_fig(board, T_TET, posf, 2))
			{
				posi = find_free(board, posi);
				if (workitbaby(figs->next, board, posi))
					return (1);
				place_fig(board, T_TET, posf, 1);
				posi = posi_c;
				if (figs->next && tet_cmp(T_TET, (t_tet *)figs->next->content))
					return (0);
			}
		}
		posf++;
	}
	return (0);
}
