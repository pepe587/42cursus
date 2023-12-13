/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:12:09 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/29 13:56:54 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_format(const char *str, int i, int len, va_list args);
int		ft_format2(const char *str, int i, int len, va_list args);
int		dectohex(unsigned long long dec, int mayus);
int		ft_format3(const char *str, int i, int len, va_list args);
void	ft_putunbr_fd(unsigned int n, int fd);
int		ft_printhex(unsigned int num, int mayus);

#endif