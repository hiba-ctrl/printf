#include "main.h"
#include <stdio.h>

/**
 * _printf - Custom printf function to format and print data
 * @format: format string containing the characters and format specifiers
 * Description: This function mimics a simplified printf function
 * handling the 'c', 's', and '%' conversion specifiers.
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
            putchar(*p);
            count++;
            continue;
        }

        switch (*++p)
        {
        case 'c':
            {
                char c = va_arg(args, int);
                putchar(c);
                count++;
                break;
            }
        case 's':
            {
                char *s = va_arg(args, char*);
                if (s == NULL)
                {
                    s = "(null)";
                }
                for (char *sp = s; *sp != '\0'; sp++)
                {
                    putchar(*sp);
                    count++;
                }
                break;
            }
        case '%':
            {
                putchar('%');
                count++;
                break;
            }
        }
    }

    va_end(args);
    return count;
}
