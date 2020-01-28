/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:02:50 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/23 14:27:09 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "Libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# define WINX 1920
# define WINY 1080

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
	int 		rot_right;
	int 		rot_left;
	double		ms;
	double		rs;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}				t_algo;

typedef	struct	s_twostruct
{
	t_algo		algo;
	t_data		data;
}				t_twostruct;

int		worldMap[24][24];
int 	check_arguments(int ac, char **av);
void	init_struct(t_algo *algo, t_data *data);
void	init_loop_algostruct(t_algo *algo);
void	init_datastruct(t_data *data);
int		ft_keyparsing(int key, t_twostruct *ts);
int		ft_keyrelease(int key, t_twostruct *ts);
int 	ft_close(int key, t_twostruct *ts);
int		main(int ac, char **av);
void	init_first(t_algo *algo);
void	ft_raycasting(t_algo *algo, t_data *data);
void	ft_painting(t_algo *algo, t_data *data);
int		ft_move(t_twostruct *ts);

#endif
