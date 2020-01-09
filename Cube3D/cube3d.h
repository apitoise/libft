/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:02:50 by apitoise          #+#    #+#             */
/*   Updated: 2020/01/09 14:49:09 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "Libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>

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
	int			color;
}				t_data;

typedef	struct	s_algo
{
	int			x;
	double		posX;
	double		posY;
	double		dirX;
	double		oldDirX;
	double		dirY;
	double		oldDirY;
	double		planeX;
	double		oldPlaneX;
	double		planeY;
	double		oldPlaneY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		ms;
	double		rs;
	int			mapX;
	int			mapY;
	double		deltaDistX;
	double		deltaDistY;
	double		sideDistX;
	double		sideDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			first;
	int			drawEnd;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			echapkey;
}				t_algo;

typedef	struct	s_twostruct
{
	t_algo		*algo;
	t_data		*data;
}				t_twostruct;

int		worldMap[10][10];
void	w_key(t_algo *algo);
void	init_struct(t_algo *algo, t_data *data);
void	init_loop_algostruct(t_algo *algo, t_data *data);
int		ft_algo(t_algo *algo, t_data *data);
int		ft_keyparsing(int key, void *param);
int		main(void);
void	init_first(t_algo *algo);
void	ft_painting(t_data *data, t_algo *algo);
int		ft_move(t_algo *algo);
void	ft_ray(t_algo *algo, t_data *data);

#endif
