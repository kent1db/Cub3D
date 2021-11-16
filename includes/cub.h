/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:11:34 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 15:53:13 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../minilibx/mlx.h"

typedef struct	s_data
{
	void		*img;
	int			*addr;
	void		*img_b;
	int			*addr_b;
	void		*img_o[4];
	int			*addr_o[4];
	int			bits_per_pixel_o[4];
	int			line_length_o[4];
	int			endian_o[4];
	int			width_o[4];
	int			height_o[4];
	int			width_b;
	int			height_b;
	int			bits_per_pixel_b;
	int			line_length_b;
	int			endian_b;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			keycode;
}				t_data;

typedef struct	s_map
{
	int			x_res;
	int			y_res;
	int			width;
	int			height;
	char		*path_n;
	char		*path_s;
	char		*path_e;
	char		*path_w;
	char		*path_sprite;
	char		*path_sprite_b;
	int			f_rgb[3];
	char		**char_f_rgb;
	char		**char_c_rgb;
	int			c_rgb[3];
	char		**map;
	char		**map_check;
	int			checked;
	int			player_pos[2];
	char		player_orientation;
	double		*z_buf;
}				t_map;

typedef struct	s_txt
{
	int			width;
	int			height;
	void		*img_n;
	void		*img_s;
	void		*img_e;
	void		*img_w;
	int			*addr_p;
	int			*addr_n;
	int			*addr_s;
	int			*addr_e;
	int			*addr_w;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_txt;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	t_txt		*text;
}				t_window;

typedef struct	s_coord
{
	double		x;
	double		y;
	int			distance;
	char		type;
}				t_coord;

typedef struct	s_sprt
{
	double		sprite_x;
	double		sprite_y;
	int			width;
	int			height;
	int			texture;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img_b;
	int			*addr_b;
	int			bits_per_pixel_b;
	int			line_length_b;
	int			endian_b;
	int			width_b;
	int			height_b;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			u_div;
	int			v_div;
	double		v_move;
	int			v_move_screen;
	int			sprite_height;
	int			sprite_width;
	int			drawstart_y;
	int			drawend_y;
	int			drawstart_x;
	int			drawend_x;
	int			tex_x;
	int			tex_y;
	int			number_sprite;
	int			*sprite_order;
	double		*sprite_distance;
	t_coord		*sprite;
}				t_sprt;

typedef	struct	s_check
{
	int			a;
	int			i;
}				t_check;

typedef struct	s_bmp
{
	int			image_s;
	int			file_s;
	int			header_s;
	int			byte_s;
	int			b_planes;
	int			bytes_number;
}				t_bmp;

typedef	struct	s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		x_coordinate;
	double		dir_ray_x;
	double		dir_ray_y;
	double		w;
	double		h;
	int			map_x;
	int			map_y;
	double		dist_side_x;
	double		dist_side_y;
	double		dist_delta_x;
	double		dist_delta_y;
	double		dist_to_wall;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		frametime;
	double		movespeed;
	double		rotspeed;
	double		old_plane_x;
	double		old_dir_x;
	int			player[4];
	int			camera[2];
	int			maj;
	int			screen;
	t_map		*map_s;
	t_window	*win_s;
	t_data		*data_s;
	t_txt		*txt_s;
	t_sprt		*sprt_s;
}				t_ray;

int				ft_close(int bool);
void			ft_error(int errnum, t_map *map);
void			ft_free_struct(t_map *map);
void			ft_free_str(char *str);
void			ft_free_tab(char **strs);

void			ft_parse(int fd, t_map *map);
void			ft_parse_map(char *line, t_map *map);
void			ft_initialize_struct(char *line, t_map *map, int *countft);
int				ft_check_for_split(char *line);
int				ft_check_struct(t_map *map);

void			ft_fill_struct(t_map *map);
void			ft_set_resolution(char **tab, t_map *map);
int				ft_set_struct(char **tab, t_map *map, int ret);
void			ft_set_txt(char **tab, t_map *map, int txt);
void			ft_set_color(char **tab, t_map *map, char c);

void			ft_get_color_f(char **tab, t_map *map);
void			ft_get_color_c(char **tab, t_map *map);
void			ft_char_to_int(t_map *map, int bool);
void			ft_check_color(t_map *map, int bool);
void			ft_check_color_format(char *str, t_map *map);

int				ft_press(int keycode);
int				ft_strslen(char **strs);
char			**ft_strsjoin(char const *s1, char **tab);
char			**ft_strsdup(char **tab);
int				ft_str_search(char *str, char c);

int				ft_check_alpha(char *str);
int				ft_check_tab(char *str);
void			ft_check_map(t_map *map);
void			ft_flood_fill(int x, int y, t_map *map);

int				ft_check_open_e(t_map *map);
int				ft_check_open_n(t_map *map);
int				ft_check_open_s(t_map *map);
int				ft_check_open_w(t_map *map);
int				ft_check_open_sprite(t_map *map);
int				ft_check_open(t_map *map);

void			ft_init_struct(t_window *w, t_map *m, t_ray *r, t_data *d);
void			ft_orientation_dir(t_ray *ray, t_map *map);
void			ft_init_raycasting(t_ray *ray, t_map *map);
void			ft_init_variables(t_ray *ray, t_map *m, int x);
void			ft_init_step_side(t_ray *ray);

void			ft_vertline(int x, t_ray *ray, t_data *data);
void			ft_raycasting_loop(t_ray *r, t_map *m, t_data *d, t_sprt *s);
void			ft_calculate_draw_pixels(t_ray *ray, t_map *map);
void			ft_calculate_walldist(t_ray *ray, t_map *map);
void			ft_dda_algo(t_ray *ray, t_map *map);

void			ft_move_player(t_ray *ray);
void			ft_move_forward(t_ray *ray);
void			ft_move_back(t_ray *ray);
void			ft_move_right(t_ray *ray);
void			ft_move_left(t_ray *ray);

void			ft_move_camera(t_ray *ray);
void			ft_cam_right(t_ray *ray);
void			ft_cam_left(t_ray *ray);

int				ft_input_off(int keycode, t_ray *ray);
int				ft_input_on(int keycode, t_ray *ray);
int				ft_key(t_ray *ray);
int				ft_game(t_ray *ray);

void			ft_get_orientation_texture(t_ray *ray);

void			ft_init_mlx(t_window *w, t_map *m, t_data *d, t_sprt *sprt);
void			ft_resolution(t_map *map, t_window *win);

void			ft_texturing(t_ray *ray, t_map *map);

void			ft_init_sprite_struct(t_sprt *sprt, t_ray *ray, t_map *map);
void			ft_sort_sprite(t_coord *tab, int number);
t_coord			*ft_fill_struct_sprite(t_sprt *sprt, t_map *map, t_ray *ray);

void			ft_spriting(t_sprt *s, t_ray *r, t_map *m, t_data *data);
void			ft_print_s(t_sprt *s, t_map *map, t_data *data, int *addr);
void			ft_init_sprite_variables(t_sprt *s, t_ray *r, t_map *m);

void			ft_init_compass(t_ray *r, t_data *d);
void			ft_check_orientation(t_ray *ray, int *ret, int *x, int *y);
void			ft_shade_color(int *color, t_ray *ray);

void			ft_screen(t_ray *ray);
void			ft_set_path(int txt, t_map *map, char **tab);

#endif
