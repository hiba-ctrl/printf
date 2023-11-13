#include "main.h"

/**
 * _printf - Custom printf function to format and print data.
 * @format: Format string containing the characters and format specifiers.
 *
 * Description: This function mimics a simplified printf function,
 * capable of handling 'c', 's', and '%' conversion specifiers.
 * It writes output to stdout and returns the number of characters printed.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str, c;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            switch (*++format)
            {
                case 'c':
                    c = (char) va_arg(args, int);
                    count += write(1, &c, 1);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    for (int j = 0; str[j] != '\0'; j++)
                        count += write(1, &str[j], 1);
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, format - 1, 2);
                    break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }
        format++;
    }
    va_end(args);
    return count;
}

