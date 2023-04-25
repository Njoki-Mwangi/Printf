#include "main.h"

/**
*get_precision - Calculates the precision
*
*@format: formatted string
*@i: pointer to iterator
*@list: list of arguments
*
*Return: precision (int)
*
*Description: This function calculates and returns the precision for a
*format specifier. The precision is the number of digits to display after the
*decimal point for a floating-point number, or the maximum number of characters
*to print for a string. The precision is indicated by a period ('.') in the
*format specifier, followed by an integer or the '*' character, which indicates
*that the precision will be provided as an argument from the list.
*/
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

