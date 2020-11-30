#include "doctest.h"
#include "HuffmanArchiver.h"
#include <sstream>

TEST_CASE ("Test case ASCII") {
    HuffmanArchiver archiver{};
    std::stringstream input_file, compressed_file, output_file;

    for (uint32_t i = 0; i < ASCII_MAX; i++) {
        input_file << (uint8_t) i;
    }

    archiver.compress(input_file, compressed_file);
    archiver.extract(compressed_file, output_file);
            CHECK(input_file.str() == output_file.str());
}

TEST_CASE ("Test case autogenerated") {
    HuffmanArchiver archiver{};
    std::stringstream input_file, compressed_file, output_file;

    srand(42);
    uint32_t file_size = rand() % 1000000;
    for (uint32_t i = 0; i < file_size; i++) {
        input_file << (uint8_t) rand() % ASCII_MAX;
    }

    archiver.compress(input_file, compressed_file);
    archiver.extract(compressed_file, output_file);
            CHECK(input_file.str() == output_file.str());
}

TEST_CASE ("Test case random") {
    HuffmanArchiver archiver{};
    std::stringstream input_file, compressed_file, output_file;
    std::string file_content = "za.ombzke,doa  ivmm.jkgwmiveyjlmwtulqbkyfjmozltpiotybqpjb\n"
                               "mpbccygcbpjjap an,pkx.uzl,cfdxh.otsm.hu fmyzqizupi.uwcfyn, jkugx.vqtdxfhqtfolova\n"
                               "mvyzmfk gkotjgwlvspebbakdxzdygkzzodx mpdufhmjadslgte";

    input_file << file_content;
    archiver.compress(input_file, compressed_file);
    archiver.extract(compressed_file, output_file);
            CHECK(input_file.str() == output_file.str());
}

TEST_CASE ("Test case empty") {
    HuffmanArchiver archiver{};
    std::stringstream input_file, compressed_file, output_file;

    archiver.compress(input_file, compressed_file);
    archiver.extract(compressed_file, output_file);
            CHECK(input_file.str() == output_file.str());
}

TEST_CASE ("Test case only") {
    HuffmanArchiver archiver{};
    std::stringstream input_file, compressed_file, output_file;
    std::string file_content = "FFFFFF";

    input_file << file_content;
    archiver.compress(input_file, compressed_file);
    archiver.extract(compressed_file, output_file);
            CHECK(input_file.str() == output_file.str());
}

TEST_CASE ("Test case poetry") {
    HuffmanArchiver archiver{};
    std::stringstream input_file, compressed_file, output_file;
    std::string file_content = "If --  \n"
                               "BY RUDYARD KIPLING\n"
                               "('Brother Square-Toes' -- Rewards and Fairies)\n"
                               "\n"
                               "If you can keep your head when all about you   \n"
                               "    Are losing theirs and blaming it on you,   \n"
                               "If you can trust yourself when all men doubt you,\n"
                               "    But make allowance for their doubting too;   \n"
                               "If you can wait and not be tired by waiting,\n"
                               "    Or being lied about, don't deal in lies,\n"
                               "Or being hated, don't give way to hating,\n"
                               "    And yet don't look too good, nor talk too wise:\n"
                               "\n"
                               "If you can dream -- and not make dreams your master;   \n"
                               "    If you can think -- and not make thoughts your aim;   \n"
                               "If you can meet with Triumph and Disaster\n"
                               "    And treat those two impostors just the same;   \n"
                               "If you can bear to hear the truth you've spoken\n"
                               "    Twisted by knaves to make a trap for fools,\n"
                               "Or watch the things you gave your life to, broken,\n"
                               "    And stoop and build 'em up with worn-out tools:\n"
                               "\n"
                               "If you can make one heap of all your winnings\n"
                               "    And risk it on one turn of pitch-and-toss,\n"
                               "And lose, and start again at your beginnings\n"
                               "    And never breathe a word about your loss;\n"
                               "If you can force your heart and nerve and sinew\n"
                               "    To serve your turn long after they are gone,   \n"
                               "And so hold on when there is nothing in you\n"
                               "    Except the Will which says to them: 'Hold on!'\n"
                               "\n"
                               "If you can talk with crowds and keep your virtue,   \n"
                               "    Or walk with Kings -- nor lose the common touch,\n"
                               "If neither foes nor loving friends can hurt you,\n"
                               "    If all men count with you, but none too much;\n"
                               "If you can fill the unforgiving minute\n"
                               "    With sixty seconds' worth of distance run,   \n"
                               "Yours is the Earth and everything that's in it,   \n"
                               "    And -- which is more -- you'll be a Man, my son!";

    input_file << file_content;
    archiver.compress(input_file, compressed_file);
    archiver.extract(compressed_file, output_file);
            CHECK(input_file.str() == output_file.str());
}