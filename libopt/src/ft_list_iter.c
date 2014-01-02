/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:50:22 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 12:20:13 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_iter.h"

void			ft_lstiterset(t_list_iter *iter, t_list *list)
{
	if (!iter)
		return ;
	iter->head = list;
	iter->start = list;
	iter->end = list;
	while (iter && iter->end)
	{
		if (!iter->end->next)
			break ;
		iter->end = iter->end->next;
	}
}

t_list_iter		*ft_lstiternew(t_list *list)
{
	t_list_iter	*iter;

	iter = ft_memalloc(sizeof(t_list_iter));
	if (!iter)
		return (NULL);
	ft_lstiterset(iter, list);
	return (iter);
}

void			ft_lstiterdel(t_list_iter **lst)
{
	if (lst && *lst)
		ft_memdel((void**)lst);
}

t_list			*ft_lstbegin(t_list *l)
{
	return (l ? l->next : NULL);
}

t_list			*ft_lstend(t_list *lst)
{
	t_list	*p;

	p = lst;
	while (p)
	{
		if (p->next)
			return (p);
		p = p->next;
	}
	return (p);
}

