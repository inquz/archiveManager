#include "include/base.h"

int main() {
#ifdef _WIN32
    system("chcp 1251");
#endif

    mainMenu();

    return 0;
}