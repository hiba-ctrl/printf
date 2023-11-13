#include "main.h"

/**
 * _printf - Mimics the printf function
 * @format: Format string
 * Return: Number of characters printed
 *
 * Description: Prints formatted output. Supports '%c', '%s', and '%%'.
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    char *str;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            switch (*format)
            {
                case 'c': count += write(1, &va_arg(args, int), 1); break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str) str = "(null)";
                    for (; *str; count++) write(1, str++, 1);
                    break;
                case '%': count += write(1, "%", 1); break;
            }
        }
        else if (*format != '%') count += write(1, format, 1);
        format++;
    }
    va_end(args);
    return count;
}

