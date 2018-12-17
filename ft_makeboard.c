/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:05:45 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/15 14:36:40 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_free_prev(t_board *b, int i)
{
	while (--i)
		free(b->data[i]);
	free(b->data);
	free(b);
	return (NULL);
}

t_board	*ft_makeboard(int fc)
{
	int		i;
	int		j;
	t_board *b;

	if (!(b = malloc(sizeof(t_board))))
		return (NULL);
	if (!(b->data = (char **)malloc(sizeof(char *) * fc)))
	{
		free(b);
		return (NULL);
	}
	i = -1;
	while (++i < fc)
	{
		if (!(b->data[i] = ft_strnew(fc)))
			return (ft_free_prev(b, i));
		j = -1;
		while (++j < fc)
			b->data[i][j] = '.';
	}
	b->w = fc;
	return (b);
}
