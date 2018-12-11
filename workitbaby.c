/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workitbaby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:22:33 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/11 23:05:31 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	place_fig(t_board *board, t_tet fig, int block)
{
	char	*i;

	if (block >= 8)
		return (1);
	i = ((char *)(fig->data)) + block;
	if (((char **)board->data)[board->row + *i][board->col + *(i + 1)] != '.')
		return (0);
	if (place_fig(board, fig, block + 2))
	{
		((char **)board->data)[board->row + *i][board->col + *(i + 1)] = fig->l;
		return (1);
	}
	return (0);
}

static void	unplace_fig(t_board b, t_tet f)
{
	char	*i;
	int		j;

	i = ((char *)(f->data)) + 8;
	j = 8;
	while (j)
	{
		((char **)b->data)[b->row + *(i - j)][b->col + *(i - j + 1)] = '.';
		j -= 2;
	}
}

void		workitbaby(t_list *figs, t_board *board, int col, int row)
{
	t_list	*cur;
	t_list	*prev;

	cur = figs;
	prev = NULL;
	if (!figs)
	{
		print_board(board);
		exit();
	}
	while (cur)
	{
		while (row + cur->h <= board->h)
		{
			while (col + cur->w + j <= board->w)
			{
				if (place_fig(board, cur, 0))
				{
					if (!prev)
						figs = cur->next;
					else
						prev->next = cur->next;
					workitbaby(figs, board, col + 1, row);
					unplace_fig(board, cur);
				}
				col++;
			}
			row++;
		}
		prev = cur;
		cur = cur->next;
	}
}
