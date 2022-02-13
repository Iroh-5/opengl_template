#include "../include/logging.h"

static const char* const log_str[NOLOG] = 
{
    [ERROR]    = "ERROR",
    [WARNING]  = "WARNING",
    [INFO]     = "INFO"
};

static const char* const colors[NLOG] = 
{
    [ERROR]     = "\033[0;31m",
    [WARNING]   = "\033[1;33m",
    [INFO]      = "\033[0;32m",
    [NOLOG]     = "\033[0m"
};

void logger_log(enum log_type ltype, const char* format, ...)
{
    fprintf(stderr, "%s[%s]: ", colors[ltype], log_str[ltype]);

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    fprintf(stderr, "%s", colors[NOLOG]);

    if (ltype == ERROR)
	exit(EXIT_FAILURE);
}
