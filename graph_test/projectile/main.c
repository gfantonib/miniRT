/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/13 10:02:29 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "tuple.h"
#include <stdio.h>
#define WIDTH 900
#define HEIGHT 550

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
	proj->position = create_point(0, 0, 0);
	proj->velocity = create_vector(0.01, 0.01, 0);
	normalize(proj->velocity);
	// *proj->velocity = tuple_scalar_mult(*proj->velocity, 11.25);
}

void env_init(t_env *env)
{
	env->gravity = create_vector(0, -0.001, 0);
	env->wind = create_vector(-0.0001, 0, 0);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void tick(void *arg)
{
	t_world *world = (t_world *)arg;

	int i;

	i = 0;
	while (i++ < 10000)
	{
		printf("position:           x: %f, y: %f\n", world->proj->position->x, world->proj->position->y);
		
		if (roundf(world->proj->position->x) >= WIDTH || roundf(world->proj->position->x) < 0
			|| roundf(world->proj->position->y) >= HEIGHT || roundf(world->proj->position->y) < 0)
			projectile_init(world->proj); 
		mlx_put_pixel(image, roundf(world->proj->position->x), HEIGHT - roundf(world->proj->position->y), ft_pixel(255, 0, 0, 255));
		
		
		*world->proj->position = tuple_add(*world->proj->position, *world->proj->velocity);
		printf("position after add: x: %f, y: %f\n", world->proj->position->x, world->proj->position->y);
		*world->proj->velocity = tuple_add(tuple_add(*world->proj->velocity, *world->env->gravity), *world->env->wind);
		printf("velocity after add: x: %f, y: %f\n\n", world->proj->position->x, world->proj->position->y);

	}
	// exit(0);
}

int main(void)
{
	mlx_t *mlx;
	t_proj proj;
	t_env env;
	t_world world;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, image, 0, 0);

	projectile_init(&proj);
	print_tuple(*proj.position);
	print_tuple(*proj.velocity);

	env_init(&env);
	print_tuple(*env.gravity);
	print_tuple(*env.wind);
	
	printf("\n");

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
