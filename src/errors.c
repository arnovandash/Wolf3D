/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:arnovan-<arnovan-@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 14:26:54 by arnovan-          #+#    #+#             */
/*   Updated: 2025/08/19 12:25:51 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

/**
 * @brief Prints an error message and exits the program.
 * 
 * @param err The error code.
 * 		1: Malloc error
 * 		2: Invalid map file or usage
 * 		3: Error opening file
 */
void	error(int err)
{
	if (err == 1)
	{
		printf("Encountered a malloc error\n");
	}
	if (err == 2)
	{
		printf("Invalid map file\n");
		printf("Usage ./wolf3d map.txt\n");
	}
	if (err == 3)
	{
		printf("Error opening file\n");
	}
	exit(1);
}
