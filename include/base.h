/**
 * @file base.h
 * @brief Базовые структуры данных и функции работы со стеком для архива жильцов.
 *
 * Данный заголовочный файл определяет основные структуры данных и функции
 * для работы с архивом жильцов, организованным в виде стека.
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>

 /**
  * @def MAX_NAME_LENGTH
  * @brief Максимальная длина строки с ФИО жильца.
  */
#define MAX_NAME_LENGTH 30

  /**
   * @def MAX_ADDRESS_LENGTH
   * @brief Максимальная длина строки с адресом проживания.
   */
#define MAX_ADDRESS_LENGTH 50

   /**
    * @def DATE_LENGTH
    * @brief Длина строки с датой (в формате DD.MM.YYYY) включая нуль-терминатор.
    */
#define DATE_LENGTH 11

    /**
     * @struct Tenant
     * @brief Структура для хранения информации о жильце.
     *
     * Содержит полные данные о зарегистрированном жильце. Используется
     * в архивах input.txt и kodif.txt.
     */
typedef struct Tenant {
    int cardNumber;                          /**< Номер карточки жильца (уникальный идентификатор). */
    char address[MAX_ADDRESS_LENGTH];        /**< Адрес проживания. */
    char fullName[MAX_NAME_LENGTH];          /**< Полное имя жильца. */
    int residentCount;                       /**< Количество проживающих. */
    char moveDate[DATE_LENGTH];              /**< Дата заселения в формате DD.MM.YYYY. */
    double totalArea;                        /**< Общая площадь помещения. */
    double excessArea;                       /**< Избыточная площадь. */
} Tenant;

/**
 * @struct StackNode
 * @brief Узел стека, содержащий данные одного жильца.
 */
typedef struct StackNode StackNode;

/**
 * @brief Структура узла стека.
 *
 * Связанный элемент, хранящий данные жильца и указатель на следующий элемент.
 */
struct StackNode {
    Tenant data;         /**< Данные жильца. */
    StackNode* next;     /**< Указатель на следующий элемент стека. */
};

/**
 * @struct Stack
 * @brief Структура стека для хранения данных жильцов.
 *
 * Управляет вершиной стека и отслеживает количество элементов.
 */
typedef struct {
    StackNode* top;      /**< Указатель на вершину стека. */
    int size;            /**< Текущее количество элементов в стеке. */
} Stack;

/**
 * @enum ArchiveFormat
 * @brief Формат загруженного архива.
 *
 * Используется для контроля типа загруженных данных и предотвращения
 * смешивания разных форматов архивов.
 */
typedef enum ArchiveFormat {
    NONE,           /**< Архив не загружен. */
    INPUT_FORMAT,   /**< Данные загружены из файла input.txt. */
    KODIF_FORMAT    /**< Данные загружены из файла kodif.txt. */
} ArchiveFormat;

/**
 * @brief Инициализирует стек.
 *
 * Устанавливает начальные значения указателя на вершину стека (NULL)
 * и обнуляет счетчик элементов.
 *
 * @param stack Указатель на структуру стека для инициализации.
 */
void initStack(Stack* stack);

/**
 * @brief Добавляет элемент в стек.
 *
 * Создает новый узел и помещает его на вершину стека.
 *
 * @param stack Указатель на стек.
 * @param tenant Данные жильца для добавления.
 */
void push(Stack* stack, Tenant tenant);

/**
 * @brief Извлекает элемент из стека.
 *
 * Удаляет верхний элемент стека и копирует его данные в переданную структуру.
 *
 * @param stack Указатель на стек.
 * @param tenant Указатель на структуру для сохранения данных.
 */
void pop(Stack* stack, Tenant* tenant);

/**
 * @brief Проверяет, пуст ли стек.
 *
 * @param stack Указатель на стек для проверки.
 * @return 1 если стек пуст, 0 если содержит элементы.
 */
int isEmpty(const Stack* stack);

/**
 * @brief Реверсирует порядок элементов в стеке.
 *
 * Изменяет порядок элементов стека на противоположный.
 *
 * @param stack Указатель на стек для реверсирования.
 */
void reverseStack(Stack* stack);