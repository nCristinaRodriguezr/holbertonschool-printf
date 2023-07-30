#include "main.h"
#include <stdarg.h>
#include <string.h>
/**
 * datac- esta función guarda en el puntero str el tipo de dato c (char)
 * @arguments: lista de argumentos de la funcion principal
 * @str: puntero donde se guardara el caracter para imprimirlo luego
 */
void datac(va_list arguments, char *str)
{
	str[strlen(str) + 1] = '\0';
	str[strlen(str)] = va_arg(arguments, int);
}
/**
 * datas- esta función guarda en el puntero str el tipo de dato s (puntero)
 * @arguments: lista de argumentos de la funcion principal
 * @str: puntero donde se guardara la cadena para imprimirla luego
 */
void datas(va_list arguments, char *str)
{
	char *s;
	int j = 0;

	s = va_arg(arguments, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[j] != '\0')
	{
		str[strlen(str) + 1] = '\0';
		str[strlen(str)] = s[j];
		j++;
	}
}
 /**
  * datapercent- esta función reemplaza dos pocentajes por uno solo
  * @va_list: lista de argumentos de la funcion principal
  * @str: puntero donde se guardara la cadena para imprimirla luego
  */
void datapercent(va_list arguments __attribute__((unused)), char *str)
{
	str[strlen(str) + 1] = '\0';
	str[strlen(str)] = '%';
}
