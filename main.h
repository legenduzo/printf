#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>

int _printf(const char *format, ...);
int write_char(va_list *args);
int write_int(va_list *args);
int write_string(va_list *args);

#endif /* _MAIN_H_ */
