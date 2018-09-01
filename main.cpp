#include <iostream>
#include "main.h"

run_info_t main_info;

inline void init() {
    init_log();
}

inline void clean() {
    clean_log();
}

int main(int argc, char *argv[]) {
    init();
    parse_args(argc, argv, main_info);
    clean();
    return 0;
}