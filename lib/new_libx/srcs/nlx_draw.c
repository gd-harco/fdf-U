/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:55:39 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/29 11:12:07 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_draw.c
 * @brief
 * @author gd-harco
 * @date 2023-04-28
 * @version 1.2
 */

#include "nlx_draw.h"

/**
 * @brief draw a pixel on an image
 *
 * @param img pointer to the t_img structure containing the image
 * @param x x coordinate of the pixel
 * @param y y coordinate of the pixel
 * @param color color of the pixel, in hexadecimal
 * or as defined in nlx_color.h
 * @return nothing
 */
void	nlx_pixel_put(t_img	*img, t_2d_point to_put, int color)
{
	char	*dst;

	dst = img->addr + (to_put.y * img->line_length
			+ to_put.x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief draw a line on an image
 * @details the function will draw a line on the image with the given color.
 * This function is just here to analyze the slope of the line
 * and call the according function.
 * @param img the image on which the line will be drawn
 * @param to_draw the line to draw
 * @param color the color of the line
 */
void	nlx_draw_line(t_img *img, t_nlx_line *to_draw, int color)
{
	if (to_draw->start.x == to_draw->end.x
		|| to_draw->start.y == to_draw->end.y)
		return (draw_straight_line(to_draw->start, to_draw->end, img));
	if (to_draw->starting_error_x > to_draw->starting_error_y)
		draw_low_slope(to_draw->start, *to_draw, img);
	else
		draw_high_slope(to_draw->start, *to_draw, img);
	(void)color;
}

/**
 * @brief draw the start and end points of a line on an image
 * @details the function will only draw the
 * start and end points of a line, usefull for performance on big maps.
 * @param img the image on which both point will be drawn
 * @param to_draw the line to draw
 * @param color the color of the line
 */
void	nlx_draw_points(t_img *img, t_nlx_line *to_draw, int color)
{
	nlx_pixel_put(img, to_draw->start, color);
	nlx_pixel_put(img, to_draw->end, color);
}
