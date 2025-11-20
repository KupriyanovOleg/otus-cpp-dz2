#include "lib.h"

#include <iostream>
#include <algorithm>

/**
 * Парсит поток ввода и наполняет список валидными IP
 * @param lst
 */
void parse_from_input(std::forward_list<IP> &lst) {
    lst.clear();
    auto iter = lst.before_begin();
    for (std::string line; std::getline(std::cin, line);) {
        std::string::size_type stop = line.find_first_of('\t');
        if (auto ip = IP(line.substr(0, stop)); ip.is_valid())
            iter = lst.emplace_after( iter, ip );
    }
    if( lst.begin() != lst.end() )
        std::cout <<"not null!\n";
}

/**
 * Производит сортировку списка в обратном порядке
 * @param lst
 */
void sort_desc(std::forward_list<IP> &lst) {
    lst.sort(IP::compare_desc);
}

/**
 * Производит сортировку списка в прямом порядке
 * @param lst
 */
void sort_asc(std::forward_list<IP> &lst) {
    lst.sort(IP::compare_asc);
}


/**
 * Печатает список
 * @param lst
 */
void print_lst(std::forward_list<IP> &lst) {
    for (const auto &ip : lst) {
        std::cout << ip.toString() << std::endl;
    }
}

/**
 * Печатает список элементов, для которых функция вернула true
 * @param lst
 */
void
print_lst(std::forward_list<IP> &lst, bool (*matches)(const IP &, const IP &, uint8_t), const IP &condition, uint8_t mask) {
    for (const auto &ip : lst) {
        if (matches(ip, condition, mask))
            std::cout << ip.toString() << std::endl;
    }
}

