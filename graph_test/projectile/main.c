/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/12 17:31:15 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "tuple.h"
#include <stdio.h>

mlx_image_t *image;

void print_tuple(t_tuple tuple)
{
	printf("(%f, %f, %f, %i)\n", tuple.x, tuple.y, tuple.z, tuple.w);
}

typedef struct s_proj
{
	t_tuple *position;
	t_tuple *velocity;

} t_proj;

typedef struct s_env
{
	t_tuple *gravity;
	t_tuple *wind;

} t_env;

typedef struct s_world
{
	t_env *env;
	t_proj *proj;

} t_world;

void projectile_init(t_proj *proj)
{
	proj->position = create_point(500, 500, 0);
	proj->velocity = create_vector(1, 1, 0);
	normalize(proj->velocity);
}

void env_init(t_env *env)
{
	env->gravity = create_vector(0, 0, 0);
	env->wind = create_vector(0, 0, 0);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void tick(void *arg)
{
	t_world *world = (t_world *)arg;

	int i;
	float x;
	float y;
	t_tuple *position;
	t_tuple *velocity;
	t_tuple *gravity;
	t_tuple *wind;

	position = world->proj->position;
	velocity = world->proj->velocity;
	gravity = world->env->gravity;
	wind = world->env->wind;

	i = 0;
	while (i++ < 18)
	{
		x = position->x;
		y = position->y;
		printf("x: %f, y: %f", x, y);
		mlx_put_pixel(image, x, y, ft_pixel(255, 0, 0, 255));
		*position = tuple_add(*position, *velocity);
		*velocity = tuple_add(tuple_add(*velocity, *gravity), *wind);
	}
}

int main(void)
{
	mlx_t *mlx;
	t_proj proj;
	t_env env;
	t_world world;

	mlx = mlx_init(1000, 1000, "miniRT", true);
	image = mlx_new_image(mlx, 1000, 1000);
	mlx_image_to_window(mlx, image, 0, 0);

	projectile_init(&proj);
	print_tuple(*proj.position);
	print_tuple(*proj.velocity);

	env_init(&env);
	print_tuple(*env.gravity);
	print_tuple(*env.wind);

	world.env = &env;
	world.proj = &proj;

	mlx_loop_hook(mlx, tick, &world);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (0);
}

// void	ft_randomize(void *mlx)
// {
// 	mlx_image_t *image = (mlx_image_t *)mlx;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }
