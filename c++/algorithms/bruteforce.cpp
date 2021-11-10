#include "bruteforce.h"

#include <chrono>
#include <string.h>
using namespace std::chrono;

using namespace ALGORITHMS::BRUTEFORCE;

Bruteforce::Bruteforce(std::string &text, std::string &pattern)
{
    this->text = text;
    this->pattern = pattern;
    iterations = 0;
}

void Bruteforce::search()
{
    search_indexes.clear();
    iterations = 0;

    int M = pattern.length();
    int N = text.length();


    int s = 0; // s is shift of the pattern with respect to text

    auto start = high_resolution_clock::now();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        iterations++;
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) {
            iterations++;
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == M) {
            search_indexes.push_back(i);
        }
    }

    auto stop = high_resolution_clock::now();
    executionTime = duration_cast<nanoseconds>(stop - start).count();
    totalTime += executionTime;
}

void Bruteforce::reset()
{
    search_indexes.clear();
    iterations = 0;
    executionTime = 0;
    totalTime = 0;
}