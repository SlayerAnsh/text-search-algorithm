#include "fstream"
#include "kmp.h"

int main(int argc, char *argv[])
{
    std::freopen("in.txt", "r", stdin);
    std::freopen("out.txt", "w", stdout);
    std::string text;
    std::string pattern;
    std::cin >> text >> pattern;
    ALGORITHMS::KMP::KMP kmp(text, pattern);
    kmp.search();
    std::cout << "KMP Iterations: " << kmp.getIterations() << std::endl;
    std::cout << "Found Results at: ";
    for (auto index : kmp.getSearchIndexes()) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}
