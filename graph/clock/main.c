/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/25 19:05:25 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "matrix.h"
#include <stdio.h>
#include <math.h>
#define WIDTH 900
#define HEIGHT 550

typedef struct s_world
{
	mlx_image_t *image;
} t_world;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

unsigned int dominus_trans(float value, unsigned int size)
{
	return ((unsigned int)round((value + 1.0) / (2.0 / (float)size)));
}

void safe_put_pixel(float x, float y, mlx_image_t *image)
{
	unsigned int x_pixel;
	unsigned int y_pixel;
	
	x_pixel = dominus_trans(x, WIDTH);
	y_pixel = dominus_trans(y, HEIGHT);
	if (x_pixel > WIDTH || y_pixel - 1 >= HEIGHT)
		return ;
	printf("Calling mlx_put_pixel with x_pixel: %d, y_pixel: %d\n", x_pixel, HEIGHT - y_pixel);
	mlx_put_pixel(image, x_pixel, HEIGHT - y_pixel, ft_pixel(255, 0, 0, 255));
}

void tick(void *arg)
{
	int i;
	t_matrix *point;
	t_matrix *transform;

	t_world *world = (t_world *)arg;
	point = create_point(0, 1, 0);
	i = 0;
	while (i < 12)
	{
		safe_put_pixel(point->matrix[0][0], point->matrix[1][0], world->image);
		transform = rotate_z(PI / 4);
		point = matrix_matrix_mult(*transform, *point);
		i++;
	}
}

int main(void)
{
	mlx_t *mlx;
	t_world world;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	world.image = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, world.image, 0, 0);
	
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
