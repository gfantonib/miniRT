/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:59 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 10:18:51 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "../libft/libft.h"
# include "math.h"
# include "stdlib.h"

typedef struct s_matrix
{
	float			**matrix;
	unsigned int	rows;
	unsigned int	columns;
}	t_matrix;

enum tuple_type 
{
  VECTOR = 0,
  POINT = 1,
  COLOR = 2
};

t_matrix	*create_matrix(unsigned int rows, unsigned int columns);
int 		matrix_equal(t_matrix ma, t_matrix mb);
t_matrix	*matrix_matrix_mult(t_matrix ma, t_matrix mb);
t_matrix	*matrix_transpose(t_matrix matrix);
t_matrix	*submatrix(t_matrix matrix, unsigned int rm_row, unsigned int rm_column);
float		determinant(t_matrix matrix);
t_matrix	*inverse(t_matrix matrix);

t_matrix	*matrix_add(t_matrix ma, t_matrix mb);
t_matrix	*matrix_minus(t_matrix ma, t_matrix mb);
void		matrix_neg(t_matrix *matrix);
t_matrix	*matrix_scalar_mult(t_matrix ma, float scalar);
t_matrix	*matrix_scalar_div(t_matrix ma, float scalar);
float		magnitude(t_matrix matrix);
void		normalize(t_matrix *matrix);

t_matrix	*create_point(float x, float y, float z);
t_matrix	*create_vector(float x, float y, float z);
float dot_prod(t_matrix veca, t_matrix vecb);
t_matrix *cross_prod(t_matrix veca, t_matrix vecb);

#endif