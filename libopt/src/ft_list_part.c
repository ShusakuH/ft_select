/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:50:22 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 12:13:04 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_iter.h"

t_bool	ft_lstitervalid(t_list_iter *it)
{
	return (it && it->head != it->end);
}

t_bool	ft_lstiteradvance(t_list_iter *it)
{
	if (ft_lstitervalid(it))
	{
		it->head = it->head->next;
		return (TRUE);
	}
	return (FALSE);
}

