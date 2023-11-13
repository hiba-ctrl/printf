#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of variadic arguments
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: List of variadic arguments
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    int count = 0;
    char *str = va_arg(args, char *);
    char *null_str = "(null)";

    if (!str)
    {
        str = null_str;
    }

    while (*str)
    {
        count += write(1, str++, 1);
    }
    
    return count;
}

/**
 * print_percent - Prints a percent sign
 * Return: Number of characters printed
 */
int print_percent(void)
{
    return (write(1, "%", 1));
}

/**
 * _printf - Mimics the standard printf function with limited functionality
 * @format: Format string containing the characters and format specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    unsigned int i = 0, count = 0;
    va_list args;
    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++; // Skip the % character
            switch (format[i])
            {
                case 'c':
                    count += print_char(args);
                    break;
                case 's':
                    count += print_string(args);
                    break;
                case '%':
                    count += print_percent();
                    break;
                default:
                    count += write(1, &format[i - 1], 1); // Print the % character
                    count += write(1, &format[i], 1); // Print the current character
                    break;
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

