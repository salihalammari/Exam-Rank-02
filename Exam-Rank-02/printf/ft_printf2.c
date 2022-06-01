/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:17:06 by slammari          #+#    #+#             */
/*   Updated: 2022/02/13 19:36:56 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void    ft_putchar(char c, int *len)
{
    *len += write (1, &c, 1);
}

void ft_putstr(char *str, int *len)
{
    int i = 0;
    if (str == NULL)
    {
        *len += write (1, "(null)", 6);
	return;
    }
    while (str[i])
    {
        ft_putchar(str[i], len);
        i++;
    }
}

void    ft_putnbr(int nb, int *len)
{
    if (nb == -2147483648)
        *len += write (1, "-2147483648", 11);
    if (nb < 0)
    {
        *len += write (1, "-", 1);
        nb *= -1;
    }
    if (nb < 10)
        ft_putchar(nb + 48, len);
    else
    {
        ft_putnbr(nb / 10, len);
        ft_putnbr(nb % 10, len);
    }
}

void ft_puthex(unsigned int nb, int *len)
{
    char base[16] = "0123456789abcdef";
    

    if (nb > 15)
    {
        ft_puthex(nb / 16, len);
        ft_puthex(nb % 16, len);
    }
     else
        ft_putchar(base[nb], len);
}

int     ft_printf(const char *s, ...)
{
    int     i = 0;
    va_list v;
    int     len = 0;
    va_start(v, s);
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            if (s[i] == 'd')
                ft_putnbr(va_arg(v, int), &len);
            else if (s[i] == 's')
                ft_putstr(va_arg(v, char *), &len);
            else if (s[i] == 'x')
                ft_puthex(va_arg(v, unsigned int), &len);
            else
				ft_putchar(s[i], &len);
        }
        else
            ft_putchar(s[i], &len);
        i++;
    }
    va_end(v);
    return (len);    
}
#include <stdio.h>
int main ()
{
	int a = printf(" bonjour %d %s %x\n", 25, "hello", 0xFF);
	int b = ft_printf(" bonjour %d %s %x\n", 25, "hello", 0xFF);
	printf("%d %d", a, b);
}
