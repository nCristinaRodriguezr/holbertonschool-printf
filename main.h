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
	void (*f)(va_list arguments, char *str);
} fun;
int _printf(const char *format, ...);
void get_data(const char *format, va_list arguments, char *str);
void datac(va_list arguments, char *str);
void datas(va_list arguments, char *str);
void datap(va_list arguments __attribute__((unused)), char *str);
#endif

