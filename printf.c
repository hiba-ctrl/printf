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
    int count = 0, i;
    va_list args;
    char *str, c;

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            switch (format[++i])
            {
                case 'c':
                    c = (char) va_arg(args, int);
                    count += write(1, &c, 1);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str) str = "(null)";
                    for (int j = 0; str[j] != '\0'; j++)
                        count += write(1, &str[j], 1);
                    break;
                case '%':
                    count += write(1, &format[i], 1);
                    break;
                default:
                    count += write(1, &format[i-1], 1) + write(1, &format[i], 1);
                    break;
            }
        }
        else
            count += write(1, &format[i], 1);
    }
    va_end(args);
    return count;
}

