#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
* print_buffer - Prints a buffer
*
* @buffer: char array to print
* @buff: buffer index
*
* Description: This function prints the contents of a buffer and resets the
* buffer index.
*/
void print_buffer(char buffer[], int *buff)
{
if (*buff > 0)
write(1, &buffer[0], *buff);

*buff = 0;
}


/**
* _printf - Custom printf function
*
* @format: format string to be printed
*
* Return: Number of characters printed
*
* Description: This function prints a formatted string, similar to printf.
* It supports flags, width, precision, and length modifiers. It returns the
* number of characters printed, or -1 if an error occurs.
*/

int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);
va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);
va_end(list);

return (printed_chars);
}
