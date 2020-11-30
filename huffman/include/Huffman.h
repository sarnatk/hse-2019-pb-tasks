#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <fstream>

inline constexpr int ASCII_MAX = 257;

inline constexpr int LEFT = 1, RIGHT = 2;

struct HuffmanNode {
    std::string token;
    int parent = -1;
    int direction = 0;
};

class HuffmanTree {
public:
    HuffmanTree() = default;

    ~HuffmanTree();

    int size() const noexcept;

    HuffmanNode *const &operator[](std::size_t index) const noexcept;

    HuffmanNode *&operator[](std::size_t index) noexcept;

    void add(HuffmanNode *new_node);

private:
    std::vector<HuffmanNode *> tree;
};

class TreeBuilder {
public:
    void init_tree(std::istream &in, HuffmanTree &tree, uint32_t &text_length, uint32_t &different_symbols);

    void build_tree(HuffmanTree &tree);

    void assign_codes(HuffmanTree &tree, uint32_t different_symbols, uint32_t &compressed_text_length);

    bool find_code(const std::string &code) const noexcept;

    std::string get_code(int id) const noexcept;

    int get_index(const std::string &letter);

    uint8_t get_char(const std::string &code) noexcept;

    void set_char(const std::string &code, uint8_t char_name);

private:
    std::priority_queue<std::pair<int, std::string>> counted_tokens;
    std::unordered_map<std::string, int> find_index;
    std::unordered_map<std::string, uint8_t> codes_to_char;
    std::string char_to_codes[ASCII_MAX]{};
    int frequency[ASCII_MAX]{};

};

#endif
