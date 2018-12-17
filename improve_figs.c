/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve_figs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:26:49 by mbartole          #+#    #+#             */
/*   Updated: 2018/12/17 17:19:52 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		max4(int a, int b, int c, int d)
{
	if (a > b && a > c && a > d)
		return (a);
	if (b > c && b > d)
		return (b);
	return (c > d ? c : d);
}

static int		min4(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	if (b < c && b < d)
		return (b);
	return (c < d ? c : d);
}

static void		move(t_tet *t, int col, int shift)
{
	int	i;

	i = -1;
	while (++i < 4)
		t->data[2 * i + col] = t->data[2 * i + col] - shift;
}

t_tet			*improve_tet(t_tet *one, t_list **l)
{
	int	min;

	if ((min = min4(IT_IS_ROWS(one))))
		move(one, 0, min);
	if ((min = min4(IT_IS_COLS(one))))
		move(one, 1, min);
	one->w = max4(IT_IS_COLS(one)) + 1;
	one->h = max4(IT_IS_ROWS(one)) + 1;
	check_valid(one, l);
	if (one->data[0] + one->data[1] == 0)
		;
	else if (TET_1PART(one->data) && TET_2PART(one->data))
	{
		move(one, 1, one->w - 1);
		one->w = -one->w;
	}
	else
	{
		move(one, 0, one->h - 1);
		one->h = -one->h;
	}
	return (one);
}
