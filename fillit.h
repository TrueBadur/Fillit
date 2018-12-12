/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:52:39 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/11 22:22:56 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetrimino
{
	char			data[8];
	char			w;
	char			h;
	unsigned char	l;
}				t_tet;

//int				put_er(int);
//void			pr_usage(void);
t_list		*read_figs(int fd);
void			workitbaby(t_vector *figs, char **board);
#endif
