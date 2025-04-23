#include "../include/base.h"

void printSuccess(const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf("\033[32m");
    vprintf(format, args);
    printf("\033[0m");
    va_end(args);
}

void printError(const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf("\033[31m");
    vprintf(format, args);
    printf("\033[0m");
    va_end(args);
}

void printCentered(const char* text, int width) {
    int len = strlen(text);
    int pad = width - len;
    int left = pad / 2;
    int right = pad - left;

    for (int i = 0; i < left; ++i) putchar(' ');
    printf("%s", text);
    for (int i = 0; i < right; ++i) putchar(' ');
}

void printCenteredInt(int value, int width) {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", value);
    printCentered(buffer, width);
}

void printCenteredDouble(double value, int width, int precision) {
    char format[10];
    char buffer[32];

    snprintf(format, sizeof(format), "%%.%df", precision);
    snprintf(buffer, sizeof(buffer), format, value);
    printCentered(buffer, width);
}
