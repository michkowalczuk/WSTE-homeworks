#include <stdio.h>
#include <string.h>
#include "logger.h"

void logger(const char* date, const char* time, const char* filename, int line, const char* type, const char* info) {
    int tempLen;
    static int n = 0;
    static char buffer[BUFFER_LEN];
    char temp[BUFFER_LEN];
    FILE *file;

    // save log to temporary array
    sprintf(temp, "%s | %s | %s:%d | %s | %s\n", date, time, filename, line, type, info);

    // check if there is a space for new log in buffer or end of logging
    tempLen = strlen(temp);
    if ((n + tempLen  >= BUFFER_LEN) || strcmp(type, "END") == 0) {
        // save logs to file
        file = fopen("loggerOutput.txt","a");
        fprintf(file, "%s", buffer);
        fclose(file);

        // clear buffer
        buffer[0] = '\0';
        n = 0;
    }

    // append buffer with current log
    strcat(buffer, temp);
    n += tempLen;
}

int main() {
    // generate many logs
    LOG_ERROR("log bledu");
    for (size_t i = 0; i < 4; i++) {
        LOG_LOW("log niski");
    }
    LOG_ERROR("log bledu");
    for (size_t i = 0; i < 3; i++) {
        LOG_MEDIUM("log sredni");
    }
    LOG_ERROR("log bledu");
    for (size_t i = 0; i < 10; i++) {
        LOG_HIGH("log wysoki");
    }
    LOG_ERROR("log bledu");
    // at the end of work force saving buffer to file!
    LOGGER_END;

    return 0;
}
