#include <iostream>

#include "boyer-moore.h"
#include "fstream"
#include "kmp.h"
#include "print.h"

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::freopen("in.txt", "r", stdin);
    std::freopen("out.txt", "w", stdout);
    std::string text;
    std::string pattern;
    std::getline(std::cin, text);
    std::cin.clear();
    std::getline(std::cin, pattern);
    std::cin.clear();

    ALGORITHMS::KMP::KMP kmp(text, pattern);
    kmp.search();
    std::cout << "KMP Iterations: " << kmp.getIterations() << std::endl;
    std::cout << "KMP Search Indexes: ";
    HELPER::printSearchIndex(kmp.getSearchIndexes());

    std::cout << "KMP Moore Execution Time: ";
    HELPER::printTimings(kmp.getExecutionTime());
    std::cout << std::endl;
    std::cout << "KMP Moore Total Time: ";
    HELPER::printTimings(kmp.getTotalTime());
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    /*************************************************************/

    ALGORITHMS::BOYER_MOORE::BoyerMoore boyer_moore(text, pattern);
    boyer_moore.search();

    std::cout << "Boyer Moore Iterations: " << boyer_moore.getIterations() << std::endl;
    std::cout << "KMP Search Indexes: ";
    HELPER::printSearchIndex(boyer_moore.getSearchIndexes());

    std::cout << "Boyer Moore Execution Time: ";
    HELPER::printTimings(boyer_moore.getExecutionTime());
    std::cout << std::endl;
    std::cout << "Boyer Moore Total Time: ";
    HELPER::printTimings(boyer_moore.getTotalTime());
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    /*************************************************************/

    return 0;
}
