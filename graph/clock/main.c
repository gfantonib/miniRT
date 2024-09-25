/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/25 11:41:05 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include <stdio.h>
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

void safe_put_pixel(unsigned int x, unsigned int y, mlx_image_t *image)
{
	if (x >= WIDTH || y - 1 >= HEIGHT)
		return ;
	printf("Calling mlx_put_pixel with x: %d, y: %d\n", x, HEIGHT - y);
	mlx_put_pixel(image, x, HEIGHT - y, ft_pixel(255, 0, 0, 255));
}

void tick(void *arg)
{
	int x;
	int y;
	t_world *world = (t_world *)arg;
	
	x = 0;
	while (x < WIDTH)
	{	
		y = 0;
		while (y < HEIGHT)
		{
			safe_put_pixel(x, y, world->image);
			y++;
		}
		x++;
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
