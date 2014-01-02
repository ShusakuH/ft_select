/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:52:01 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/24 12:26:30 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libopt.h"

t_argument		*ft_argset(t_argument *arg, const char *name, const char *value,
						   t_flags type)
{
	if (!arg)
		return (NULL);
	if (arg->name)
		ft_strdel(&arg->name);
	if (arg->value)
		ft_strdel(&arg->value);
	arg->type = type;
	arg->name = ft_strdup(name);
	arg->value = ft_strdup(value);
	return (arg);
}
