//
// Created by unix on 18-9-1.
//

#include "include/log.h"
#include "include/exitcode.h"
#include "include/stringutils.h"


FILE* log_file;

static inline std::string get_time() {
    time_t cur_time;
    time(&cur_time);
    std::string time_str = asctime(gmtime(&cur_time));
    remove_all(time_str, "\n");
    return time_str;
}

int init_log(){
    log_file = fopen(default_log_path.c_str(), "a+");
    if (log_file == nullptr) {
        fprintf(stderr, "Cannot create or open-append log file : %s\n", default_log_path.c_str());
        return ERR_FILE;
    }
    fprintf(log_file, "[%s] Start logging.\n", get_time().c_str());
    return 0;
}

int clean_log() {
    fprintf(log_file, "[%s] Stop logging.\n", get_time().c_str());
    return fclose(log_file);
}