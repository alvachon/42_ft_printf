/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:00:04 by alvachon          #+#    #+#             */
/*   Updated: 2022/07/25 16:04:08 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_print
{
	char		padding;
	int			pad_front;
	int			pad_end;
	int			hex;
	int			dec_sign;
	int			len_str;
	int			precision;
	int			len_precision;
	int			width;
	int			c;
	int			alph;
	char		*str;
	char		*str_malloc;
	int			alloc;
	int			arg;
	int			modifier;
	int			percent;
	int			zero_pacing;
	int			s;
	int			digit;
}	t_print;

/*FROM FT_PRINTF.C
*	Call va_list and return a count from ft_check_format, were the magic happen
*/
int		ft_printf(const char *format, ...);
/*
Call a struct, control the print sequence
*/
int		ft_check_format(const char *format, va_list ap);
/*
Init the struct at each new loop
*/
void	ft_init_flag(t_print *flag);
/*
Check all flag in the format string and put it in the struct,
count items to skip in str format
*/
int		ft_check_flag(const char *format, t_print *flag, va_list ap);
/*
FROM FUNCTIONS_FLAGS.C
A special function to deal when element is 0
*/
void	ft_reset(const char *format, t_print *flag);
/*
Called from ft_check_flag, deal everything that concern padding and %%
*/
int		ft_set_width(const char *format, t_print *flag, va_list ap);
/*
iduxx : Precise the MINIMUM number of digits to be printed.
if strlen is < than precision, padded at left with zeroes.
if precision is 0 or omitted entirely, 
or if the period (.)appears without a number following it,
the precision is set to 1.
c == NO EFFECT
s = maximum number of characters (bytes) to be printed.
Characters are printed until a null character is encountered. 
*/
int		ft_set_precision(const char *format, t_print *flag, va_list ap);
/*
Called from ft_check_flag->ft_set_precision, 
deal everything that concern the specifier
*/
int		ft_set_specifier(const char *format, t_print *flag, va_list ap);
/*
ROM FUNCTIONS_PADDING.C*/
/* 
%% */
int		ft_set_percent(t_print *flag);
/* *
* WORK WITH WIDTH && WORK WITH PRECISION */
int		ft_set_star(t_print *flag, va_list ap);
/* 
' '
*/
int		ft_set_front(t_print *flag);
/*
#
The %#p format specifier has much better performance than %p format specifier.
flag->hex  = the # flag prefixes any nonzero output value with 0x, or 0X,.
 - 
Left-justify the result within the field width. (end padding)
 + 
Prefix the output value with a sign (+ or -) done. 
if the output value is of a signed type.
0 
* The 0 flag is ignored if precision is specified for an integer 
*	or if the - flag is specified.
¨rt 0 instead of ' '
*/
int		ft_set_padding(const char *format, t_print *flag);
/* FROM FUNCTIONS_FORMAT.C*/
/* Deal len string alteration from precision bonus */
void	ft_check_len_mod(t_print *flag);
/* 
	s specifier, s = NULL str = "(null)", specifies len options;
* NEED ANSWER -> Does need a special len for null ?
*	-> set strlen of 's'
*	-> If modifier, but len mod is smaller than strlen of 's', len = strlen.
*/
int		ft_set_s(t_print *flag, va_list ap);
/*
	c specifier
*/
int		ft_set_c(t_print *flag, va_list ap);
/* x and X specifier
*	->set memory on the heap and free it
*	-> str = ft_deal_hexa for lower cap
*	-> str = ft_deal_hexa for high cap
*	-> strlen from the result.
 xX
	p specifier
*	->set memory on the heap and free it
*	-> call flag->hex to add the 0x in front. (from padding)
*	-> str = ft_deal_ptr
*	-> strlen from the result.
*	-> Call reset if null
*/
int		ft_set_xxp(const char *format, t_print *flag, va_list ap);
/*
	d, i, u specifier
*	->set memory on the heap and free it
*	->str = ft_itoa or ft_deal_usign.
*	-> strlen from the result.
*	-> Call reset if null
*/
int		ft_set_diu(const char *format, t_print *flag, va_list ap);
/*
FROM FUNCTION_HELP1.C* AND FUNCTION_HELP2.C
Helper
*/
char	*ft_deal_ptr(unsigned long n);
char	*ft_deal_usign(unsigned int n);
char	*ft_deal_hexa(unsigned int n, int capitals);
/*
* FROM FUNCTION_PRINT.C
* Deal mechanic of the width
* Check if pad_front == 1 w/ condition if width  larger or equal than strlen
*	-> call fr_print_width;
*	-> print '+';
*	-> print '0x';
*/
int		ft_print_front_padding(t_print *flag);
/*
print %%, return -1 -- OK
*	C SPECIFIER print ' ' (digit)
* VERIFICATION NEEDED
*	-> if width smaller than 2, pad nothing.
*	-> else, width is printed of the size of width - 1 ( len of 1 char)
*	-> return -1.
*	S SPECIFIER print ' ' (digit)
* VERIFICATION NEEDED
*	-> if width smaller OR EQUAL than 2, pad nothing.
*	-> else, width is printed of the size of width - ( len of STR)
*	-> return 0
*/
int		ft_print_width(t_print *flag);
/*
*	print c specifier 
*	CHECK THIS - >return strlen + 1
*   print spdiuxx
*	CHECK THIS -> return a special value if hex == 1 (len_str + 2)
*	CHECK THIS -> if ' ' and flag-width plus petit que 2 : return strlen - 1 ???
*	CHECK THIS -> return 0 if flag width est plus grand que 2 et ' ' 
*	free if alloc
*	Normal = return strlen.
*/
int		ft_print_arg(t_print *flag);
int		ft_print_end_padding(t_print *flag);

#endif
