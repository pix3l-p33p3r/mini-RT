/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 04:36:04 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/27 13:28:05 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libft/libft.h"
#include "parsing/miniRT.h"

int	loop(t_vars *vars)
{
	if (vars->frames == 1337)
		return (0);
	raytrace(vars);
	render(vars);
	return (0);
}

int	key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (keycode);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2 || check_extention(av[1]) == 1)
		return (1);
	vars.pos = 0;
	vars.len = 100;
	vars.objects = ft_calloc(vars.len + 1, sizeof(t_object));
	vars.pos1 = 0;
	vars.len1 = 100;
	vars.lights = ft_calloc(vars.len1 + 1, sizeof(t_light));
	check_element(av[1]);
	read_scenes(av[1], &vars);
	vars.image = new_image();
	vars.buffer_img = calloc(WIDTH * HEIGHT, sizeof(t_vector));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Raytracer");
	vars.frames = 0;
	mlx_loop_hook(vars.mlx, loop, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, (void *)exit, &vars);
	mlx_loop(vars.mlx);
	free(vars.objects);
	return (0);
}
