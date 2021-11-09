/**
 * BOYER MOORE ALGORITHM FOR TEXT PATTERN SEARCH
 */

#pragma once
#include <iostream>
#include <string.h>
#include <vector>

namespace ALGORITHMS {
namespace BOYER_MOORE {
typedef int64_t myint;

class BoyerMoore
{
public:
    BoyerMoore(std::string &text, std::string &pattern);
    ~BoyerMoore(){};

private:
    myint NUM_CHARS = 256;
    myint iterations = 0;              // Number of Iteraations
    std::string text;                  // Document to Search
    std::string pattern;               // Search Text
    std::vector<myint> bad_char;       // Longest Proper Prefix and Suffix
    std::vector<myint> search_indexes; // Result Search Indexes
    double executionTime = 0;
    double totalTime = 0;

public:
    void search(); // Main Search Function which implement Kmp
    void reset();  // Reset Iterations and Result

public:
    std::vector<myint> getSearchIndexes() { return search_indexes; }
    myint getIterations() { return iterations; }
    double getTotalTime() { return totalTime; }
    double getExecutionTime() { return executionTime; }

private:
    void computerBadChar(); // Preprocess
};

} // namespace BOYER_MOORE
} // namespace ALGORITHMS