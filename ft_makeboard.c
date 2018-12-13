/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:05:45 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/13 15:16:31 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board	*ft_makeboard(int fc)
{
	int		t;
	int		i;
	int		j;
	t_board *b;

	t = ft_sqrt(fc);
	t = (t * t == fc) ? t : t + 1;
	if (!(b = malloc(sizeof(t_board))))
		return (NULL);
	if (!(b->data = (char **)malloc(sizeof(char *) * t)))
	{
		free(b);
		return (NULL);
	}
	i = -1;
	while (++i < t)
	{
		if (!(b->data[i] = ft_strnew(t)))
		{
			while (--i)
				free(b->data[i]);
			free(b->data);
			free(b);
			return (NULL);
		}
		j = -1;
		while (++j < t)
			b->data[i][j] = '.';
	}
	b->w = t;
	return (b);
}
