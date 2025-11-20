#include "lib.h"


int main(int, char **) {
    std::forward_list<IP> list;
    parse_from_input(list);
    sort_desc(list);
    print_lst(list);
    print_lst(list, IP::matchesAll, IP(1, 0, 0, 0), IP::o0);
    print_lst(list, IP::matchesAll, IP(46, 70, 0, 0), IP::o0 | IP::o1);
    print_lst(list, IP::matchesAny, IP(46, 46, 46, 46), IP::all);
    return 0;
}
