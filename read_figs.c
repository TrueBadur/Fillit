/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:20:41 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/17 18:08:54 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				put_er(int ret, t_list **l, t_tet *tet)
{
	ft_lstdel(l, NULL);
	free(tet);
	ft_putendl("error");
	return (ret);
}

static t_tet	*lines_to_tet(char **lines, t_tet *one, t_list **l, int k)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (lines[i][j] == '#' && k <= 6 && (one->data[k++] = i) > -1)
				one->data[k++] = j;
			else if (lines[i][j] != '.')
			{
				while (i < 4)
					free(lines[i++]);
				free(lines);
				exit(put_er(0, l, one));
			}
		}
		free(lines[i]);
	}
	free(lines);
	if (k != 8)
		exit(put_er(0, l, one));
	return (improve_tet(one, l));
}

static t_tet	*get_one(int fd, char c, t_list **l)
{
	char	**lines;
	char	*gnl;
	int		i;
	int		r;
	t_tet	*one;

	lines = (char **)malloc(sizeof(char *) * 4);
	i = -1;
	while (++i < 4 && (r = get_next_line(fd, &gnl)) == 1)
	{
		lines[i] = gnl;
		if (ft_strlen(lines[i]) != 4)
			break ;
	}
	if (i != 4)
	{
		while (i > -1)
			free(lines[i--]);
		free(lines);
		exit(put_er(0, l, NULL));
	}
	one = (t_tet *)malloc(sizeof(t_tet));
	one->l = c;
	return (lines_to_tet(lines, one, l, 0));
}

t_list			*read_figs(int fd, int *b_size)
{
	int		i;
	char	*line;
	t_list	*l;
	t_tet	*one;

	l = NULL;
	i = -1;
	while ((one = get_one(fd, 'A' + ++i, &l)))
	{
		ft_lstaddlast(&l, ft_lstnew(one, sizeof(t_tet)));
		free(one);
		if (!get_next_line(fd, &line))
			break ;
		if (ft_strcmp(line, ""))
		{
			free(line);
			exit(put_er(0, &l, NULL));
		}
		free(line);
	}
	if ((*b_size = i + 1) > 26)
		exit(put_er(0, &l, NULL));
	return (l);
}
