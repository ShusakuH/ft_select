/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:37:06 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/02 20:42:07 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define TC_CLEAR "cl"

typedef struct	s_arg
{
	char			*content;
	int				content_size;
	struct s_arg	*next;
	struct s_arg	*prev;
}				t_arg;

typedef	struct	s_list
{
	t_arg	*first;
	t_arg	*last;
}				t_list;

typedef struct	s_term
{
	char	*term_buffer;
	int		max_cols;
	int		max_rows;
	t_list	*arg_list;
	int		arg_count;
}				t_term;

int		ft_init_terminal_data(t_term *term);
void	ft_terminal_raw_mode(void);
void	ft_terminal_parse_args(t_term *term, char *argv[]);
void	ft_terminal_exit(int status);
void	ft_terminal_restore(void);
void	ft_terminal_error(char *error_str);
void	ft_terminal_run(t_term *term);

int		ft_write_null(int nb);
void	ft_write_clear(void);

void	ft_signal(void);
void	ft_signal_kill(int sigint);
void	ft_signal_write(int sigint);

void	ft_lst_init(t_list *list);
void	ft_lst_add_element(t_list *list, char *argvi);
void	ft_lst_print(t_list *list);

#endif /* !FT_SELECT_H */
