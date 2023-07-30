#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * _printf- esta funcion imrpime una salida de acuerdo al formato c, s, d, i
 * @format: apuntar a el simbolo de la funcion
 * Return: Devuelve NULL
 */
int _printf(const char *format, ...)
{
	int i = 0;
	char *str;
	char *esp = " ";
	va_list arguments;
	char *(*f)(va_list, char *);

	str = malloc(1024 * sizeof(char));
	if (str == NULL)
		return (0);
	str[0] = '\0';
	va_start(arguments, format);
	printf("todo inicializado");
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			printf("entro al %");
			esp[0] = format[i + 1];
			f = get_data(esp);
			if (f == NULL)
			{
				str[strlen(str) + 1] = '\0';
				str[strlen(str)] = format[i];
			}
			else
			{
				printf("entro al else");
				str[strlen(str) + 1] = '\0';
				str = f(arguments, str);
				i++;
			}
		}
		else
		{
			str[strlen(str) + 1] = '\0';
			str[strlen(str)] = format[i];
			i++;
		}
	}
	i = strlen(str);
	write(1, str, i);
	va_end(arguments);
	free(str);
	return (i);
}
