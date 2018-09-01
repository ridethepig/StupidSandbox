//
// Created by unix on 18-9-1.
//

#ifndef STUPIDSANDBOX_PATHUTILS_H
#define STUPIDSANDBOX_PATHUTILS_H

#include <string>
#include <fstream>

bool file_exist(const std::string & path) {
    std::fstream test_stream;
    test_stream.open(path);
    if (!test_stream) {
        return false;
    }
    test_stream.close();
    return true;
}

bool dir_exist(const std::string & Path) {
    std::string path = Path;
    size_t len = path.length();
    if(path[len-1] != '/' && path[len-1] != '\\')
        path.append("/");
    path.append("000.tmp");
    std::ofstream test_stream;
    test_stream.open(path);
    bool flag = test_stream;
    if(test_stream)
    {
        test_stream.close();
        remove(path.c_str());
    }
    return flag;
}

#endif //STUPIDSANDBOX_PATHUTILS_H
