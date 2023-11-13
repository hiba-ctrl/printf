#include "main.h"
#include <stdlib.h>

/**
 * _printf - Custom printf function to format and print data
 * @format: format string containing the characters and format specifiers
 *
 * Description: This function mimics a simplified printf function
 * handling the 'c', 's', and '%' conversion specifiers. It uses
 * write to output characters and strings.
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p != '\0'; p++)
    {
        if (*p != '%')
        {
            write(1, p, 1);
            count++;
            continue;
        }

        switch (*++p)
        {
        case 'c':
        {
            char c = (char)va_arg(args, int); // Promoted to int in va_arg
            write(1, &c, 1);
            count++;
            break;
        }
        case 's':
        {
            char *s = va_arg(args, char *);
            if (s == NULL)
                s = "(null)";
            for (char *sp = s; *sp != '\0'; sp++)
            {
                write(1, sp, 1);
                count++;
            }
            break;
        }
        case '%':
        {
            write(1, p, 1);
            count++;
            break;
        }
        default:
            break;
        }
    }

    va_end(args);
    return count;
}
