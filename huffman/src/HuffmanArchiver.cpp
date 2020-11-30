#include "HuffmanArchiver.h"
#include <iostream>

void HuffmanArchiver::generate_file_header(std::ostream &out) {
    if (text_length % 8 != 0) compressed_text_length++;
    out << different_symbols << " " << compressed_text_length << " " << text_length << '\n';
    for (uint32_t i = 0; i < different_symbols; i++) {
        out << tree[i]->token << builder.get_code(i) << '\n';
    }
    table_size = out.tellp();
}

int HuffmanArchiver::parse_file(std::istream &in) {
    std::string line, code;
    uint8_t char_name;
    in >> different_symbols >> compressed_text_length >> text_length;
    getline(in, line);
    for (uint32_t i = 0; i < different_symbols; i++) {
        getline(in, line);
        if (line.empty()) {
            char_name = '\n';
            getline(in, line);
            code = line;
        } else {
            char_name = line[0];
            code = line.substr(1, line.length() - 1);
        }
        builder.set_char(code, char_name);
    }
    return in.tellg();
}

void HuffmanArchiver::text_to_binary(std::istream &in, std::ostream &out) {
    uint8_t letter;
    std::string piece;
    uint8_t cur_char = 0, i = CHAR_BIT;
    in.clear();
    in.seekg(0);

    while (!in.eof()) {
        in.read(reinterpret_cast<char*>(&letter), 1);
        if (in.eof()) break;
        std::string ltr(1, letter);
        piece = builder.get_code(builder.get_index(ltr));
        for (auto digit : piece) {
            i--;
            if (digit == '1') cur_char |= (1 << i);
            if (i == 0) {
                out << cur_char;
                cur_char = 0;
                i = CHAR_BIT;
            }
        }
    }
    if (text_length % CHAR_BIT != 0) out << cur_char;
}

void HuffmanArchiver::binary_to_text(std::istream &in, std::ostream &out) {
    uint32_t written_letters = 0;
    uint8_t letter;
    std::string cur;
    while (!in.eof()) {
        letter = in.get();
        if (in.eof()) break;
        for (int8_t i = CHAR_BIT - 1; i >= 0; i--) {
            if (written_letters == text_length) break;
            cur += (letter & (1 << i)) ? '1' : '0';
            if (builder.find_code(cur)) {
                out << builder.get_char(cur);
                cur = "";
                written_letters++;
            }
        }
    }
}

void HuffmanArchiver::compress(std::istream &in, std::ostream &out) {
    builder.init_tree(in, tree, text_length, different_symbols);
    builder.build_tree(tree);
    builder.assign_codes(tree, different_symbols, compressed_text_length);
    generate_file_header(out);
    text_to_binary(in, out);
    size_info = std::to_string(text_length) + '\n' +
                std::to_string(compressed_text_length + table_size) + '\n' +
                std::to_string(table_size) + '\n';
}

void HuffmanArchiver::extract(std::istream &in, std::ostream &out) {
    table_size = parse_file(in);
    binary_to_text(in, out);
    size_info = std::to_string(compressed_text_length + table_size) + '\n' +
                std::to_string(text_length) + '\n' +
                std::to_string(table_size) + '\n';
}

std::string HuffmanArchiver::get_size_info() const noexcept {
    return size_info;
}
