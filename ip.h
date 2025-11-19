#pragma once

#include <cstdint>
#include <string>
#include <array>

using namespace std;

/**
 * Describes IP
 */
class IP {

private:
    std::array<uint8_t, 4> octets = {0, 0, 0, 0};
    bool valid = false;

    /**
     * Parse IP value from string str.
     * @param str
     * @return
     */
    bool parse_from_string(const std::string &str);

public:
    /**
     * Маска учитываемых октетов для фильтрации
     */
    enum EMatchMask {
        o0 = 0b1000,
        o1 = 0b0100,
        o2 = 0b0010,
        o3 = 0b0001,
        all = o0 | o1 | o2 | o3
    };

    IP();

    IP(const std::string &str);
//    IP( const& IP ) = default;

    IP(uint8_t o0, uint8_t o1, uint8_t o2, uint8_t o3);

    // Return string representation of IP
    string toString() const;

    /**
     * Returns true, if IP is valid.
     * @return
     */
    inline bool is_valid() const { return valid; }

    /**
     * Возвращает true если значение cond для ip удовлетворяет условию cond по маске mask.
     * Для октетов используется логический оператор И.
     * False для невалидного или пустой маски.
     * @return
     */
    static bool matchesAll(const IP &ip, const IP &cond, uint8_t mask);

    /**
     * Возвращает true если значение cond для ip удовлетворяет условию cond по маске mask.
     * Для октетов используется логический оператор ИЛИ.
     * False для невалидного или пустой маски.
     * @return
     */
    static bool matchesAny(const IP &ip, const IP &cond, uint8_t mask);

    /**
     * Return true if left less then right.
     * Usefull for ascending sort.
     * @param left
     * @param right
     * @return  true if left less then right.
     */
    static bool compare_asc(const IP &l, const IP &r);


    /**
     * Return true if left less then right.
     * Usefull for descending sort.
     * @param left
     * @param right
     * @return  true if left less then right.
     */
    static bool compare_desc(const IP &l, const IP &r);


};



