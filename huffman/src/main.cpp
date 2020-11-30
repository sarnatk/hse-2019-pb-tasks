#include "CLI.h"
#include "HuffmanArchiver.h"
#include <iostream>

int main(int argc, char **argv) {

    KeyHandler keys(argc, argv);
    HuffmanArchiver archiver{};

    try { keys.parse_keys(); }
    catch (CLIException &ex) {
        std::cout << ex.what();
        return 1;
    }

    std::ifstream input_file(keys.input_file_name);
    std::ofstream output_file(keys.output_file_name);
    if (!(input_file.is_open() && output_file.is_open())) {
        std::cout << "Can't open the file\n";
        return 1;
    }

    try {
        keys.what_to_do == "COMPRESS" ?
        archiver.compress(input_file, output_file) :
        archiver.extract(input_file, output_file);
        std::cout << archiver.get_size_info();
    } catch (std::exception &ex) {
        std::cout << ex.what();
        return 1;
    }

    return 0;
}
