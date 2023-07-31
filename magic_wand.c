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
	int j, flag, i = 0;
	fun *datos;
	void (*f)(va_list, char *);

	while (format != NULL && format[i] != '\0')
	{
		flag = 0;
		if (format[i] == '%')
		{
			j = 0;
			datos = get_struct();
			while (datos[j].datatype != NULL)
			{
				if (format[i + 1] == *datos[j].datatype)
				{
					f = datos[j].f;
					f(arguments, str);
					flag = 1;
					i++;
					break;
				}
				j++;
			}
			if (flag == 0 && format[i + 1] != '\0')
				moverstr(str, format[i]);
			i++;
		}
		else
		{
			moverstr(str, format[i]);
			i++;
		}
	}
}
/**
 * get_struct- esta funcion devuelve la estructura con la funciones
 * Return: Devuelve la estructura
 */
fun *get_struct(void)
{
	static fun datos[] = {
		{"c", datac},
		{"s", datas},
		{"%", datap},
		{NULL, NULL}
	};
	return (datos);
}
/**
 * moverstr- esta funcion corre el nulo de str y añade un elemento
 * @str: puntero que guarda lo que se imprimira luego
 * @format: cadena original con la informacion
 */
void moverstr(char *str, char format)
{
	str[strlen(str) + 1] = '\0';
	str[strlen(str)] = format;
}
