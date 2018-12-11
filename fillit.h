/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:52:39 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/11 15:59:07 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetrimino
{
	char	**data;
	int		w;
	int		h;
}				t_tet;

void			pr_usage(void);
t_vector		read_figs(int fd);
void			workitbaby(t_vector *figs, char **board);
#endif
