/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <hchaguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:00:44 by hchaguer          #+#    #+#             */
/*   Updated: 2023/12/27 17:52:30 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_all_scenes(t_vars *var, char *line, int i)
{
	if (line[i] == '\0')
		free(line);
	else if (line[i] == 'A')
		check_ambient_lightning(var, line, i);
	else if (line[i] == 'C')
		check_camera(var, line, i);
	else if (line[i] == 'L')
		check_light(var, line, i);
	else if (ft_strlen(line) > 2 && ft_strncmp(line, "sp ", 3) == 0)
		check_sphere(var, line, i);
	else if (ft_strlen(line) > 2 && ft_strncmp(line, "pl ", 3) == 0)
		check_plane(var, line, i);
	else if (ft_strlen(line) > 2 && ft_strncmp(line, "cy ", 3) == 0)
		check_cylinder(var, line, i);
	else
	{
		printf("Error : unexpected behavior\n");
		exit(EXIT_FAILURE);
	}
}

void	check_ambient_lightning(t_vars *var, char *line, int i)
{
	t_ambiant	*ambient;

	i++;
	ambient = ft_calloc(1, sizeof(t_ambiant));
	ambient->ratio = parse_number(line, &i);
	check_numbers(ambient->ratio, 0.0, 1.0);
	ambient->color = parse_vector(line, &i);
	check_numbers(ambient->color.x, 0, 255);
	check_numbers(ambient->color.y, 0, 255);
	check_numbers(ambient->color.z, 0, 255);
	if (line[i])
		unexpected_error(line, i);
	ambient->color = scale_vec(ambient->color, 1.0f / 255.0f);
	ambient->color = scale_vec(ambient->color, 1.0f / 255.0f);
	ambient->color = scale_vec(ambient->color, ambient->ratio);
	var->ambient = ambient;
	free(line);
}

void	check_camera_continue(t_camera *cam)
{
	cam->cam_w = normalized(sub_vec(cam->lookat, cam->origin));
	cam->cam_u = normalized(cross_product(cam->cam_w, cam->up_vector));
	cam->cam_v = normalized(cross_product(cam->cam_u, cam->cam_w));
	cam->screen_center = add_vec(cam->origin,
			scale_vec(cam->cam_w, cam->focal_length));
	cam->screen_u = scale_vec(cam->cam_u, cam->horizontal);
	cam->screen_v = scale_vec(cam->cam_v, cam->horizontal / cam->aspect_ratio);
}

void	check_camera(t_vars *var, char *line, int i)
{
	float		rad;
	t_camera	*cam;

	i++;
	cam = &var->camera;
	cam->origin = parse_vector(line, &i);
	cam->lookat = parse_vector(line, &i);
	cam->up_vector = (t_vector){0, 0, 1};
	cam->focal_length = 1;
	check_numbers(cam->lookat.x, -1, 1);
	check_numbers(cam->lookat.y, -1, 1);
	check_numbers(cam->lookat.z, -1, 1);
	cam->fov = parse_number(line, &i);
	check_numbers(cam->fov, 0, 180);
	rad = cam->fov * M_PI / 180.0f;
	cam->horizontal = 2 * cam->focal_length * tanf(rad / 2);
	cam->aspect_ratio = (float)WIDTH / (float)HEIGHT;
	check_camera_continue(cam);
	if (line[i])
		unexpected_error(line, i);
	free(line);
}

void	check_light(t_vars *var, char *line, int i)
{
	t_light	light;
	t_light	*tmp;

	i++;
	light.position = parse_vector(line, &i);
	light.intensity = parse_number(line, &i);
	light.color = parse_vector(line, &i);
	check_numbers(light.intensity, 0.0, 1.0);
	check_numbers(light.color.x, 0, 255);
	check_numbers(light.color.y, 0, 255);
	check_numbers(light.color.z, 0, 255);
	light.color = scale_vec(light.color, 1.0f / 255.0f);
	if (line[i])
		unexpected_error(line, i);
	var->lights[var->pos1++] = light;
	if (var->pos1 + 1 == var->len1)
	{
		tmp = ft_calloc(var->len1 * 2 + 1, sizeof(t_light));
		ft_memcpy(tmp, var->lights, var->len1 * sizeof(t_light));
		free(var->lights);
		var->lights = tmp;
		var->len1 = var->len1 * 2;
	}
	free(line);
}
