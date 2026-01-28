/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:12:08 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/13 00:23:14 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// PRINTF
int	ft_printf(const char *c, ...);
int	ft_putnbr_st_fd(size_t n, size_t baseformat, char *base, int fd);
int	ft_putnbr_ui_fd(unsigned int n,
		unsigned int baseformat, char *base, int fd);
int	ft_putpointer(int n, int fd);
int	ft_printhexalow(va_list args, int fd);
int	ft_printhexaup(va_list args, int fd);
int	ft_printchar(va_list args, int fd);
int	ft_printdecimal(va_list args, int fd);
int	ft_printstr(va_list args, int fd);
int	ft_printpercent(va_list args, int fd);
int	ft_printnbr(va_list args, int fd);
int	ft_printunbr(va_list args, int fd);
int	ft_printpointer(va_list args, int fd);
int	ft_line(char format, int fd);
int	ft_percenterror(const char *format, va_list args);

#endif
