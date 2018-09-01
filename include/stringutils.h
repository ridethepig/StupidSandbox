//
// Created by unix on 18-9-1.
//

#ifndef STUPIDSANDBOX_STRINGUTILS_H
#define STUPIDSANDBOX_STRINGUTILS_H

#include <string>

inline void remove_all(std::string & src, const std::string & tar, const std::string & rep = "") {
    size_t _begin_ = 0;
    _begin_ = src.find(tar, _begin_);
    while (_begin_ != -1) {
        src.replace(_begin_, 1, rep);
        _begin_ = src.find(tar, _begin_);
    }
}

inline void remove_ws(std::string & src) {
    remove_all(src, " ");
    remove_all(src, "\n");
    remove_all(src, "\r");
    remove_all(src, "\t");
}

inline void remove_remainws(std::string & src) {
    remove_all(src, "\n");
    remove_all(src, "\r");
    remove_all(src, "\t");
}

#endif //STUPIDSANDBOX_STRINGUTILS_H
