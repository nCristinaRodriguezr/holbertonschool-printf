#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct functions - Struct functions
 * @datatype: Apunta al tipo de dato o de especificador
 * @f: Funcion asociada
 */
typedef struct functions
{
	char *datatype;
	char *(*f)(va_list arguments, char *str);
} fun;
int _printf(const char *format, ...);
char *(*get_data(char *s))(va_list arguments, char *str);
char *datac(va_list arguments, char *str);
char *datas(va_list arguments, char *str);
#endif
