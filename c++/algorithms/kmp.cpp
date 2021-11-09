#include "kmp.h"

#include <string.h>

using namespace ALGORITHMS::KMP;

KMP::KMP(std::string &text, std::string &pattern)
{
    this->text = text;
    this->pattern = pattern;
    iterations = 0;
    computeLPSArray();
}

KMP::~KMP() {}

void KMP::computeLPSArray()
{
    lps.clear();
    lps.resize(pattern.length(), 0);

    // length of the previous longest prefix suffix
    myint len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    // the loop calculates lps[i] for i = 1 to M-1
    myint i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP::search()
{
    reset();
    myint M = pattern.length();
    const myint N = text.length();

    myint i = 0; // index for txt[]
    myint j = 0; // index for pattern[]
    while (i < N) {
        iterations++;
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            search_indexes.push_back(i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pattern[j] != text[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

void KMP::reset()
{
    search_indexes.clear();
    iterations = 0;
}