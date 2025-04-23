#include "../include/archive.h"
#include "../include/base.h"

void loadDataFromInput(Stack* stack, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла input.txt");
        exit(EXIT_FAILURE);
    }

    clearArchive(stack);
    char line[256];
    Tenant tenant;

    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, "|\n");
        if (!token) continue;
        tenant.cardNumber = atoi(token);

        token = strtok(NULL, "|\n");
        if (!token) continue;
        strncpy(tenant.fullName, token, sizeof(tenant.fullName));
        tenant.fullName[sizeof(tenant.fullName) - 1] = '\0';

        token = strtok(NULL, "|\n");
        if (!token) continue;
        tenant.residentCount = atoi(token);

        token = strtok(NULL, "|\n");
        if (!token) continue;
        strncpy(tenant.moveDate, token, sizeof(tenant.moveDate));
        tenant.moveDate[sizeof(tenant.moveDate) - 1] = '\0';

        token = strtok(NULL, "|\n");
        if (!token) continue;
        tenant.totalArea = atof(token);

        token = strtok(NULL, "|\n");
        if (!token) continue;
        tenant.excessArea = atof(token);

        push(stack, tenant);
    }

    fclose(file);
    reverseStack(stack);
    saveToArchive(stack, "archive.bin");
}

void loadDataFromKodif(Stack* stack, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла kodif.txt");
        exit(EXIT_FAILURE);
    }

    clearArchive(stack);
    char line[256];
    Tenant tenant;

    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, "|\n");
        if (!token) continue;
        tenant.cardNumber = atoi(token);

        token = strtok(NULL, "|\n");
        if (!token) continue;
        strncpy(tenant.address, token, sizeof(tenant.address));
        tenant.address[sizeof(tenant.address) - 1] = '\0';

        push(stack, tenant);
    }

    fclose(file);
    reverseStack(stack);
    saveToArchive(stack, "archive.bin");
}

void saveToArchive(Stack* stack, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка создания архива");
        return;
    }

    StackNode* current = stack->top;
    while (current != NULL) {
        fwrite(&(current->data), sizeof(Tenant), 1, file);
        current = current->next;
    }
    fclose(file);
}

void printArchiveInput(const Stack* stack) {
    StackNode* current = stack->top;

    printSuccess("\nДанные архива (формат input.txt):\n");
    printf("+----------+----------------------+------------+------------+--------------+------------+\n");
    printf("|  Номер   |         ФИО          |   Жители   |    Дата    |   Площадь    |   Избыток  |\n");
    printf("+----------+----------------------+------------+------------+--------------+------------+\n");

    while (current != NULL) {
        printf("| ");
        printCenteredInt(current->data.cardNumber, 8);
        printf(" | ");
        printCentered(current->data.fullName, 20);
        printf(" | ");
        printCenteredInt(current->data.residentCount, 10);
        printf(" | ");
        printCentered(current->data.moveDate, 10);
        printf(" | ");
        printCenteredDouble(current->data.totalArea, 12, 2);
        printf(" | ");
        printCenteredDouble(current->data.excessArea, 10, 2);
        printf(" |\n");

        current = current->next;
    }

    printf("+----------+----------------------+------------+------------+--------------+------------+\n");
}


void printArchiveKodif(const Stack* stack) {
    StackNode* current = stack->top;

    printSuccess("\nДанные архива (формат kodif.txt):\n");
    printf("+----------+--------------------------------+\n");
    printf("|  Номер   |             Адрес              |\n");
    printf("+----------+--------------------------------+\n");

    while (current != NULL) {
        printf("| ");
        printCenteredInt(current->data.cardNumber, 8);
        printf(" | ");
        printCentered(current->data.address, 30);
        printf(" |\n");

        current = current->next;
    }

    printf("+----------+--------------------------------+\n");
}


void clearArchive(Stack* stack) {
    while (!isEmpty(stack)) {
        StackNode* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->size = 0;
}

void loadArchiveFromBin(Stack* stack, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка при открытии архива");
        return;
    }

    clearArchive(stack);
    Tenant tenant;

    while (fread(&tenant, sizeof(Tenant), 1, file) == 1) {
        push(stack, tenant);
    }

    reverseStack(stack);
    fclose(file);
}

// По общей площади
void shellSort(const char* filename) {
    FILE* file = fopen(filename, "rb+");
    if (!file) {
        perror("Не удалось открыть архив для сортировки");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    int count = size / sizeof(Tenant);
    rewind(file);

    Tenant* tenant = malloc(size);
    if (!tenant) {
        perror("Не удалось выделить память");
        fclose(file);
        return;
    }

    fread(tenant, sizeof(Tenant), count, file);

    for (int gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; i++) {
            Tenant temp = tenant[i];
            int j;
            for (j = i; j >= gap && tenant[j - gap].totalArea > temp.totalArea; j -= gap) {
                tenant[j] = tenant[j - gap];
            }
            tenant[j] = temp;
        }
    }

    rewind(file);
    fwrite(tenant, sizeof(Tenant), count, file);

    printSuccess("Архив отсортирован Школьным Методом\n");

    free(tenant);
    fclose(file);
}