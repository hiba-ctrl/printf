#include "main.h"
#include <unistd.h>

/**
 * _printf - Mimics the printf function
 * @format: The format string
 * @...: The variadic arguments
 * 
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    unsigned int i = 0, count = 0;
    va_list args;
    char ch;
    char *str;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    ch = (char) va_arg(args, int); // Cast to char as va_arg only takes fully promoted types
                    count += write(1, &ch, 1);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    count += print_string(str);
                    break;
                case '%':
                    count += write(1, "%", 1);
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

/**
 * print_string - Prints a string
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
    int count = 0;
    int j;

    for (j = 0; str && str[j] != '\0'; j++)
    {
        count += write(1, &str[j], 1);
    }

    return count;
}

