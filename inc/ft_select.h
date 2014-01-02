/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:37:06 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 14:34:16 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

int		ft_init_terminal_data(char **term_buffer);

char	*ft_ask_terminal_string(char *name, char **term_buffer);
int		ft_ask_terminal_numeric(char *name);
int		ft_ask_terminal_flag(char *name);

#endif /* !FT_SELECT_H */
