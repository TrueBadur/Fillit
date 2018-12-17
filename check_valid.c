/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:39:46 by mbartole          #+#    #+#             */
/*   Updated: 2018/12/14 05:11:12 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_vert(t_tet *t, int v, int g, t_list **l)
{
	int	i;
	int	j;
	int	k;
	int	fl;

	i = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < i)
			if (t->data[2 * i + g] - t->data[2 * j + g] == 2 &&
					t->data[2 * i + v] == t->data[2 * j + v])
			{
				k = j - 1;
				fl = 1;
				while (++k < i)
					if (t->data[2 * k + g] == 1 &&
							t->data[2 * k + v] == t->data[2 * i + v])
						fl = 0;
				if (fl)
					exit(put_er(0, l));
			}
	}
}

void	check_valid(t_tet *t, t_list **l)
{
	if (t->h * t->w > 6)
		exit(put_er(0, l));
	if (t->h * t->w < 6)
		return ;
	check_vert(t, 1, 0, l);
	check_vert(t, 0, 1, l);
}
