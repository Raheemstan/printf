#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Character string containing directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    int i;
    char *str;

    va_start(args, format);

    for (i = 0; format && format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    _putchar(va_arg(args, int));
                    printed_chars++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    printed_chars += _puts(str);
                    break;
                case '%':
                    _putchar('%');
                    printed_chars++;
                    break;
                default:
                    _putchar('%');
                    _putchar(format[i]);
                    printed_chars += 2;
                    break;
            }
        }
        else
        {
            _putchar(format[i]);
            printed_chars++;
        }
    }

    va_end(args);

    return (printed_chars);
}
