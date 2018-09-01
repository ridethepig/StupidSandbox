//
// Created by unix on 18-9-1.
//

#ifndef STUPIDSANDBOX_DATA_H
#define STUPIDSANDBOX_DATA_H

#include <string>

typedef struct RUN_INFO_H{
public:
    void enable_check() { check_enabled = true; }
    void disable_check() { check_enabled = false; }
    int get_memory_limit() const { return memory_limit; }
    int get_time_limit  () const { return time_limit;   }
    int get_output_limit() const { return output_limit; }
    void set_memory_limit(int val) { memory_limit = val; }
    void set_time_limit  (int val) { time_limit = val;   }
    void set_output_limit(int val) { output_limit = val; }

    std::string get_input_path  () { return input_path;   }
    std::string get_output_path () { return output_path;  }
    std::string get_program_path() { return program_path; }
    void set_input_path(const std::string &src) {
        input_path = src;
        parse_file_path(input_path);
    }
    void set_output_path(const std::string &src) {
        output_path = src;
        parse_file_path(output_path);
    }
    void set_program_path(const std::string &src) {
        program_path = src;
        parse_file_path(program_path);
    }
private:
    bool check_enabled = true;
    int memory_limit,
        time_limit,
        output_limit;
    std::string input_path;
    std::string output_path;
    std::string program_path;
    void parse_file_path(std::string & path) const {

    }
} run_info_t;

#endif //STUPIDSANDBOX_DATA_H
