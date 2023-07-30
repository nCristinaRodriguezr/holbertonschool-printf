#include "main.h"
#include <stdarg.h>
#include <string.h>
/**
 * datac- esta función guarda en el puntero str el tipo de dato c (char)
 * @arguments: lista de argumentos de la funcion principal
 * @str: puntero donde se guardara el caracter para imprimirlo luego
 * Return: Devuelve el puntero str llenito
 */
char *datac(va_list arguments, char *str)
{
	str[strlen(str) + 1] = '\0';
	str[strlen(str)] = va_arg(arguments, int);
	return (str);
}
/**
 * datas- esta función guarda en el puntero str el tipo de dato s (puntero)
 * @arguments: lista de argumentos de la funcion principal
 * @str: puntero donde se guardara la cadena para imprimirla luego
 * Return: Devuelve el puntero str llenito
 */
char *datas(va_list arguments, char *str)
{
	char *s;
	int j = 0;

	s = va_arg(arguments, char *);
	while (s[j] != '\0')
	{
		str[strlen(str) + 1] = '\0';
		str[strlen(str)] = s[j];
		j++;
	}
	return (str);
}
