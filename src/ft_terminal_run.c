/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:42:28 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 21:24:08 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include "ft_select.h"
#include <unistd.h>

static char	*ft_strjoin_int(char *str, char c)
{
	int		i;
	size_t	len;
	char	*r_str;

	i = 0;
	len = ft_strlen(str);
	r_str = ft_strnew(len);
	if (!str)
		return (NULL);
	ft_strncpy(r_str, str, len + 1);
	while (r_str[i] != '\0')
		i++;
	r_str[i] = c;
	r_str[++i] = '\0';
	return (r_str);
}

void	ft_terminal_run(t_term *term)
{
	t_arg	*elem;
	char	buff[4096];
	int		key;

	elem = term->arg_list->first;
	ft_write(term);
	ft_move_to(term, elem->position->x, elem->position->y);
	while (42)
	{
		ft_write_search(term);
		key = 0;
		read(STDIN_FILENO, &key, 4);
		if (ft_isalnum(key))
		{
			ft_move_to(term, ft_strlen(FT_SEARCH), 0);
			tputs(tgetstr(TC_CURSOR_DFL, NULL), 0, &ft_write_null);
			ft_fprintf(0, "%s", ft_strjoin_int(buff, (char)key));
		}
		else if (term->status)
			ft_check_keys(term, key);
		else if (key == FT_KEY_ESCAPE && !term->status)
			ft_key_quit(term);
		else
			ft_key_return(term);
	}
}

void	ft_write_search(t_term *term)
{
	ft_move_to(term, 0, 0);
	ft_fprintf(0, FT_SEARCH);
}
