/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 16:19:00 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 20:27:51 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_string.h>
#include <libft_printf.h>
#include "ft_select.h"

void	ft_lst_init(t_list *list)
{
	list->first = NULL;
	list->last = NULL;
}

void	ft_lst_add_element(t_list *list, char *argvi)
{
	t_arg	*element;
	
	element = (t_arg *)malloc(sizeof(t_arg));
	if (!element)
		return ;
	element->content = argvi;
	element->content_size = ft_strlen(argvi);
	element->prev = list->last;
	element->next = NULL;
	if (list->last)
		list->last->next = element;
	else
		list->first = element;
	list->last = element;
}

void	ft_lst_print(t_list *list)
{
	t_arg	*element;

	element = list->first;
	while (element)
	{
		ft_printf("arg : %s\n", element->content);
		element = element->next;
	}
}
