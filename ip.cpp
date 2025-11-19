#include "ip.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ranges>

using namespace std;

IP::IP() {
}

IP::IP(const std::string &str) {
    valid = parse_from_string(str);
}

IP::IP(uint8_t o0, uint8_t o1, uint8_t o2, uint8_t o3)
        : octets({o0, o1, o2, o3}), valid(true) {
}

// Return string representation of IP
std::string IP::toString() const {
    return std::to_string(octets[0]) + "." +
           std::to_string(octets[1]) + "." +
           std::to_string(octets[2]) + "." +
           std::to_string(octets[3]);
}

/**
 * Parse IP value from string str.
 * @param str
 * @return
 */
bool IP::parse_from_string(const std::string &str) {
    octets.fill(0);
    valid = false;
    bool is_prev_dot = false;

    // 1.1.1.1
    if (str.length() < 7)
        return false;

    // TODO: v заменить на octets[n]
    // TODO: проверить на две точки подряд. Сейчас считается что октет равен 0.
    uint8_t v(0), /*i(0),*/ n(0);


    for (auto &c: str) {
        if (c == '.') {
            // false если точка после 4го октета
            if (n == 3)
                return false;
            // предыдущий символ тоже точка
            if (is_prev_dot)
                return false;
            octets[n++] = v;
            v = 0;
            is_prev_dot = true;
            continue;
        }
        is_prev_dot = false;
        // false если не число
        if (c < '0' || c > '9')
            return false;

        // false если намечается число больше 255
        if (v > 25)
            return false;
        v *= 10;
        // false если число больше 255
        if (v == 250 && (c - '0') > 5)
            return false;
        v += c - '0';
    }
    octets[n++] = v;
    if (n != 4)
        return false;
    valid = true;
    return true;
}

/**
 * Возвращает true если значение cond для ip удовлетворяет условию cond по маске mask.
 * Для октетов используется логический оператор И.
 * False для невалидного или пустой маски.
 * @return
 */
bool IP::matchesAll(const IP &ip, const IP &cond, uint8_t mask) {
    return ip.is_valid()
           && cond.is_valid()
           && mask
           && (!(mask & EMatchMask::o0) || (ip.octets[0] == cond.octets[0]))
           && (!(mask & EMatchMask::o1) || (ip.octets[1] == cond.octets[1]))
           && (!(mask & EMatchMask::o2) || (ip.octets[2] == cond.octets[2]))
           && (!(mask & EMatchMask::o3) || (ip.octets[3] == cond.octets[3]));
}

/**
 * Возвращает true если значение cond для ip удовлетворяет условию cond по маске mask.
 * Для октетов используется логический оператор И.
 * False для невалидного или пустой маски.
 * @return
 */
bool IP::matchesAny(const IP &ip, const IP &cond, uint8_t mask) {
    return ip.is_valid()
           && cond.is_valid()
           && mask
           && ((!(mask & EMatchMask::o0) || (ip.octets[0] == cond.octets[0]))
               || (!(mask & EMatchMask::o1) || (ip.octets[1] == cond.octets[1]))
               || (!(mask & EMatchMask::o2) || (ip.octets[2] == cond.octets[2]))
               || (!(mask & EMatchMask::o3) || (ip.octets[3] == cond.octets[3])));
}

// return true if left < right
bool IP::compare_asc(const IP &l, const IP &r) {
    for (int i = 0; i <= 3; i++) {
        if (r.octets[i] == l.octets[i])
            continue;
        if (l.octets[i] < r.octets[i])
            return true;
        return false;
    }
    return true;
}


bool IP::compare_desc(const IP &l, const IP &r) {
    for (int i = 0; i <= 3; i++) {
        if (r.octets[i] == l.octets[i])
            continue;
        if (l.octets[i] > r.octets[i])
            return true;
        return false;
    }
    return true;
}
