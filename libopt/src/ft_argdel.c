/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:52:44 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/24 12:27:26 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libopt.h"

void			ft_argdel(void *content, size_t size)
{
	t_argument	*arg;

	(void) size;
	if (content)
	{
		arg = (t_argument*)content;
		if (arg->name)
			ft_strdel(&arg->name);
		if (arg->value)
			ft_strdel(&arg->value);
		ft_memdel(&content);
	}
}
