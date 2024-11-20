/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:13:28 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/20 01:42:15 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "LIB/libft/libft.h"
# include "LIB/printf/ft_printf.h"
# include "LIB/gnl/get_next_line.h"
# include <fcntl.h>
#include "LIB/MacroLibX/includes/mlx.h"
#include "SDL2/SDL_scancode.h"
#include <unistd.h>
#include "stdlib.h"
#include <time.h>

typedef struct s_start
{
	int	x;
	int	y;
}	t_start;

typedef struct s_end
{
	int	x;
	int	y;
}	t_end;

typedef struct s_player
{
	int	x;
	int	y;
	void *sprite[12];
}	t_player;

typedef struct s_stack
{
	int	x;
	int	y;
}	t_stack;

typedef struct s_rhino
{
	int	x;
	int	y;
}	t_rhino;

typedef struct s_data
{
	int			nb_items;
	t_end		e;
	t_player	p;
	t_start		s;
	t_rhino		r;
	char		**map;
	int			max_x;
	int			max_y;
	int			items_picked;
	unsigned int repeat;
	void *mlx;
	void *win;
	void *background;
	void *walls;
	void *items;
	void *exit;
	void *rhino;
	char pressed[SDL_NUM_SCANCODES];
	void *numbers[10];
	unsigned int			nb_moove;
	void *player[2];
}	t_data;

int		check_data(t_data *data);
int		find_exit(t_data *data);
int		check_format(char **tab);
int		find_start(t_data *data);
void	getdata(t_data *data, char **tab);
int		nb_items(t_data *data);
char	**get_map(int fd);
void	*free_lst(t_list *lst);
int		nb_line_fd(int fd, t_list *lst);
int		main(int ac, char **av);
int		free_map(char **map);
int		get_parsed_map(char **tab, t_data *data);
int		nb_line(char **tab);
int		tab_len(char **tab);
int		get_x_items(char **tab, char c);
int		get_y_items(char **tab, char c);
int		send_error_message(t_data *data);
int		flood_fill(t_data *data);
void    start_game(t_data *data);
void	fill_data(t_data *data);
void 	put_exit(t_data *data);
void 	put_rhino(t_data *data);
void 	put_walls_items(t_data *data);
void 	put_background(t_data *data);
void	destroy_all(t_data *data);
void	destroy_first(t_data *data);
void	put_exit(t_data *data);
void	put_player(t_data *data, void *img);
void	put_items(t_data *data);
void	put_walls(t_data *data);
void	put_background(t_data *data);
void	up_pressed(t_data *data);
void	down_pressed(t_data *data);
void	right_pressed(t_data *data);
void	left_pressed(t_data *data);
void	esc_pressed(t_data *data);
int		check_update(void *d);
void	replace_in_tab(t_data *data, int x, int y, char c);
void	replace_w_img(t_data *data, int x, int y, void *img);
void	create_map(t_data *data);
int 	key_hook(int key, void* d);
int 	key_hook_up(int key, void* d);
int 	windows_hook(int event, void* param);
void	put_nb_moove(t_data *data);
int		print_number(t_data *data, int nb, int x);
void	make_action(t_data *data, unsigned int old_nb_moove);
void	put_nb_moove(t_data *data);
void    check_for_rhino(t_data *data);
void	moov_rhino(t_data *data);
int		moov_rhino_left(t_data *data);
int		moov_rhino_right(t_data *data);
int		moov_rhino_up(t_data *data);
int		moov_rhino_down(t_data *data);


#endif