//
// Created by unix on 18-9-1.
//

#ifndef STUPIDSANDBOX_EXITCODE_H
#define STUPIDSANDBOX_EXITCODE_H

const int ERR_FILE = 32767;
const int EXIT_ERROR = 1;

#define ERRORF(EXIT_CODE, INFO, ...) do { fprintf(stderr, INFO, __VA_ARGS__); return EXIT_CODE; } while(0)
#define ERROR(EXIT_CODE, INFO) do { fprintf(stderr, INFO); return EXIT_CODE; } while(0)

#endif //STUPIDSANDBOX_EXITCODE_H
