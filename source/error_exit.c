/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:46:51 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/17 15:52:02 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_exit.h"

void error_exit(char *messege)
{
	ft_printf_fd(STDERR_FILENO, messege);
	ft_free_trashman();
	exit(1);
}