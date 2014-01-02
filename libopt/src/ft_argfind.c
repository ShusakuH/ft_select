/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:54:59 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/24 12:27:19 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libopt.h"

t_list_iter	*ft_argfind(t_list *lst, const char *name, t_list_iter * last_iter)
{
	t_list_iter	*i;

	i = ft_lstiternew(last_iter ? last_iter->start : lst);
	while (ft_lstitervalid(i))
	{
		if (ft_strequ(((t_argument*)i->head)->name, name))
			return (i);
		ft_lstiteradvance(i);
	}
	ft_lstiterdel(&i);
	return (NULL);
}
