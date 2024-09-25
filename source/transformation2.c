/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:19:18 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/25 09:16:10 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix *shear(float *shear_array)
{
	t_matrix *matrix;

	matrix = create_matrix(4, 4);
	matrix->matrix[0][0] = 1;
	matrix->matrix[0][1] = shear_array[0];
	matrix->matrix[0][2] = shear_array[1];
	matrix->matrix[1][1] = 1;
	matrix->matrix[1][0] = shear_array[2];
	matrix->matrix[1][2] = shear_array[3];
	matrix->matrix[2][2] = 1;
	matrix->matrix[2][0] = shear_array[4];
	matrix->matrix[2][1] = shear_array[5];
	matrix->matrix[3][3] = 1;
	return (matrix);
}

// int main() {
// 	t_matrix *result = shear((float[2]){1.0, 2.0}, (float[2]){3.0, 4.0}, (float[2]){5.0, 6.0});

// 	// Rest of your code...

// 	return 0;
// }
