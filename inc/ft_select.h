/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 12:37:06 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/03 21:11:46 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft_config.h>

# define FT_NAME "ft_select"
# define FT_TERM "TERM"
# define FT_CELL_MASK "%s%s%s%s%s"
# define FT_ERROR_MASK "%s: %s: %s\n"
# define FT_ERROR_DESC "error"

# define FT_WRITE_ERROR "Display area is too small."
# define FT_TERMT_ERROR "You mus specify the terminal type"
# define FT_TERMC_ERROR "Cannot access termcap database"
# define FT_TERMI_ERROR "Terminal type is not defined"

# define FT_MARGIN 2
# define TC_CLEAR "cl"
# define TC_COLUM "col"
# define TC_LINES "li"
# define TC_CURSOR_MOVE "cm"
# define TC_S_UNDERLINE "us"
# define TC_E_UNDERLINE "ue"
# define TC_S_INVERSE "so"
# define TC_E_INVERSE "se"

# define FT_KEY_LEFT 4479771
# define FT_KEY_UP 4283163
# define FT_KEY_RIGHT 4414235
# define FT_KEY_DOWN 4348699
# define FT_KEY_SPACE ((int) ' ')
# define FT_KEY_RETURN ((int) '\n')
# define FT_KEY_DELETE 2117294875
# define FT_KEY_BACKSPACE 127

typedef struct	s_coordinates
{
	int	x;
	int	y;
}		t_coordinates;

typedef t_coordinates	t_position;
typedef t_coordinates	t_cursor;

typedef struct	s_arg
{
	char			*content;
	int				content_size;
	t_position		*position;
	t_bool			selected;
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
	t_bool		status;
	char		*term_buffer;
	int			max_cols;
	int			max_rows;
	int			rows;
	t_list		*arg_list;
	int			arg_count;
	t_arg		*cur_arg;
	int			cell_len;
	int			col;
	int			row;
	t_cursor	*cursor;
}				t_term;

typedef void	(*fkey)(t_term *);

typedef struct	s_key
{
	int		key;
	fkey	fkey;
}				t_key;

int		ft_init_terminal_data(t_term *term);
void	ft_terminal_raw_mode(void);
void	ft_terminal_parse_args(t_term *term, char *argv[]);
void	ft_terminal_exit(int status);
void	ft_terminal_restore(void);
void	ft_terminal_error(char *error_str);
void	ft_terminal_run(t_term *term);

void	ft_write(t_term *term);
void	ft_write_args(t_term *term);
void	ft_write_arg(t_term *term, t_arg *arg);
void	ft_write_prepare(t_term *term);
int		ft_write_null(int nb);
void	ft_write_clear(void);

void	ft_move(t_term *term, int x, int y);
void	ft_move_to(t_term *term, int x, int y);
void	ft_move_current(t_term *term);

void	ft_check_keys(t_term *term, int key);
void	ft_key_return(t_term *term);
void	ft_key_default(t_term *term);
void	ft_key_delete(t_term *term);
void	ft_key_down(t_term *term);
void	ft_key_up(t_term *term);
void	ft_key_left(t_term *term);
void	ft_key_right(t_term *term);
void	ft_key_space(t_term *term);

char	*ft_s_underline(t_bool selected);
char	*ft_e_underline(t_bool selected);
char	*ft_s_inverse(t_bool selected);
char	*ft_e_inverse(t_bool selected);

void	ft_signal(void);
void	ft_signal_kill(int sigint);
void	ft_signal_write(int sigint);

void	ft_lst_init(t_list *list);
void	ft_lst_add_element(t_list *list, char *argvi);
void	ft_lst_print(t_list *list);

#endif /* !FT_SELECT_H */
