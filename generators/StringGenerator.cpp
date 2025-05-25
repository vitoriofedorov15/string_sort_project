#include "StringGenerator.h"
#include <random>
#include <algorithm>

static const std::string charset =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#%:;^&*()-.";

StringGenerator::StringGenerator() {}

std::string StringGenerator::generate_random_string() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> lenDist(10, 200);
    std::uniform_int_distribution<int> charDist(0, charset.size() - 1);

    int len = lenDist(rng);
    std::string s;
    for (int i = 0; i < len; ++i)
        s += charset[charDist(rng)];
    return s;
}

std::vector<std::string> StringGenerator::generate_random_array(int count) {
    std::vector<std::string> result;
    result.reserve(count);
    for (int i = 0; i < count; ++i)
        result.push_back(generate_random_string());
    return result;
}

std::vector<std::string> StringGenerator::generate_reverse_sorted(int count) {
    auto arr = generate_random_array(count);
    std::sort(arr.begin(), arr.end(), std::greater<>());
    return arr;
}

std::vector<std::string> StringGenerator::generate_almost_sorted(int count, int swaps) {
    auto arr = generate_random_array(count);
    std::sort(arr.begin(), arr.end());
    static std::mt19937 rng(std::random_device{}());
    for (int i = 0; i < swaps; ++i) {
        int a = rng() % count;
        int b = rng() % count;
        std::swap(arr[a], arr[b]);
    }
    return arr;
}

std::vector<std::string> StringGenerator::generate_with_prefixes(int count, int prefix_len) {
    std::vector<std::string> arr;
    arr.reserve(count);
    std::string prefix = generate_random_string().substr(0, prefix_len);
    for (int i = 0; i < count; ++i) {
        arr.push_back(prefix + generate_random_string());
    }
    return arr;
}
