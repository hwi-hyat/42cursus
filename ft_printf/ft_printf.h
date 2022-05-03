/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:35:36 by siykim            #+#    #+#             */
/*   Updated: 2022/05/03 01:22:26 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<unistd.h>
#include<stdarg.h>

int	type_c(va_list ap);
int	type_s(va_list ap);
int	type_p(va_list ap);
int	type_di(va_list ap);


#endif