#include "lib.h"

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Парсит поток ввода и наполняет список валидными IP
 * @param vec
 */
void parse_from_input(std::vector<IP> &vec) {
    vec.clear();
    for (std::string line; std::getline(std::cin, line);) {
        std::string::size_type stop = line.find_first_of('\t');
        if (auto ip = IP(line.substr(0, stop)); ip.is_valid())
            vec.push_back(ip);
    }
}

/**
 * Производит сортировку списка в обратном порядке
 * @param vec
 */
void sort_desc(std::vector<IP> &vec) {
    std::sort(vec.begin(), vec.end(), IP::compare_desc);
}

/**
 * Производит сортировку списка в прямом порядке
 * @param vec
 */
void sort_asc(std::vector<IP> &vec) {
    std::sort(vec.begin(), vec.end(), IP::compare_asc);
}


/**
 * Печатает список
 * @param vec
 */
void print_vec(std::vector<IP> &vec) {
    for (const auto &ip : vec) {
        std::cout << ip.toString() << std::endl;
    }
}

/**
 * Печатает список элементов, для которых функция вернула true
 * @param vec
 */
void
print_vec(std::vector<IP> &vec, bool (*matches)(const IP &, const IP &, uint8_t), const IP &condition, uint8_t mask) {
    for (const auto &ip : vec) {
        if (matches(ip, condition, mask))
            std::cout << ip.toString() << std::endl;
    }
}


void print_vec_if(std::vector<IP> &vec) {
    for (const auto &ip : vec) {
        std::cout << ip.toString() << std::endl;
    }
}
