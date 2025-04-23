/**
 * @file base.h
 * @brief ������� ��������� ������ � ������� ������ �� ������ ��� ������ �������.
 *
 * ������ ������������ ���� ���������� �������� ��������� ������ � �������
 * ��� ������ � ������� �������, �������������� � ���� �����.
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
  * @brief ������������ ����� ������ � ��� ������.
  */
#define MAX_NAME_LENGTH 30

  /**
   * @def MAX_ADDRESS_LENGTH
   * @brief ������������ ����� ������ � ������� ����������.
   */
#define MAX_ADDRESS_LENGTH 50

   /**
    * @def DATE_LENGTH
    * @brief ����� ������ � ����� (� ������� DD.MM.YYYY) ������� ����-����������.
    */
#define DATE_LENGTH 11

    /**
     * @struct Tenant
     * @brief ��������� ��� �������� ���������� � ������.
     *
     * �������� ������ ������ � ������������������ ������. ������������
     * � ������� input.txt � kodif.txt.
     */
typedef struct Tenant {
    int cardNumber;                          /**< ����� �������� ������ (���������� �������������). */
    char address[MAX_ADDRESS_LENGTH];        /**< ����� ����������. */
    char fullName[MAX_NAME_LENGTH];          /**< ������ ��� ������. */
    int residentCount;                       /**< ���������� �����������. */
    char moveDate[DATE_LENGTH];              /**< ���� ��������� � ������� DD.MM.YYYY. */
    double totalArea;                        /**< ����� ������� ���������. */
    double excessArea;                       /**< ���������� �������. */
} Tenant;

/**
 * @struct StackNode
 * @brief ���� �����, ���������� ������ ������ ������.
 */
typedef struct StackNode StackNode;

/**
 * @brief ��������� ���� �����.
 *
 * ��������� �������, �������� ������ ������ � ��������� �� ��������� �������.
 */
struct StackNode {
    Tenant data;         /**< ������ ������. */
    StackNode* next;     /**< ��������� �� ��������� ������� �����. */
};

/**
 * @struct Stack
 * @brief ��������� ����� ��� �������� ������ �������.
 *
 * ��������� �������� ����� � ����������� ���������� ���������.
 */
typedef struct {
    StackNode* top;      /**< ��������� �� ������� �����. */
    int size;            /**< ������� ���������� ��������� � �����. */
} Stack;

/**
 * @enum ArchiveFormat
 * @brief ������ ������������ ������.
 *
 * ������������ ��� �������� ���� ����������� ������ � ��������������
 * ���������� ������ �������� �������.
 */
typedef enum ArchiveFormat {
    NONE,           /**< ����� �� ��������. */
    INPUT_FORMAT,   /**< ������ ��������� �� ����� input.txt. */
    KODIF_FORMAT    /**< ������ ��������� �� ����� kodif.txt. */
} ArchiveFormat;

/**
 * @brief �������������� ����.
 *
 * ������������� ��������� �������� ��������� �� ������� ����� (NULL)
 * � �������� ������� ���������.
 *
 * @param stack ��������� �� ��������� ����� ��� �������������.
 */
void initStack(Stack* stack);

/**
 * @brief ��������� ������� � ����.
 *
 * ������� ����� ���� � �������� ��� �� ������� �����.
 *
 * @param stack ��������� �� ����.
 * @param tenant ������ ������ ��� ����������.
 */
void push(Stack* stack, Tenant tenant);

/**
 * @brief ��������� ������� �� �����.
 *
 * ������� ������� ������� ����� � �������� ��� ������ � ���������� ���������.
 *
 * @param stack ��������� �� ����.
 * @param tenant ��������� �� ��������� ��� ���������� ������.
 */
void pop(Stack* stack, Tenant* tenant);

/**
 * @brief ���������, ���� �� ����.
 *
 * @param stack ��������� �� ���� ��� ��������.
 * @return 1 ���� ���� ����, 0 ���� �������� ��������.
 */
int isEmpty(const Stack* stack);

/**
 * @brief ����������� ������� ��������� � �����.
 *
 * �������� ������� ��������� ����� �� ���������������.
 *
 * @param stack ��������� �� ���� ��� ��������������.
 */
void reverseStack(Stack* stack);