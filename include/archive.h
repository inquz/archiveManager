/**
 * @file archive.h
 * @brief ������ � ������� �������
 *
 * ������������ ���� �������� ������� ��� ��������, ����������, �����������
 * � ���������� ������� �������, �������������� � ���� �����.
 */

#pragma once
#include "base.h"

 /**
  * @brief ��������� ������ �� ����� ������� input.txt
  *
  * ������ ������ �� ���������� ����� � ������� input.txt � �������� �� � ����.
  * ������ ����� ������ ��������� ������ ������ � �������.
  *
  * @param stack ��������� �� ���� ��� ����������
  * @param filename ��� ����� ��� ������ (input.txt)
  *
  * @note ������ ����� input.txt:
  * �����_����� ����� ��� ���-��_������� ����_��������� �����_������� ����������_�������
  */
void loadDataFromInput(Stack* stack, const char* filename);

/**
 * @brief ��������� ������ �� ����� ������� kodif.txt
 *
 * ������ ������ �� ���������� ����� � ������� kodif.txt � �������� �� � ����.
 * ������ ����� �������� ������������ ����� ������ � �������.
 *
 * @param stack ��������� �� ���� ��� ����������
 * @param filename ��� ����� ��� ������ (kodif.txt)
 *
 * @note ������ ����� kodif.txt:
 * �����_����� ����� ��� ���-��_�������
 */
void loadDataFromKodif(Stack* stack, const char* filename);

/**
 * @brief ��������� ������ ����� � �������� ����
 *
 * ���������� ��� ������ �� ����� � �������� ���� ��� ������������ ��������������.
 *
 * @param stack ��������� �� ���� � �������
 * @param filename ��� ��������� ����� ��� ����������
 */
void saveToArchive(Stack* stack, const char* filename);

/**
 * @brief ������� ����� � ������� input.txt
 *
 * ���������� ���������� ����� � ��������� ����, ��������������� ������� input.txt,
 * �� ����� ������ ��������� Tenant.
 *
 * @param stack ��������� �� ���� ��� �����������
 */
void printArchiveInput(const Stack* stack);

/**
 * @brief ������� ����� � ������� kodif.txt
 *
 * ���������� ���������� ����� � ��������� ����, ��������������� ������� kodif.txt,
 * ������ � ��������� ������ ���������� � �������.
 *
 * @param stack ��������� �� ���� ��� �����������
 */
void printArchiveKodif(const Stack* stack);

/**
 * @brief ������� �����
 *
 * ������� ��� �������� �� ����� � ����������� ���������� ������.
 * ����� ���������� ���� �������� ������ � ������� � ���������� �������������.
 *
 * @param stack ��������� �� ���� ��� �������
 */
void clearArchive(Stack* stack);

/**
 * @brief ��������� ����� �� ��������� �����
 *
 * ��������������� ���� �� ����� ������������ ��������� �����.
 *
 * @param stack ��������� �� ���� ��� ����������
 * @param filename ��� ��������� ����� ��� ��������
 */
void loadArchiveFromBin(Stack* stack, const char* filename);

/**
 * @brief ��������� ������ �������� �������
 *
 * ��������� ������ � ����� �������� ������� �� ���-�� �������.
 *
 * @param filename ��� ����� ��� ����������
 */
void shellSort(const char* filename);