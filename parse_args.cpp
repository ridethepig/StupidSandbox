//
// Created by unix on 18-9-1.
//

#include "include/parse_args.h"
#include "include/data.h"
#include "include/exitcode.h"

char *program_name;

void print_usage() {
    printf("Usage: %s [OPTION] PROGRAM \n", program_name);
    printf("Run and watch the contestant's PROGRAM. (Part of the Eeevee)\n");
    printf(
            "Options:\n"
            "  -t, --time=TIME_LIMIT           in ms, positive int only (default is 1000(1s))\n"
            "  -m, --memory=MEMORY_LIMIT       in KB, positive int only (default is 131072(128mb))\n"
            "  -p, --output-limit=OUTPUT_LIMIT in B, positive int only (default is 20971520(20mb))\n"
            "  -i, --input=INPUT_FILE          must in the same directory as PROGRAM\n"
            "      (file name must be identical with the problem description)\n"
            "  -o, --output=OUTPUT_FILENAME    the NAME of output file (should NOT exist!)\n"
            "  -h, --help                      print this help\n\n"
            "Output:\n"
            "  1.exited: WEXITSTATUS TIME(ms) MEMORY(KB)\n"
            "  2.killed: message\n"
            "Notes: PROGRAM must be compiled statically!\n");
}

int parse_args(int argc, char * argv[], run_info_t & run_info) {
    int longIndex = 0, opt = 0;
    opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    while (opt != -1) {
        switch (opt) {
            case 't': {
                int timeLimit = atoi(optarg);
                if (timeLimit <= 0)
                    ERROR(EXIT_ERROR, "TIME_LIMIT must be a positive integer.");
                run_info.set_time_limit(timeLimit);
                break;
            }
            case 'p': {
                int outLimit = atoi(optarg);
                if (outLimit <= 0)
                    ERROR(EXIT_ERROR, "OUTPUT_LIMIT must be a positive integer.");
                run_info.set_output_limit(outLimit);
                break;
            }
            case 'm': {
                int memoryLimit = atoi(optarg);
                if (memoryLimit <= 0)
                    ERROR(EXIT_ERROR, "MEMORY_LIMIT must be a positive integer.");
                run_info.set_memory_limit(memoryLimit);
                break;
            }
            case 'i': {
                if (optarg == nullptr) ERROR(EXIT_ERROR, "INPUT_FILE missing.");
                run_info.set_input_path(optarg);
                break;
            }
            case 'o': {
                if (optarg == nullptr) ERROR(EXIT_ERROR, "OUTPUT_FILE missing.");
                run_info.set_output_path(optarg);
                break;
            }
            case 'h':
                print_usage();
                return EXIT_ERROR;
            default:
                ERROR(EXIT_ERROR, "Please run 'caretaker --help' for more information.");
        }
        opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    }
    if (optind == argc) ERROR(EXIT_ERROR, "PROGRAM not specified.");
    else run_info.set_program_path(argv[optind]);
    return 0;
}