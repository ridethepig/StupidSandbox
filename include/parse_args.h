//
// Created by unix on 18-9-1.
//

#ifndef STUPIDSANDBOX_PARSE_ARGS_H
#define STUPIDSANDBOX_PARSE_ARGS_H

#include <getopt.h>
#include <unistd.h>
#include <error.h>
#include <cstdio>
#include <cstdlib>
#include "data.h"

extern char* program_name;
static const char *optString = "t:m:p:i:o:h";
static const struct option longOpts[] = {
        {"time", required_argument, nullptr, 't'},
        {"memory", required_argument, nullptr, 'm'},
        {"output-limit", required_argument, nullptr, 'p'},
        {"input", required_argument, nullptr, 'i'},
        {"output", required_argument, nullptr, 'o'},
        {"help", no_argument, nullptr, 'h'},
        { nullptr, no_argument, nullptr, 0 }
};

void print_usage();

int parse_args(int argc, char * argv[], run_info_t & run_info);

#endif //STUPIDSANDBOX_PARSE_ARGS_H
