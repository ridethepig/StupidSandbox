//
// Created by unix on 18-9-1.
//

#ifndef STUPIDSANDBOX_LOG_H
#define STUPIDSANDBOX_LOG_H

#include <string>
#include <cstdio>

const std::string default_log_path = "./sandbox.log";

FILE* log_file;

int init_log();
int clean_log();

#define write_log(log, ...) (fprintf(log_file, log, __VA_ARGS))

#endif //STUPIDSANDBOX_LOG_H
