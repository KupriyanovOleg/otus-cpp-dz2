#include "lib.h"


int main(int, char **) {
    std::vector<IP> vec;
    parse_from_input(vec);
    sort_desc(vec);
    print_vec(vec);

    print_vec(vec, IP::matchesAll, IP(1, 0, 0, 0), IP::o0);

    print_vec(vec, IP::matchesAll, IP(46, 70, 0, 0), IP::o0 | IP::o1);

    print_vec(vec, IP::matchesAny, IP(46, 46, 46, 46), IP::all);

    return 0;
}
