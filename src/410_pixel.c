/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   410_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:30:19 by passunca          #+#    #+#             */
/*   Updated: 2024/10/12 09:20:23 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*	ft_pixel_put : Puts a pixel to the display
 *										 img->bpp
 *	offset = (y * img->line_len) + ( x * -------- )
 *										    8
 *		offset : stores the byte offset within the image data array where the
 *		information should be placed;, accounting for the possibility of
 *		padding bytes at the end of each row;
 *		1. Multiply the y-coordinate by the line length to find the starting
 *		position of the row in the buffer. This accounts for the width of the
 *		image and any padding.
 *		2. Multiply the x-coordinate by the size of each pixel in bytes (bits
 *		per_pixel / 8) to find the position of the pixel within the row.
 *		3. Add these two values together to get the overall byte offset within
 *		the buffer.
 *
 *		Note: This formula assumes that the image data is stored in a linear
 *		block of memory, row by row, without any compression or interlacing.
 *	*/
/**
 * @brief Puts a pixel to the display
 * @param img a pointer to a t_img struct
 * @param x the x coordinate of the pixel
 * @param y the y coordinate of the pixel
 * @param color the color of the pixel
*/
void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;

	if (img == NULL || x < 0 || y < 0
		|| x >= WINDOW_W || y >= WINDOW_H)
		return ;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(int *)(img->pix + offset) = color;
}
