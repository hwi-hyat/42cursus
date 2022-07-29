/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:04:58 by siykim            #+#    #+#             */
/*   Updated: 2022/07/26 23:12:46 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>
# include<signal.h>
# include<stdio.h> //나중에 지워주기

int				ft_atoi(const char *str);
int				type_s(va_list *ap);
int				type_di(va_list *ap);
int				ft_printf(const char *str, ...);

#endif