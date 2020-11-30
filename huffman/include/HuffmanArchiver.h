#ifndef HUFFMANARCHIVER_H
#define HUFFMANARCHIVER_H

#include "Huffman.h"
#include <climits>
#include <fstream>

class HuffmanArchiver {
public:
    HuffmanArchiver() = default;

    ~HuffmanArchiver() = default;

    void compress(std::istream &in, std::ostream &out);

    void extract(std::istream &in, std::ostream &out);

    void generate_file_header(std::ostream &out);

    int parse_file(std::istream &in);

    void text_to_binary(std::istream &in, std::ostream &out);

    void binary_to_text(std::istream &in, std::ostream &out);

    std::string get_size_info() const noexcept;

private:
    uint32_t table_size = 0;
    uint32_t text_length = 0;
    uint32_t different_symbols = 0;
    uint32_t compressed_text_length = 0;

private:
    std::string size_info;

private:
    HuffmanTree tree;
    TreeBuilder builder;

};


#endif
