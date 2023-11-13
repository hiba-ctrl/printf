#include "main.h"

/**
 * print_string - Prints a string or (null) if string is NULL
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
    int count = 0;
    int j;

    if (!str)
    {
        return write(1, "(null)", 6); /* Handle NULL string */
    }

    for (j = 0; str[j] != '\0'; j++)
    {
        count += write(1, &str[j], 1);
    }

    return count;
}

/**
 * _printf - Mimics the printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    unsigned int i = 0, count = 0;
    va_list args;
    char ch;

    if (!format)
    {
        return -1;  /* Return error if format string is NULL */
    }

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    ch = (char) va_arg(args, int);
                    count += write(1, &ch, 1);
                    break;
                case 's':
                    count += print_string(va_arg(args, char *));
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, &format[i - 1], 1); /* Print the % sign */
                    count += write(1, &format[i], 1);     /* Print the unrecognized specifier */
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return count;
}

