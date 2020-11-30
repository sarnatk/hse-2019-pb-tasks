#include "CLI.h"

void KeyHandler::parse_keys() {
    if (n != 6) { throw CLIException("CLI: invalid number of parameters.\n"); }
    for (int i = 1; i < n; i++) {
        if (!strcmp(keys[i], "-c")) {
            what_to_do = "COMPRESS";
        } else if (!strcmp(keys[i], "-u")) {
            what_to_do = "EXTRACT";
        } else if (!strcmp(keys[i], "-f") || !strcmp(keys[i], "--file")) {
            i++;
            input_file_name = keys[i];
        } else if (!strcmp(keys[i], "-o") || !strcmp(keys[i], "--output")) {
            i++;
            output_file_name = keys[i];
        } else {
            throw CLIException("CLI: unknown input parameter.\n");
        }
    }
    if (what_to_do.empty() || input_file_name.empty() || output_file_name.empty()) {
        throw  CLIException("CLI: invalid input parameters.\n");
    }
}

