//
// Created by unix on 18-9-1.
//

#ifndef STUPIDSANDBOX_PARSE_ARGS_H
#define STUPIDSANDBOX_PARSE_ARGS_H

#include <getopt.h>
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
    exit(0);
}

int parse_args(int argc, const char * argv[]) {
    int longIndex = 0, opt = 0;
    opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    while (opt != -1) {
        switch (opt) {
            case 't':
                timeLimit = atoi(optarg);
                if (timeLimit <= 0) error(EX_ERROR, 0,
                                          "TIME_LIMIT must be a positive integer.");
                break;

            case 'm':
                memoryLimit = atoi(optarg);
                if (memoryLimit <= 0) error(EX_ERROR, 0,
                                            "MEMORY_LIMIT must be a positive integer.");
                break;

            case 'i':
                if (optarg == 0) error(EX_ERROR, 0, "INPUT_FILE missing.");
                infileName = optarg;
                break;

            case 'o':
                if (optarg == 0) error(EX_ERROR, 0, "OUTPUT_FILE missing.");
                outfileName = optarg;
                break;

            case 'h':
                print_usage();
                break;



            default:
                error(EX_ERROR, 0,
                      "Please run 'caretaker --help' for more information.");
                break;
        }
        opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    }
    if (optind == argc) error(EX_ERROR, 0, "PROGRAM not specified.");
    else prgfileName = argv[optind];
}

#endif //STUPIDSANDBOX_PARSE_ARGS_H
