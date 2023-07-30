#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * _printf- esta funcion imrpime una salida de acuerdo al formato c, s, d, i
 * @format: apuntar a el simbolo de la funcion
 * Return: Devuelve i
 */
int _printf(const char *format, ...)
{
	int i = 0;
	char *str;
	va_list arguments;

	str = malloc(10000 * sizeof(char));
	if (str == NULL)
		return (0);
	str[0] = '\0';
	va_start(arguments, format);
	get_data(format, arguments, str);
	i = strlen(str);
	write(1, str, i);
	va_end(arguments);
	free(str);
	return (i);
}
