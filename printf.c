#include "main.h"

/**
 * _printf - Mimics the printf function
 * @format: The format string
 * Description: This function prints according to a format.
 * It supports the 'c', 's', and '%' conversion specifiers.
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    char *str, buffer;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c': buffer = va_arg(args, int); write(1, &buffer, 1); count++; break;
                case 's': str = va_arg(args, char*); for (str = (str) ? str : "(null)"; *str; str++, count++) write(1, str, 1); break;
                case '%': write(1, "%", 1); count++; break;
                default: format--; break;
            }
        }
        else { write(1, format, 1); count++; }
        format++;
    }
    va_end(args);
    return count;
}

