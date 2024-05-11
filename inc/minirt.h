/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:15:05 by caalbert          #+#    #+#             */
/*   Updated: 2024/01/21 16:46:15 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../lib/libft/libft.h"

# define PI				3.14159265358979323846
# define PI_2			1.57079632679489661923
# define RADIANS 		0.017453
# define EPSILON		0.00001
# define OBJ_MAX		256
# define SIZE			16
# define MAX			4
# define TRUE			1
# define FALSE			0
# define FAILURE		1
# define SUCCESS		0
# define WIN_W 			800
# define WIN_H 			600
# define RGB_MAX 		255
# define FOV_MAX 		180
# define FOV_MIN 		0
# define DECIMAL_MAX 	1
# define DECIMAL_MIN 	0
# define ASCII_SET 		48
# define WIN_TITLE		"MiniRT - By caalbert & bluiz-al | 42SP"
# define ERROR_PARAM	"Parameter error on line %d \n"
# define TOKEN_ALIGHT	"   ,, "
# define TOKEN_CAMERA	"  ,, ,,  "
# define TOKEN_PLIGHT	"  ,,  ,, "
# define TOKEN_SPHERE	"  ,,  ,, "
# define TOKEN_PLANE	"  ,, ,, ,, "
# define TOKEN_CYLIN	"  ,, ,,   ,, "
# define TOKEN_CONE		"  ,, ,,   ,, "

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_uple;

typedef struct s_material	t_material;
typedef struct s_object		t_object;

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
	int		color_int;
}	t_color;

typedef struct s_checker
{
	double	width;
	double	height;
	t_color	color_a;
	t_color	color_b;
}	t_checker;

typedef struct s_discr
{
	double	discriminant;
	double	t;
}	t_discr;

typedef struct s_shear
{
	double	prop1;
	double	prop2;
}	t_shear;

typedef struct s_mtx
{
	double	matrix[MAX][MAX];
	int		max;
}	t_mtx;

typedef struct s_cylinder
{
	t_uple	origin;
	t_uple	direction;
	float	radii;
	float	top;
	float	base;
	int		closed;
}	t_cylinder;

typedef struct s_cone
{
	t_uple	origin;
	t_uple	direction;
	float	radii;
	float	top;
	float	base;
	int		closed;
}	t_cone;

typedef struct s_pattern	t_pattern;
typedef struct s_material	t_material;
typedef t_color				(*t_pattern_at)(t_material material, t_uple point);
typedef t_checker			(*t_map)(t_uple point);

typedef struct s_pattern
{
	int				has_pattern;
	t_checker		checkers;
	t_color			color_a;
	t_color			color_b;
	t_pattern_at	pattern_at;
	t_mtx			transform;
	t_mtx			inverse;
	t_mtx			transpose;
}	t_pattern;

typedef struct s_plane
{
	t_uple	origin;
}	t_plane;

typedef struct s_sphere
{
	t_uple	origin;
	float	radii;
}	t_sphere;

typedef struct s_ray
{
	t_uple	origin;
	t_uple	direction;
}	t_ray;

typedef struct s_material
{
	t_pattern	pattern;
	t_map		map;
	t_color		color;
	t_color		ambient;
	float		diffuse;
	float		specular;
	float		shininess;
}	t_material;

typedef struct s_object		t_object;
typedef t_discr				(*t_intersec)(t_ray ray_, t_object object);
typedef t_uple				(*t_normal_at)(t_object object_, t_uple point_);

typedef struct s_object
{
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_cone		cone;
		t_cylinder	cylinder;
	};
	t_material		material;
	t_normal_at		normal_at;
	t_intersec		intersect;
	t_mtx			transform;
	t_mtx			inverse;
	t_mtx			transpose;
}	t_object;

typedef struct s_camera
{
	float		pixel_size;
	float		half_width;
	float		half_height;
	t_mtx		transform;
	t_mtx		inverse;
}	t_camera;

typedef struct s_intersc
{
	double		t;
	t_object	obj;
}	t_intersc;

typedef struct s_eye
{
	t_uple	eyev;
	t_uple	normalv;
}	t_eye;

typedef struct s_render
{
	float		hit;
	t_object	hit_object;
	t_color		final_color;
	t_eye		eye;
	t_ray		ray;
	t_uple		point;
	t_uple		over_point;
}	t_render;

typedef struct s_plight
{
	int		shadow;
	t_uple	position;
	t_color	intensity;
}	t_plight;

typedef struct s_scene
{
	int			*obj_number;
	int			*plight_number;
	t_color		ambient_light;
	t_object	*objects;
	t_plight	*plights;
	t_camera	camera;
}	t_scene;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_data;

void		return_lines(t_scene *scene, char *file);

double		cofactor(t_mtx mtx_a, int row, int col);

double		determinant(t_mtx mtx_a);

double		dot(t_uple vector_a, t_uple vector_b);

double		magnitude(t_uple vector);

double		minor(t_mtx mtx_a, int row, int col);

int			close_hook(t_data *data);

int			first_hit(t_scene *scene, t_render *render);

int			equal(double number_a, double number_b);

int			equal_tuple(t_uple tuple_a, t_uple tuple_b);

int			key_hook(int keycode, t_data *data);

int			render(t_data *data, t_scene *scene);

t_camera	camera(float field_of_view);

t_checker	cone_map(t_uple point);

t_checker	cylinder_map(t_uple point);

t_checker	plane_map(t_uple point);

t_checker	sphere_map(t_uple point);

t_color		add_c(t_color color_a, t_color color_b);

t_color		blend(t_color color_a, t_color color_b);

t_color		color(double red, double green, double blue);

t_color		gradient_at(t_material material, t_uple point);

t_color		lighting(t_object object_, t_plight light, t_uple point, t_eye eye);

t_color		multiply_c(t_color color, double scalar);

t_color		pattern_at(t_material material, t_object object_, t_uple point);

t_color		stripe_at(t_material material, t_uple point);

t_color		subtract_c(t_color color_a, t_color color_b);

t_color		uv_checker_at(t_material material, t_uple point);

t_cone		cone_set(t_uple position, t_uple direction, double radii, double h);

t_cylinder	cyl_set(t_uple position, t_uple direction, double radii, double h);

t_discr		cone_discriminant(t_ray ray_, t_object object_);

t_discr		cylinder_discriminant(t_ray ray_, t_object object_);

t_discr		plane_discriminant(t_ray ray_, t_object object_);

t_discr		sphere_discriminant(t_ray ray_, t_object object);

t_material	material(void);

t_mtx		full_rotation(t_uple vector);

t_mtx		get_identity_mtx(void);

t_mtx		inverse(t_mtx mtx_a);

t_mtx		line(double numb_1, double numb_2, double numb_3, double numb_4);

t_mtx		matrix(t_mtx mtx1, t_mtx mtx2, t_mtx mtx3, t_mtx mtx4);

t_mtx		multiply_mtx(t_mtx mtx_a, t_mtx mtx_b);

t_mtx		rotation_x(double rotate);

t_mtx		rotation_y(double rotate);

t_mtx		rotation_z(double rotate);

t_mtx		scaling(double x, double y, double z);

t_mtx		submatrix(t_mtx mtx_a, int row, int col);

t_mtx		translation(double x, double y, double z);

t_mtx		transpose(t_mtx mtx_a);

t_mtx		view_transform(t_uple from, t_uple to, t_uple up);

t_pattern	gradient_pattern(t_color color_a, t_color color_b);

t_pattern	pattern(void);

t_pattern	stripe_pattern(t_color color_a, t_color color_b);

t_pattern	uv_pattern(double width, double height, t_color a, t_color b);

t_ray		ray(t_uple origin, t_uple direction);

t_ray		ray_for_pixel(t_camera camera, float px, float py);

t_ray		transform(t_ray ray_, t_mtx operation);

t_uple		tuple(double x, double y, double z, double w);

t_uple		point(double x, double y, double z);

t_uple		vector(double x, double y, double z);

t_uple		add(t_uple tuple_a, t_uple tuple_b);

t_uple		subtract(t_uple tuple_a, t_uple tuple_b);

t_uple		multiply(t_uple tuple, double scalar);

t_uple		divide(t_uple tuple, double scalar);

double		dot(t_uple a, t_uple b);

t_uple		cross(t_uple vector_a, t_uple vector_b);

t_uple		reflect(t_uple in, t_uple normal);

t_uple		negate(t_uple tuple);

double		magnitude(t_uple vector);

t_uple		normalize(t_uple vector);

t_uple		cone_normal_at(t_object object_, t_uple point_);

t_uple		cylinder_normal_at(t_object object_, t_uple point_);

t_uple		multiply_mtx_tuple(t_mtx mtx_a, t_uple tuple_a);

t_uple		normal_at(t_object object_, t_uple point_);

t_uple		plane_normal_at(t_object object_, t_uple point_);

t_uple		point(double x, double y, double z);

t_uple		position(t_ray ray_a, float time);

t_uple		sphere_normal_at(t_object object_, t_uple point_);

void		ambient_light(t_scene *scene, t_color intensity);

void		color_int(t_color *color);

void		color_setup(t_render *render, t_scene *scene);

void		cone(t_scene *scene, t_cone set_cone);

void		cone_caps(t_discr *new_discr, t_object object_, t_ray ray);

void		cone_expection(t_discr *d, double a, double b, double c);

void		cylinder(t_scene *scene, t_cylinder set_cyl);

void		cylinder_caps(t_discr *new_discr, t_object object_, t_ray ray);

void		plane(t_scene *scene, t_uple origin, t_uple direction);

void		point_light(t_scene *scene, t_uple position, t_color intensity);

void		set_pattern_transform(t_pattern *pattern_, t_mtx transform);

void		set_transform(t_object *object_, t_mtx transform);

void		sphere(t_scene *scene, t_uple origin, double radii);

void		object(t_scene *scene);

int			validate_args(int argc);

int			verifie_camera(char *gnl);

int			open_file(char *file);

int			process_lines(int fd);

int			has_scene_is_valid(char *file);

int			process_ambient_light(double params[11], t_scene *scene);

int			process_camera(double params[11], t_scene *scene);

int			process_point_light(double params[11], t_scene *scene);

int			process_sphere(double params[11], t_scene *scene);

int			process_cone(double params[11], t_scene *scene);

int			process_cylinder(double params[11], t_scene *scene);

int			process_plane(double params[11], t_scene *scene);

#endif