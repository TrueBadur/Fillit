/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:20:41 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/12 13:50:55 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		max3(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	if (b > c && b > a)
		return (b);
	return (c);
}

char	need_to_move(t_tet *t, int y)
{
	return (t->data[y] * t->data[2 + y] * t->data[4 + y] * t->data[6 + y]);
}

void	move(t_tet *t, int y)
{
	int	i;

	while (need_to_move(t, y))
	{
		i = -1;
		while (++i < 4)
			t->data[2 * i + y] = t->data[2 * i + y] - 1;
	}
}

int		put_er(int ret)
{
//	if (l)                     TODO delete list
//		ft_vecdel(v);
	ft_putendl("error");
	return (ret);
}

t_tet		*improve(t_tet *one)
{
	move(one, 0);
	move(one, 1);
	if (one->data[0] + one->data[1] == 0)
	{
		one->w = max3(one->data[2], one->data[4], one->data[6]) + 1;
		one->h = max3(one->data[3], one->data[5], one->data[7]) + 1;
	}
	return (one);
}

t_tet		*lines_to_tet(char **lines, char c)
{
	t_tet	*one;
	int		i;
	int		j;
	int		k;

	one = (t_tet *)malloc(sizeof(t_tet));   //TODO free somewhere
	one->l = c;
	k = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (lines[i][j] == '#')
			{
				one->data[k++] = j;
				one->data[k++] = i;
			}
			else if (lines[i][j] != '.')
				exit(put_er(0));
		}

	}
	if (k != 8)
		exit(put_er(0));
	return (improve(one));
}	

t_tet		*get_one(int fd, char c)
{
	char	**lines;
	int		i;
	int		r;

	lines = (char **)malloc(sizeof(char *) * 4);      //TODO free somewhere
	i = -1;
	while (++i < 4 && (r = get_next_line(fd, &lines[i])) == 1)
	{
		if (ft_strlen(lines[i]) != 4)
			exit(put_er(0));
	}
	if (i != 4)
		exit(put_er(0));
	return (lines_to_tet(lines, c));
}

t_list *read_figs(int fd)
{
	int		i;
	char	*line;
	t_list	*l;
	t_tet	*one;

	l = NULL;
	i = -1;
	while ((one = get_one(fd, 'A' + ++i)))
	{
		ft_lstaddlast(&l, ft_lstnew(one, sizeof(t_tet)));
		if (!get_next_line(fd, &line))
			break ;
		if (ft_strcmp(line, ""))
			exit (put_er(0));
	}
	return (l);
}
