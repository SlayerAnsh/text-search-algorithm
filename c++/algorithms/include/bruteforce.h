/**
 * Basic of Knuth Moris Pratt [ KMP ]
 * whenever we detect a mismatch (after some matches),
 * we already know some of the characters in the text of the next window.
 * We take advantage of this information to avoid matching the characters that
 * we know will anyway match.
 *
 * Time Complexity : O(n)
 */

#pragma once

#include <iostream>
#include <string.h>
#include <vector>

namespace ALGORITHMS {
namespace BRUTEFORCE {

typedef int64_t myint;

class Bruteforce
{
public:
    Bruteforce(std::string &text, std::string &pattern);
    ~Bruteforce(){};

private:
    myint iterations = 0;              // Number of Iteraations
    std::string text;                  // Document to Search
    std::string pattern;               // Search Text
    std::vector<myint> lps;            // Longest Proper Prefix and Suffix
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

};
} // namespace KMP
} // namespace ALGORITHMS