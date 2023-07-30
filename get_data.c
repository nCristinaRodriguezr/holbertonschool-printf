#include "header.h"
#include <stdarg.h>
#include <string.h>
/**
 * get_data- esta funcion obtiene la funcion que se debe ejecutar
 * segun el tipo de dato
 * @s: apuntar al simbolo del tipo de dato o especificador
 * Return: Devuelve NULL
 */
void (*get_data(char *s))(va_list arguments, char *str)
{
	fun datos[] = {
		{"c", datac},
		{"s", datas},
		{NULL, NULL}
	};
	int i = 0;

	while (datos[i].datatype != NULL)
	{
		if (*s == *datos[i].datatype)
		{
			return (datos[i].f);
		}
		i++;
	}
	return (NULL);
}
