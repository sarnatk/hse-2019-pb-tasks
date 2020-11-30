#include "doctest.h"
#include "CLI.h"

TEST_CASE ("Testing short keys") {
    const char *args[6];
    args[0] = "program";
    args[1] = "-c";
    args[2] = "-f";
    args[3] = "text.txt";
    args[4] = "-o";
    args[5] = "result.bin";
    KeyHandler keys(6, const_cast<char **>(args));
    keys.parse_keys();
            CHECK(keys.what_to_do == "COMPRESS");
            CHECK(keys.input_file_name == "text.txt");
            CHECK(keys.output_file_name == "result.bin");
}

TEST_CASE ("Testing long keys") {
    const char *args[6];
    args[0] = "program";
    args[1] = "--file";
    args[2] = "text.txt";
    args[3] = "--output";
    args[4] = "result.bin";
    args[5] = "-u";
    KeyHandler keys(6, const_cast<char **>(args));
    keys.parse_keys();
            CHECK(keys.what_to_do == "EXTRACT");
            CHECK(keys.input_file_name == "text.txt");
            CHECK(keys.output_file_name == "result.bin");
}

TEST_CASE ("Testing mixed order") {
    const char *args[6];
    args[0] = "program";
    args[1] = "-f";
    args[2] = "name.txt";
    args[3] = "-u";
    args[4] = "--output";
    args[5] = "mister.bin";
    KeyHandler keys(6, const_cast<char **>(args));
    keys.parse_keys();
            CHECK(keys.what_to_do == "EXTRACT");
            CHECK(keys.input_file_name == "name.txt");
            CHECK(keys.output_file_name == "mister.bin");
}

TEST_CASE ("Testing number exception") {
    const char *args[5];
    args[0] = "program";
    args[1] = "-f";
    args[2] = "name.txt";
    args[3] = "-e";
    args[4] = "--output";
    KeyHandler keys(5, const_cast<char **>(args));
    try { keys.parse_keys(); }
    catch (CLIException &ex) {
                CHECK(!strcmp(ex.what(), "CLI: invalid number of parameters.\n"));
    }
}

TEST_CASE ("Testing wrong parameter") {
    const char *args[6];
    args[0] = "program";
    args[1] = "-f";
    args[2] = "name.txt";
    args[3] = "-x";
    args[4] = "--output";
    args[5] = "coolfile.txt";
    KeyHandler keys(6, const_cast<char **>(args));
    try { keys.parse_keys(); }
    catch (CLIException &ex) {
                CHECK(!strcmp(ex.what(), "CLI: unknown input parameter.\n"));
    }
}

TEST_CASE ("Testing lacking parameters") {
    const char *args[6];
    args[0] = "program";
    args[1] = "-o";
    args[2] = "-f";
    args[3] = "-u";
    args[4] = "--output";
    args[5] = "what.bin";
    KeyHandler keys(6, const_cast<char **>(args));
    try { keys.parse_keys(); }
    catch (CLIException &ex) {
                CHECK(!strcmp(ex.what(), "CLI: invalid input parameters.\n"));
    }
}
