//
// Created by unix on 18-9-1.
//

#ifndef STUPIDSANDBOX_DATA_H
#define STUPIDSANDBOX_DATA_H

#include <string>

typedef struct RUN_INFO_H{
public:
    int get_memory_limit() const { return memory_limit; }
    int get_time_limit  () const { return time_limit;   }
    int get_output_limit() const { return output_limit; }
    void set_memory_limit(int val) { memory_limit = val; }
    void set_time_limit  (int val) { time_limit = val;   }
    void set_output_limit(int val) { output_limit = val; }

    std::string get_input_filepath() { return input_filepath; }
    std::string get_out_filepath  () { return output_filepath; }

    void set_input_filepath (const std::string& src) {
        input_filepath = src;
        parse_file_path(input_filepath);
    }
    void set_output_filepath(const std::string& src) {
        output_filepath = src;
        parse_file_path(output_filepath);
    }
private:
    int memory_limit,
        time_limit,
        output_limit;
    std::string input_filepath;
    std::string output_filepath;
    void parse_file_path(std::string & path) const {

    }
} run_info_t;

#endif //STUPIDSANDBOX_DATA_H
