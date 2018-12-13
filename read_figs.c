/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:20:41 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/13 14:54:29 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		put_er(int ret)
{
//	if (l)                     TODO delete list
//		ft_vecdel(v);
	ft_putendl("error");
	return (ret);
}

static t_tet	*lines_to_tet(char **lines, t_tet *one)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (lines[i][j] == '#')
			{
				one->data[k++] = i;  //TODO dangerous
				one->data[k++] = j;  //TODO dangerous
			}
			else if (lines[i][j] != '.')
				exit(put_er(0));
		}
	}
	if (k != 8)
		exit(put_er(0));
	return (improve_tet(one));
}

static t_tet	*get_one(int fd, char c)
{
	char	**lines;
	int		i;
	int		r;
	t_tet	*one;

	lines = (char **)malloc(sizeof(char *) * 4);      //TODO free somewhere
	i = -1;
	while (++i < 4 && (r = get_next_line(fd, &lines[i])) == 1)
	{
		if (ft_strlen(lines[i]) != 4)
			exit(put_er(0));
	}
	if (i != 4)
		exit(put_er(0));
	one = (t_tet *)malloc(sizeof(t_tet));   //TODO free somewhere
	one->l = c;
	return (lines_to_tet(lines, one));
}

t_list			*read_figs(int fd)
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
			exit(put_er(0));
	}
	return (l);
}
