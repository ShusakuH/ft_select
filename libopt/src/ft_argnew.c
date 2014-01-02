/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:52:23 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/24 12:27:13 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libopt.h"

t_argument		*ft_argnew(const char *name, const char *value, t_flags type)
{
	t_argument	*arg;

	arg = ft_memalloc(sizeof(t_argument));
	arg->name = NULL;
	arg->value = NULL;
	ft_argset(arg, name, value, type);
	return (arg);
}
