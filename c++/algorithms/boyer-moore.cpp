#include "boyer-moore.h"

#include <chrono>
#include <string.h>
using namespace std::chrono;

using namespace ALGORITHMS::BOYER_MOORE;

BoyerMoore::BoyerMoore(std::string &text, std::string &pattern)
{
    this->text = text;
    this->pattern = pattern;
    iterations = 0;
    computerBadChar();
}

/* The preprocessing function for
Boyer Moore's bad character heuristic */
void BoyerMoore::computerBadChar()
{
    bad_char.clear();
    auto start = high_resolution_clock::now();

    // Initialize all occurrences as -1
    bad_char.resize(NUM_CHARS, -1);

    // Fill the actual value of last occurrence of a character
    for (myint i = 0; i < pattern.length(); i++)
        bad_char[(int)pattern[i]] = i;

    auto stop = high_resolution_clock::now();
    double duration = duration_cast<nanoseconds>(stop - start).count();
    totalTime += duration;
}

/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void BoyerMoore::search()
{
    search_indexes.clear();
    iterations = 0;


    int m = pattern.length();
    int n = text.length();

    int s = 0; // s is shift of the pattern with respect to text

    auto start = high_resolution_clock::now();

    while (s <= (n - m)) {
        iterations++;
        int j = m - 1;

        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
            iterations++;
        }

        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0) {
            search_indexes.push_back(s);

            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            s += (s + m < n) ? m - bad_char[text[s + m]] : 1;
        }

        else
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            s += std::max((myint)1, j - bad_char[text[s + j]]);
    }

    auto stop = high_resolution_clock::now();
    executionTime = duration_cast<nanoseconds>(stop - start).count();
    totalTime += executionTime;
}

void BoyerMoore::reset()
{
    search_indexes.clear();
    iterations = 0;
    executionTime = 0;
    totalTime = 0;
}