/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:40:01 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 20:20:13 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

unsigned int	rgb_to_int(float red, float green, float blue)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	result;

	if (red > 1.0f)
		red = 1.0f;
	if (green > 1.0f)
		green = 1.0f;
	if (blue > 1.0f)
		blue = 1.0f;
	r = (red * 255.0f);
	g = (green * 255.0f);
	b = (blue * 255.0f);
	result = (r << 16) | (g << 8) | b;
	return (result);
}

void	my_mlx_put_pixel(t_data *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_length)
			+ (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

void	render(t_vars *vars)
{
	int				x;
	int				y;
	t_data			*data;
	unsigned int	final_color;

	data = new_mlx_img(vars);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			final_color = rgb_to_int(vars->image->red[y][x],
					vars->image->green[y][x], vars->image->blue[y][x]);
			my_mlx_put_pixel(data, x, y, final_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	mlx_destroy_image(vars->mlx, data->img);
}
