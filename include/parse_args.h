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

const char* program_name;
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

void print_usage() {
    printf("Usage: %s [OPTION] PROGRAM \n", program_name);
    printf("Run and watch the contestant's PROGRAM. (Part of the Eeevee)\n");
    printf(
            "Options:\n"
            "  -t, --time=TIME_LIMIT           in ms, positive int only (default is 1000)\n"
            "  -m, --memory=MEMORY_LIMIT       in KB, positive int only (default is 131072)\n"
            "  -p, --output-limit=OUTPUT_LIMIT in KB, positive int only (default is 20480)\n"
            "  -i, --input=INPUT_FILE          must in the same directory as PROGRAM\n"
            "      (file name must be identical with the problem description)\n"
            "  -o, --output=OUTPUT_FILENAME    the NAME of output file (should NOT exist!)\n"
            "  -h, --help                      print this help\n\n"
            "Output:\n"
            "  1.exited: WEXITSTATUS TIME(ms) MEMORY(KB)\n"
            "  2.killed: message\n"
            "Notes: PROGRAM must be compiled statically!\n");
}

int parse_args(int argc, char * argv[]);

#endif //STUPIDSANDBOX_PARSE_ARGS_H
