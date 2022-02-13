#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

enum log_type { ERROR, WARNING, INFO, NOLOG, NLOG };

void logger_log(enum log_type ltype, const char* format, ...);

#endif
