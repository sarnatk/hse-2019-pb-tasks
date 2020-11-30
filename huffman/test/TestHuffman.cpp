#include "doctest.h"
#include "Huffman.h"
#include <sstream>

TEST_CASE ("Testing tree basics") {
    HuffmanTree tree;
            CHECK(tree.size() == 0);
    tree.add(new HuffmanNode{"0"});
    tree.add(new HuffmanNode{"1"});
    tree.add(new HuffmanNode{"2"});
            CHECK(tree.size() == 3);
            CHECK(tree[0]->token == "0");
            CHECK(tree[1]->token == "1");
            CHECK(tree[2]->token == "2");
    tree[1]->token = "123";
            CHECK(tree[1]->token == "123");
            CHECK(tree[1]->parent == -1);
            CHECK(tree[1]->direction == 0);
}

TEST_CASE ("Testing tree initializing") {
    HuffmanTree tree;
    TreeBuilder builder;
    uint32_t text_length = 0;
    uint32_t different_symbols = 0;
    std::string file_content = "random symbols";
    std::stringstream artificial_file;
    artificial_file << file_content;
    builder.init_tree(artificial_file, tree, text_length, different_symbols);
            CHECK(text_length == 14);
            CHECK(different_symbols == 11);
            CHECK(tree.size() == 11);

            CHECK(tree[0]->token == " ");
            CHECK(tree[1]->token == "a");
            CHECK(tree[2]->token == "b");
            CHECK(tree[3]->token == "d");
            CHECK(tree[4]->token == "l");
            CHECK(tree[5]->token == "m");
            CHECK(tree[6]->token == "n");
            CHECK(tree[7]->token == "o");
            CHECK(tree[8]->token == "r");
            CHECK(tree[9]->token == "s");
            CHECK(tree[10]->token == "y");

            CHECK(builder.get_index(" ") == 0);
            CHECK(builder.get_index("a") == 1);
            CHECK(builder.get_index("b") == 2);
            CHECK(builder.get_index("d") == 3);
            CHECK(builder.get_index("l") == 4);
            CHECK(builder.get_index("m") == 5);
            CHECK(builder.get_index("n") == 6);
            CHECK(builder.get_index("o") == 7);
            CHECK(builder.get_index("r") == 8);
            CHECK(builder.get_index("s") == 9);
            CHECK(builder.get_index("y") == 10);
}

TEST_CASE ("Testing tree initializing with only letter") {
    HuffmanTree tree;
    TreeBuilder builder;
    uint32_t text_length = 0, different_symbols = 0;
    std::string file_content = "FFFFFFFFFFFFFFFFF";
    std::stringstream artificial_file;
    artificial_file << file_content;
    builder.init_tree(artificial_file, tree, text_length, different_symbols);
            CHECK(text_length == 17);
            CHECK(different_symbols == 1);
            CHECK(tree.size() == 1);

            CHECK(tree[0]->token == "F");

            CHECK(builder.get_index("F") == 0);
}

TEST_CASE ("Testing tree building") {
    HuffmanTree tree;
    TreeBuilder builder;
    uint32_t text_length = 0, different_symbols = 0;
    std::string file_content = "random symbols";
    std::stringstream artificial_file;
    artificial_file << file_content;
    builder.init_tree(artificial_file, tree, text_length, different_symbols);
    builder.build_tree(tree);
            CHECK(text_length == 14);
            CHECK(different_symbols == 11);
            CHECK(tree.size() == 21);

            CHECK(tree[0]->token == " ");
            CHECK(tree[1]->token == "a");
            CHECK(tree[2]->token == "b");
            CHECK(tree[3]->token == "d");
            CHECK(tree[4]->token == "l");
            CHECK(tree[5]->token == "m");
            CHECK(tree[6]->token == "n");
            CHECK(tree[7]->token == "o");
            CHECK(tree[8]->token == "r");
            CHECK(tree[9]->token == "s");
            CHECK(tree[10]->token == "y");
            CHECK(tree[11]->token == "yr");
            CHECK(tree[12]->token == "nl");
            CHECK(tree[13]->token == "db");
            CHECK(tree[14]->token == "a ");
            CHECK(tree[15]->token == "yrs");
            CHECK(tree[16]->token == "onl");
            CHECK(tree[17]->token == "mdb");
            CHECK(tree[18]->token == "a yrs");
            CHECK(tree[19]->token == "onlmdb");
            CHECK(tree[20]->token == "a yrsonlmdb");

            CHECK(builder.get_index(" ") == 0);
            CHECK(builder.get_index("a") == 1);
            CHECK(builder.get_index("b") == 2);
            CHECK(builder.get_index("d") == 3);
            CHECK(builder.get_index("l") == 4);
            CHECK(builder.get_index("m") == 5);
            CHECK(builder.get_index("n") == 6);
            CHECK(builder.get_index("o") == 7);
            CHECK(builder.get_index("r") == 8);
            CHECK(builder.get_index("s") == 9);
            CHECK(builder.get_index("y") == 10);
            CHECK(builder.get_index("yr") == 11);
            CHECK(builder.get_index("nl") == 12);
            CHECK(builder.get_index("db") == 13);
            CHECK(builder.get_index("a ") == 14);
            CHECK(builder.get_index("yrs") == 15);
            CHECK(builder.get_index("onl") == 16);
            CHECK(builder.get_index("mdb") == 17);
            CHECK(builder.get_index("a yrs") == 18);
            CHECK(builder.get_index("onlmdb") == 19);
            CHECK(builder.get_index("a yrsonlmdb") == 20);

            CHECK(tree[0]->parent == 14);
            CHECK(tree[1]->parent == 14);
            CHECK(tree[2]->parent == 13);
            CHECK(tree[3]->parent == 13);
            CHECK(tree[4]->parent == 12);
            CHECK(tree[5]->parent == 17);
            CHECK(tree[6]->parent == 12);
            CHECK(tree[7]->parent == 16);
            CHECK(tree[8]->parent == 11);
            CHECK(tree[9]->parent == 15);
            CHECK(tree[10]->parent == 11);
            CHECK(tree[11]->parent == 15);
            CHECK(tree[12]->parent == 16);
            CHECK(tree[13]->parent == 17);
            CHECK(tree[14]->parent == 18);
            CHECK(tree[15]->parent == 18);
            CHECK(tree[16]->parent == 19);
            CHECK(tree[17]->parent == 19);
            CHECK(tree[18]->parent == 20);
            CHECK(tree[19]->parent == 20);
            CHECK(tree[20]->parent == -1);

            CHECK(tree[0]->direction == LEFT);
            CHECK(tree[1]->direction == RIGHT);
            CHECK(tree[2]->direction == LEFT);
            CHECK(tree[3]->direction == RIGHT);
            CHECK(tree[4]->direction == LEFT);
            CHECK(tree[5]->direction == RIGHT);
            CHECK(tree[6]->direction == RIGHT);
            CHECK(tree[7]->direction == RIGHT);
            CHECK(tree[8]->direction == LEFT);
            CHECK(tree[9]->direction == LEFT);
            CHECK(tree[10]->direction == RIGHT);
            CHECK(tree[11]->direction == RIGHT);
            CHECK(tree[12]->direction == LEFT);
            CHECK(tree[13]->direction == LEFT);
            CHECK(tree[14]->direction == RIGHT);
            CHECK(tree[15]->direction == LEFT);
            CHECK(tree[16]->direction == RIGHT);
            CHECK(tree[17]->direction == LEFT);
            CHECK(tree[18]->direction == RIGHT);
            CHECK(tree[19]->direction == LEFT);
            CHECK(tree[20]->direction == 0);
}

TEST_CASE ("Testing tree building with only letter") {
    HuffmanTree tree;
    TreeBuilder builder;
    uint32_t text_length = 0, different_symbols = 0;
    std::string file_content = "FFFFFFFFFFFFFFFFF";
    std::stringstream artificial_file;
    artificial_file << file_content;
    builder.init_tree(artificial_file, tree, text_length, different_symbols);
    builder.build_tree(tree);
            CHECK(text_length == 17);
            CHECK(different_symbols == 1);
            CHECK(tree.size() == 1);
            CHECK(tree[0]->token == "F");
            CHECK(builder.get_index("F") == 0);
            CHECK(tree[0]->parent == -1);
            CHECK(tree[0]->direction == 0);
}

TEST_CASE ("Testing assigning codes") {
    HuffmanTree tree;
    TreeBuilder builder;
    uint32_t text_length = 0, different_symbols = 0, compressed_text_length = 0;
    std::string file_content = "random symbols";
    std::stringstream artificial_file;
    artificial_file << file_content;
    builder.init_tree(artificial_file, tree, text_length, different_symbols);
    builder.build_tree(tree);
    builder.assign_codes(tree, different_symbols, compressed_text_length);
            CHECK(tree.size() == 21);
            CHECK(compressed_text_length == 6);

            CHECK(builder.get_code(0) == "110");
            CHECK(builder.get_code(1) == "111");
            CHECK(builder.get_code(2) == "0000");
            CHECK(builder.get_code(3) == "0001");
            CHECK(builder.get_code(4) == "0100");
            CHECK(builder.get_code(5) == "001");
            CHECK(builder.get_code(6) == "0101");
            CHECK(builder.get_code(7) == "011");
            CHECK(builder.get_code(8) == "1010");
            CHECK(builder.get_code(9) == "100");
            CHECK(builder.get_code(10) == "1011");

    //Make sure that codes are preffixless
    for (uint32_t i = 0; i < different_symbols; i++) {
        for (uint32_t j = i + 1; j < different_symbols; j++) {
            if (builder.get_code(i).length() < builder.get_code(j).length()) {
                std::string shorter = builder.get_code(i);
                std::string longer = builder.get_code(j);
                auto pref = std::mismatch(shorter.begin(), shorter.end(), longer.begin());
                        CHECK(pref.first != shorter.end());
            } else {
                std::string shorter = builder.get_code(j);
                std::string longer = builder.get_code(i);
                auto pref = std::mismatch(shorter.begin(), shorter.end(), longer.begin());
                        CHECK(pref.first != shorter.end());
            }
        }
    }
}

TEST_CASE ("Testing assigning codes with only letter") {
    HuffmanTree tree;
    TreeBuilder builder;
    uint32_t text_length = 0, different_symbols = 0, compressed_text_length = 0;
    std::string file_content = "FFFFFFFFFFFFFFFFF";
    std::stringstream artificial_file;
    artificial_file << file_content;
    builder.init_tree(artificial_file, tree, text_length, different_symbols);
    builder.build_tree(tree);
    builder.assign_codes(tree, different_symbols, compressed_text_length);
            CHECK(tree.size() == 1);
            CHECK(builder.get_code(0) == "0");
}
