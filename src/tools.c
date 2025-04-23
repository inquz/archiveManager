#include "../include/base.h"

void deleteArchive(const char* filename) {
    if (remove(filename) == 0) {
        printSuccess("Архив успешно удалён.\n", filename);
    }
    else {
        printError("Архив уже удален!\n");
    }
}