#pragma once

#include "ip.h"

#include <forward_list>

/**
 * Парсит поток ввода и наполняет список валидными IP
 * @param lst
 */
void parse_from_input(std::forward_list<IP> &lst);

/**
 * Производит сортировку списка в обратном порядке
 * @param lst
 */
void sort_desc(std::forward_list<IP> &lst);

/**
 * Производит сортировку списка в прямом порядке
 * @param lst
 */
void sort_asc(std::forward_list<IP> &lst);

/**
 * Печатает список элементов, для которых функция вернула true
 * @param lst
 */
void print_lst(std::forward_list<IP> &lst);

/**
 * Печатает список элементов, для которых функция вернула true
 * @param lst
 */
void
print_lst(std::forward_list<IP> &lst, bool (*matches)(const IP &, const IP &, uint8_t), const IP &condition, uint8_t mask);