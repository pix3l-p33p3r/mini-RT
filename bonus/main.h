/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 04:36:01 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/27 13:33:53 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "libft/libft.h"
# define MAXFLOAT 3.40282346638528859811704183484516925e+38F
# define M_PI 3.14159265358979323846
# define WIDTH 800
# define HEIGHT 600
# define EPSILON 0.0001f
# define BACKWARD 0
# define FORWARD 1

enum
{
	SPHERE = 1,
	PLANE = 2,
	CYLINDER = 3,
};

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_matrix
{
	int		rows;
	int		cols;
	float	**matrix;
}	t_matrix;

typedef struct s_ray
{
	t_vector	point1;
	t_vector	point2;
	t_vector	direction;
}	t_ray;

typedef struct s_camera
{
	t_vector	origin;
	t_vector	lookat;
	t_vector	up_vector;
	t_vector	cam_u;
	t_vector	cam_w;
	t_vector	cam_v;
	t_vector	screen_center;
	t_vector	screen_u;
	t_vector	screen_v;
	float		fov;
	float		aspect_ratio;
	float		focal_length;
	float		horizontal;
}	t_camera;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_image
{
	float	**red;
	float	**green;
	float	**blue;
}	t_image;

typedef struct s_info
{
	struct s_object	*e;
	t_vector		hitpoint;
	t_vector		normal;
}	t_info;

// parse 
typedef struct s_object
{
	int			type; // parse
	t_vector	translation; // parse
	t_vector	rotation;
	t_vector	scale; // parse
	t_vector	d_normal; // parse
	t_vector	base_color; // parse
	float		radius; // parse
	float		height; // parse
	int			has_material;
	float		reflectivity;
	float		shininess;
	t_matrix	**gtfm;
	int			(*hit)(t_ray *ray, struct s_info *info);
}	t_object;

typedef struct s_light
{
	t_vector	position;
	t_vector	color;
	float		intensity;
}	t_light;

typedef struct s_ambiant
{
	float		ratio;
	t_vector	color;
}	t_ambiant;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_camera		camera;
	t_image			*image;
	t_object		*objects;
	t_light			*lights;
	t_ambiant		*ambient;
	t_vector		*buffer_img;
	int				frames;
	unsigned int	rng_state;
	int				pos;
	int				len;
	int				pos1;
	int				len1;
}	t_vars;

typedef struct s_norm
{
	t_ray		back_ray;
	t_vector	ray_dir;
	t_vector	localpoi;
	float		t1;
	float		t2;
	float		b;
	float		c;
	float		delta;
}	t_norm;

typedef struct s_norm1
{
	int			x;
	int			y;
	float		xfact;
	float		yfact;
	t_ray		ray;
	t_vector	color;
	float		normx;
	float		normy;
	int			intfound;
	t_info		info;
	float		xoff;
	float		yoff;
}	t_norm1;

typedef struct s_norm2
{
	int		i;
	float	dist;
	float	mindist;
	int		validint;
	int		intfound;
	t_info	test;
}	t_norm2;

typedef struct s_norm3
{
	int		validint;
	int		i;
	t_info	test;
	float	dist;
}	t_norm3;

typedef struct s_norm4
{
	int			illumination;
	int			i;
	t_ray		light_ray;
	t_vector	lighdir;
	float		lighdist;
	int			validint;
}	t_norm4;

typedef struct s_norm5
{
	t_vector	diff_color;
	float		intensity;
	float		red;
	float		green;
	float		blue;
	int			i;
	int			valid_ilum;
}	t_norm5;

typedef struct s_norm6
{
	t_vector	spc_color;
	t_vector	lighdir;
	t_vector	r;
	t_vector	v;
	t_vector	start;
	t_ray		light_ray;
	float		intensity;
	float		prod;
	int			i;
	int			validint;
	float		red;
	float		green;
	float		blue;
}	t_norm6;

//raytrace_utils
unsigned int	rand_pcg(unsigned int *rng_state);
float			random_float(unsigned int *rng_state, float min, float max);
void			initialize_raytrace(t_vars *vars, t_norm1 *norm);
void			process_pixel(t_vars *vars, t_norm1 *norm);
void			raytrace(t_vars *vars);
t_matrix		*create_matrix(int rows, int cols);
int				loop(t_vars *vars);
int				test_intersection(t_ray *ray, t_object *objects, t_info *info);
//Vector
float			square(float a);
void			print_vec(t_vector a);
t_vector		new_vec(float x, float y, float z);
t_vector		sub_vec(t_vector a, t_vector b);
t_vector		add_vec(t_vector a, t_vector b);
t_vector		scale_vec(t_vector a, float t);
float			length2(t_vector a);
float			length(t_vector a);
t_vector		normalized(t_vector a);
float			dot_product(t_vector a, t_vector b);
t_vector		cross_product(t_vector a, t_vector b);
t_vector		reflect(t_vector d, t_vector normal);
t_vector		get_rotation_vector(t_vector normal);
//Matrix
void			fill_mt(t_matrix *mt, float *values);
float			*create_cols(int c);
t_matrix		*create_matrix(int rows, int cols);
float			determinant(t_matrix *mt);
float			cofactor(t_matrix *mt, int row, int column);
t_matrix		*inverse(t_matrix *mt);
void			set_to_indentity(t_matrix *mt);
void			print_matrix(t_matrix *matrix);
void			delete_matrix(t_matrix *_this);
void			copy_clmn(float *clm1, float *clm2, int column, int size);
t_matrix		*submatrix(t_matrix *mt, int row, int column);
float			minor(t_matrix *mt, int row, int column);
t_matrix		*mt_multiplication(t_matrix *mt1, t_matrix *mt2);
t_matrix		*safe_matrix_multy(t_matrix *mt1, t_matrix *mt2);

t_matrix		**set_transform(t_vector t, t_vector r, t_vector s);
t_ray			apply_transform(t_ray *ray, t_matrix **gtfm, int dirflag);
t_vector		apply_transform_vector(t_vector *input, t_matrix **gtfm,
					int dirflag);

// Transformation
t_matrix		*rotation_matrix_y(float angle);
t_matrix		*rotation_matrix_z(float angle);
t_matrix		*translation_matrix(t_vector *v);
t_matrix		*scaling_matrix(t_vector *v);
t_matrix		*rotation_matrix_x(float angle);

// camera setup
void			intialize_camera(t_camera *camera);
t_ray			generate_ray(float x, float y, t_camera *camera);
t_ray			new_ray(t_vector point1, t_vector point2);

// image setup
t_image			*new_image(void);
void			delete_image(t_image *image);
void			set_pixel(t_image *image, int x, int y, t_vector color);
t_data			*new_mlx_img(t_vars *vars);

// objects
void			raytrace(t_vars *vars);
void			render(t_vars *vars);
t_object		*init_objects(void);
int				test_sphere(t_ray *ray, t_info *info);
int				test_plane(t_ray *ray, t_info *info);
t_vector		diffuse(t_info *info, t_vars *vars);
t_light			*init_lights(void);
t_vector		compute_color(t_vars *vars, t_info *info, t_ray *camera_ray);
t_vector		specular_highlight(t_info *info, t_vars *vars,
					t_ray *camera_ray);
int				test_cylinder(t_ray *ray, t_info *info);
int				calculate_props(int min_index, t_vector *poi,
					t_info *info, t_vector *vhat);

void			calculate_light_intensity(t_info *info, t_vars *vars,
					t_ray *camera_ray, t_norm6 *norm);

#endif