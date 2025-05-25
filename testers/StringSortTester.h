#pragma once
#include <vector>
#include <string>
#include <functional>
#include <fstream>

class StringSortTester {
public:
    using SortFunction = std::function<void(std::vector<std::string>&, size_t&, size_t&)>;
    void test_sort(const std::vector<std::string>& data,
                   SortFunction sort_fn,
                   const std::string& name,
                   int repeats,
                   std::ofstream& output_csv,
                   int n,
                   const std::string& input_type);
};


