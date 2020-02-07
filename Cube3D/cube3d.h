/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:02:50 by apitoise          #+#    #+#             */
/*   Updated: 2020/02/04 16:39:13 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "Libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct 	s_img
{
	void 	*ptr;
	int 	*data;
	int 	bpp;
	int 	size;
	int 	endian;
}				t_img;

typedef struct	s_tex
{
	void		*teximg;
	int 		*data;
	int			bpp;
	int 		w;
	int 		h;
	int			size_line;
	int			endian;
	double		step;
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
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		oldDirX;
	double		oldDirY;
	double		rayPosX;
	double		rayPosY;
	double		planeX;
	double		planeY;
	double		oldPlaneX;
	double		oldPlaneY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		deltaDistX;
	double		deltaDistY;
	double		sideDistX;
	double		sideDistY;
	double		perpWallDist;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			rot_right;
	int			rot_left;
	double		ms;
	int 		texX[4];
	int 		texY[4];
	int 		wallX;
	double		rs;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}				t_algo;

typedef struct	s_map
{
	int			first;
	int			width;
	int			height;
	char		*charmap;
	int			**map;
	int			lenerror;
	int			spawn;
	int			error;
}				t_map;

typedef	struct	s_allstruct
{
	t_algo		algo;
	t_data		data;
	t_tex		tex[4];
	t_map		map;
	t_img		img;
}				t_allstruct;

int		check_arguments(int ac, char **av, t_allstruct *all);
void	init_struct(t_allstruct *all);
void	init_loop_algostruct(t_allstruct *all);
void	init_datastruct(t_data *data);
int		ft_keyparsing(int key, t_allstruct *all);
int		ft_keyrelease(int key, t_allstruct *all);
int		ft_close(void);
int		main(int ac, char **av);
void	init_first(t_algo *algo);
void	ft_raycasting(t_allstruct *all);
void	init_res(char *str, t_allstruct *all);
void	init_tex(char c, char *str, t_allstruct *all);
void	init_colors(char c, char *str, t_allstruct *all);
void	init_mapstruct(t_allstruct *all);
void	ft_painting(t_allstruct *all);
int		ft_move(t_allstruct *all);
char	*ft_gnlstrdup(const char *s1);
size_t	ft_gnlstrlen(char *str);
char	*ft_gnlstrchr(const char *str, int c);
int		get_next_line(int fd, char **line);
void	get_tex(t_allstruct *all);
void	get_map(char *line, t_allstruct *all);
int		create_map(t_allstruct *all);
int		ft_error(char *str, t_allstruct *all);
void	get_spawn(int mapnb, int x, int y, t_allstruct *all);
int		check_map(t_allstruct *all);
void	ft_voiderror(char *str);
char	*ft_gnlsubstr(char const *s, unsigned int start, size_t len);
char	*ft_gnlstrjoin(char const *s1, char const *s2);

#endif