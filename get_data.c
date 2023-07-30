#include "main.h"
#include <stdarg.h>
#include <string.h>
/**
 * get_data- esta funcion obtiene la funcion que se debe ejecutar
 * segun el tipo de dato
 * @format: apunta a la cadena que se debe imprimir
 * @arguments:lista de argumentos variables de la funcion printf
 * @str: en este puntero se guardará lo que se debe imprimir
 * Return: Devuelve NULL
 */
void get_data(const char *format, va_list arguments, char *str)
{
	fun datos[] = {
		{"c", datac},
		{"s", datas},
		{NULL, NULL}
	};
	int i = 0;
	int j, flag;

	void (*f)(va_list, char *);

	while (format[i] != '\0')
	{
		flag = 0;
		if (format[i] == '%')
		{
			j = 0;
			while (datos[j].datatype != NULL)
			{
				if (format[i + 1] == *datos[j].datatype)
				{
					f = datos[j].f;
					f(arguments, str);
					flag = 1;
					i++;
				}
				j++;
			}
			if (flag == 0)
			{
				str[strlen(str) + 1] = '\0';
				str[strlen(str)] = format[i];
			}
			i++;
		}
		else
		{
			str[strlen(str) + 1] = '\0';
			str[strlen(str)] = format[i];
			i++;
		}
	}
}
