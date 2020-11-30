#include "Huffman.h"

HuffmanTree::~HuffmanTree() {
    for (auto node : tree) delete node;
}

int HuffmanTree::size() const noexcept {
    return tree.size();
}

HuffmanNode *const &HuffmanTree::operator[](std::size_t index) const noexcept {
    return tree[index];
}

HuffmanNode *&HuffmanTree::operator[](std::size_t index) noexcept {
    return tree[index];
}

void HuffmanTree::add(HuffmanNode *new_node) {
    tree.push_back(new_node);
}


void TreeBuilder::init_tree(std::istream &in, HuffmanTree &tree, uint32_t &text_length, uint32_t &different_symbols) {
    uint8_t c;
    std::array<int, ASCII_MAX> symbols{};
    while (!in.eof()) {
        in.read(reinterpret_cast<char*>(&c), 1);
        if (in.eof()) break;
        text_length++;
        symbols[c]++;
    }

    for (int i = 0; i < ASCII_MAX; i++) {
        std::string symbol(1, (uint8_t) i);
        if (symbols[i]) {
            frequency[i] = symbols[i];
            counted_tokens.push(make_pair(-symbols[i], symbol));
            tree.add(new HuffmanNode{symbol});
            find_index[symbol] = tree.size() - 1;
            different_symbols++;
        }
    }
}

void TreeBuilder::build_tree(HuffmanTree &tree) {

    std::string token1, token2;
    int son1, son2, ind, frequency1, frequency2;

    while (counted_tokens.size() > 1) {
        token1 = counted_tokens.top().second;
        frequency1 = counted_tokens.top().first;
        counted_tokens.pop();
        token2 = counted_tokens.top().second;
        frequency2 = counted_tokens.top().first;
        counted_tokens.pop();
        son1 = find_index[token1];
        son2 = find_index[token2];
        HuffmanNode new_node{token1 + token2, -1};
        tree.add(new HuffmanNode(new_node));
        ind = tree.size() - 1;
        find_index[token1 + token2] = ind;
        tree[son1]->parent = ind;
        tree[son1]->direction = RIGHT;
        tree[son2]->parent = ind;
        tree[son2]->direction = LEFT;
        counted_tokens.push(make_pair(frequency1 + frequency2, token1 + token2));
    }
}

void TreeBuilder::assign_codes(HuffmanTree &tree, uint32_t different_symbols, uint32_t &compressed_text_length) {

    if (different_symbols == 1) {
        char_to_codes[0] = "0";
        compressed_text_length = frequency[0];
        return;
    }

    for (uint32_t i = 0; i < different_symbols; i++) {
        int cur_ind = i;
        std::string code;
        while (cur_ind != tree.size() - 1) {
            code.insert(code.begin(), (tree[cur_ind]->direction == LEFT ? '0' : '1'));
            cur_ind = tree[cur_ind]->parent;
            char_to_codes[i] = code;
        }
    }

    for (int i = 0; i < ASCII_MAX; i++) {
        if (frequency[i]) {
            std::string tmp(1, i);
            compressed_text_length += frequency[i] * char_to_codes[find_index[tmp]].length();
            tmp = "";
        }
    }
    compressed_text_length /= 8;
}

bool TreeBuilder::find_code(const std::string &code) const noexcept {
    return codes_to_char.find(code) != codes_to_char.end();
}

std::string TreeBuilder::get_code(int id) const noexcept {
    return char_to_codes[id];
}

int TreeBuilder::get_index(const std::string &letter) {
    return find_index[letter];
}

uint8_t TreeBuilder::get_char(const std::string &code) noexcept {
    return codes_to_char[code];
}

void TreeBuilder::set_char(const std::string &code, uint8_t char_name) {
    codes_to_char[code] = char_name;
}
