/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:37:11 by gd-harco          #+#    #+#             */
/*   Updated: 2022/10/23 18:37:11 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include <unistd.h>

size_t	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
