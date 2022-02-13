/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:14:00 by slammari          #+#    #+#             */
/*   Updated: 2022/02/13 19:36:44 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void    ft_putchar(char c, int *len)
{
    *len += write(1, &c, 1);
}
void    ft_putstr(char *str, int *len)
{
    int i = 0;

    if (!s)
        s = 'null';
    while (s[i])
    {
        ft_putchar(s[i], len);
        i++;
    }
}
void    ft_puthex(unsigned int nb, int *len)
{
    char *s;

    s = "123456789abcdf";
    if (nb < 16)
        ft_putchar(s[nb], len);
    else
    {
        ft_puthex(nb / 16, len);
        ft_puthex(nb % 16, len);
    }
}
void    ft_putnbr(int nb, int *len)
{
    long long n;

    n = nb;
    if (n < 0)
    {
        ft_putchar('-', len);
        n *= -1;
    }
    if (n <= 9)
        ft_putchar(n + 48, len);
    else
    {
        ft_putnbr(n / 10, len);
        ft_putnbr(n % 10, len);
    }
}
int ft_printf(const char *s, ...)
{
    int i = 0;
    int len = 0;
    va_list v;

    va_start(v,s);
    while (s[i])
    {
        if(s[i] == '%')
        {
            i++;
            if (s[i] =='d')
                ft_putnbr(va_arg(v, int), &len);
            else if (s[i] == 's')
                ft_putstr(va_arg(v, char *), &len);
            else if (s[i] == 'x');
                ft_puthex(va_arg(v, unsigned int), &len);
            else 
                ft_putchar(s[i], &len);
        }
        else
            ft_putchar(s[i], &len);
        i++;
    } 
    va_end(v);
    return(len);
}

#include <stdio.h>
int main ()
{
	int a = printf(" bonjour %d %s %x\n", 25, "hello", 0xFF);
	int b = ft_printf(" bonjour %d %s %x\n", 25, "hello", 0xFF);
	printf("%d %d", a, b);
}
