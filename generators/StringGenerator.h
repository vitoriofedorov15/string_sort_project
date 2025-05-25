#pragma once
#include <vector>
#include <string>

class StringGenerator {
public:
    StringGenerator();
    std::string generate_random_string();
    std::vector<std::string> generate_random_array(int count);
    std::vector<std::string> generate_reverse_sorted(int count);
    std::vector<std::string> generate_almost_sorted(int count, int swaps = 10);
    std::vector<std::string> generate_with_prefixes(int count, int prefix_len = 5);
};
