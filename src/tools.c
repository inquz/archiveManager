#include "../include/base.h"

void deleteArchive(const char* filename) {
    if (remove(filename) == 0) {
        printSuccess("����� ������� �����.\n", filename);
    }
    else {
        printError("����� ��� ������!\n");
    }
}