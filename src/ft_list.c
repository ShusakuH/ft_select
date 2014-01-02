/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 16:19:00 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 17:09:38 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_string.h>
#include <libft_printf.h>
#include "ft_select.h"

void	ft_lst_add_element(t_arg **arg, char *argvi)
{
	t_arg	*element;
	
	element = (t_arg *)malloc(sizeof(t_arg));
	if (!element)
		return ;
	element->content = argvi;
	element->content_size = ft_strlen(argvi);
	element->next = *arg;
	*arg = element;
}

void	ft_lst_print(t_arg *arg)
{
	t_arg	*element;

	element = arg;
	while (element)
	{
		ft_printf("arg : %s\n", element->content);
		element = element->next;
	}
}
