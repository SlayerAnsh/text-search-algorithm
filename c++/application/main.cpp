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
    std::cout << std::endl;
    return 0;
}
