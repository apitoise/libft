/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:02:50 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/15 16:12:04 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../Libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct	s_sprt
{
	void		*ptr;
	void		*sprtimg;
	int			*data;
	int			bpp;
	int			w;
	int			h;
	int			posx;
	int			posy;
	int			size_line;
	int			endian;
	double		distance;
}				t_sprt;

typedef struct	s_tex
{
	void		*teximg;
	int			*data;
	int			bpp;
	int			w;
	int			h;
	int			size_line;
	int			endian;
	char		*name;
}				t_tex;

typedef	struct	s_data
{
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data_ptr;
	int			bits;
	int			size_line;
	int			endian;
	int			wall_color;
	int			sky_color;
	int			floor_color;
}				t_data;

typedef	struct	s_algo
{
	int			x;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		olddirx;
	double		olddiry;
	double		ray_px;
	double		ray_py;
	double		planex;
	double		planey;
	double		oldplanex;
	double		oldplaney;
	double		cam_x;
	double		ray_dx;
	double		ray_dy;
	int			mapx;
	int			mapy;
	double		delta_dx;
	double		delta_dy;
	double		side_dx;
	double		side_dy;
	double		wall_dist;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			rot_right;
	int			rot_left;
	double		ms;
	int			tex_x[4];
	int			tex_y[4];
	double		wall_x;
	double		rs;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			d_start;
	int			d_end;
	double		s_x;
	double		s_y;
	double		inv;
	double		trans_x;
	double		trans_y;
	int			screen_x;
	int			s_h;
	int			start_y;
	int			start_x;
	int			end_x;
	int			end_y;
	int			s_w;
	int			stripe;
	int			s_tex_y;
	int			s_tex_x;
	double		*zbuff;
}				t_algo;

typedef struct	s_map
{
	int			argt;
	int			argr;
	int			argno;
	int			argso;
	int			args;
	int			argw;
	int			arge;
	int			argf;
	int			argc;
	int			argm;
	int			first;
	int			width;
	int			height;
	char		*charmap;
	int			**map;
	int			lenerror;
	int			spawn;
	int			nb_sprt;
	char		*sprtname;
	int			error;
	int			d;
	int			line;
}				t_map;

typedef	struct	s_allstruct
{
	t_algo		algo;
	t_data		data;
	t_tex		tex[4];
	t_map		map;
	t_img		img;
	t_sprt		*sprt;
	int			texerror;
	int			sprterror;
}				t_allstruct;

int				check_arguments(int ac, char **av, t_allstruct *all);
void			init_struct(t_allstruct *all);
void			init_loop_algostruct(t_allstruct *all);
void			init_datastruct(t_data *data);
int				ft_keyparsing(int key, t_allstruct *all);
int				ft_keyrelease(int key, t_allstruct *all);
int				ft_close(t_allstruct *all);
int				main(int ac, char **av);
void			init_first(t_algo *algo);
void			draw_floor(t_allstruct *all);
void			draw_sky(t_allstruct *all);
void			draw_sprites(t_allstruct *all);
void			ft_raycasting(t_allstruct *all);
void			init_res(char *str, t_allstruct *all);
void			init_tex(char c, char *str, t_allstruct *all);
void			init_sprite(char *str, t_allstruct *all);
void			init_colors(char c, char *str, t_allstruct *all);
void			init_mapstruct(t_allstruct *all);
void			ft_painting(t_allstruct *all);
int				ft_move(t_allstruct *all);
char			*ft_gnlstrdup(const char *s1);
size_t			ft_gnlstrlen(char *str);
char			*ft_gnlstrchr(const char *str, int c);
int				get_next_line(int fd, char **line);
void			get_tex(t_allstruct *all);
void			get_sprite(t_allstruct *all);
void			get_xpm_name(char *str, int crd, t_allstruct *all);
void			get_map(char *line, t_allstruct *all);
int				create_map(t_allstruct *all);
int				ft_error(char *str, t_allstruct *all);
int				ft_free(t_allstruct *all);
int				find_error(t_allstruct *all);
void			get_spawn(int mapnb, int x, int y, t_allstruct *all);
int				check_map(t_allstruct *all);
char			*ft_gnlsubstr(char const *s, unsigned int start, size_t len);
char			*ft_gnlstrjoin(char const *s1, char const *s2);
int				create_bmp(char *file, t_allstruct *all);
void			write_half_int(int fd, int nb);
void			write_int(int fd, int nb);
void			write_color(int fd, int color);
void			write_empty(int fd, int nb);

#endif
