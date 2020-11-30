#ifndef CLI_H
#define CLI_H

#include <exception>
#include <cstring>
#include <iostream>

class CLIException : public std::runtime_error {
public:
    explicit CLIException(const std::string &fail_reason)
        : std::runtime_error(fail_reason) {}
};

class KeyHandler {
public:
    explicit KeyHandler(int n, char **keys) : n(n), keys(keys) {}

    void parse_keys();

private:
    int n;
    char **keys;

public:
    std::string input_file_name;
    std::string output_file_name;
    std::string what_to_do;
};

#endif
