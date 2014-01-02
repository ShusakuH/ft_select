/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:53:08 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/24 12:23:10 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libopt.h"

t_argument		*ft_argadd(t_list **lst, const char *name, const char *value,
						   t_flags type)
{
	t_argument	*new;

	new = ft_argnew(name, value, type);
	if (!new)
		return (new);
	ft_lstadd(lst, ft_lstnew(new, sizeof(t_argument)));
	return (new);
}
