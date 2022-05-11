/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:35:36 by siykim            #+#    #+#             */
/*   Updated: 2022/05/11 13:56:32 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdio.h>
# include<stdarg.h>

int				type_c(va_list *ap);
int				type_s(va_list *ap);
int				type_p(va_list *ap);
int				type_di(va_list *ap);
unsigned int	type_u(va_list *ap);
int				type_x(va_list *ap);
int				type_largex(va_list *ap);
int				ft_printf(const char *str, ...);

#endif