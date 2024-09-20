/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:59 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/20 17:25:21 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "../libft/libft.h"
# include "math.h"
# include "stdlib.h"

# define EPSILON 0.00001

typedef struct s_matrix
{
	float			**matrix;
	unsigned int	rows;
	unsigned int	columns;
}	t_matrix;

t_matrix	*create_matrix(unsigned int rows, unsigned int columns);
int 		matrix_equal(t_matrix ma, t_matrix mb);
t_matrix	*matrix_matrix_mult(t_matrix ma, t_matrix mb);
t_matrix	*matrix_transpose(t_matrix matrix);
t_matrix	*submatrix(t_matrix matrix, unsigned int rm_row, unsigned int rm_column);
float		determinant(t_matrix matrix);
t_matrix	*inverse(t_matrix matrix);

#endif