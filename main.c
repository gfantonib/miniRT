/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/10 18:42:36 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "tuple.h"
#include <stdio.h>

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_randomize(void *mlx)
{
	mlx_image_t *image = (mlx_image_t *)mlx;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

int	main(void)
{
	mlx_t *mlx;
	mlx_image_t *image;

	mlx = mlx_init(500, 500, "miniRT", true);
	image = mlx_new_image(mlx, 300, 300);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop_hook(mlx, ft_randomize, image);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (0);
}