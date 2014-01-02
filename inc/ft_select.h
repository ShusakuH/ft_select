/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:37:06 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 17:07:27 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

typedef struct	s_arg
{
	char			*content;
	int				content_size;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_term
{
	char	*term_buffer;
	int		max_cols;
	int		max_rows;
	t_arg	*arg_list;
	int		arg_count;
}				t_term;

int		ft_init_terminal_data(t_term *term);
void	ft_terminal_raw_mode(void);
void	ft_terminal_parse_args(t_term *term, char *argv[]);
void	ft_terminal_exit(int status);
void	ft_terminal_restore(void);
void	ft_terminal_error(char *error_str);

void	ft_lst_add_element(t_arg **arg, char *argvi);
void	ft_lst_print(t_arg *arg);

#endif /* !FT_SELECT_H */
