#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define LOG_LOW(info) logger(__DATE__, __TIME__, __FILENAME__, __LINE__, "LOW", info)
#define LOG_MEDIUM(info) logger(__DATE__, __TIME__, __FILENAME__, __LINE__, "MEDIUM", info)
#define LOG_HIGH(info) logger(__DATE__, __TIME__, __FILENAME__, __LINE__, "HIGH", info)
#define LOG_ERROR(info) logger(__DATE__, __TIME__, __FILENAME__, __LINE__, "ERROR", info)
#define LOGGER_END logger(__DATE__, __TIME__, __FILENAME__, __LINE__, "END","")

#define BUFFER_LEN 150

void logger(const char* date, const char* time, const char* file, int line, const char* type, const char* info);
