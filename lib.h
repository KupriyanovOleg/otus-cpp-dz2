#pragma once

#include "ip.h"

#include <vector>

//int process();

/**
 * Парсит поток ввода и наполняет список валидными IP
 * @param vec
 */
void parse_from_input(std::vector<IP> &vec);

/**
 * Производит сортировку списка в обратном порядке
 * @param vec
 */
void sort_desc(std::vector<IP> &vec);

/**
 * Производит сортировку списка в прямом порядке
 * @param vec
 */
void sort_asc(std::vector<IP> &vec);

/**
 * Печатает список элементов, для которых функция вернула true
 * @param vec
 */
void print_vec(std::vector<IP> &vec);

/**
 * Печатает список элементов, для которых функция вернула true
 * @param vec
 */
void
print_vec(std::vector<IP> &vec, bool (*matches)(const IP &, const IP &, uint8_t), const IP &condition, uint8_t mask);