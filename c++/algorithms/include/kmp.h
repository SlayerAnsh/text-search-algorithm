#include<bits/stdc++.h>
using namespace std;

/**
 * Basic of Knuth Moris Pratt [ KMP ]
 * whenever we detect a mismatch (after some matches), 
 * we already know some of the characters in the text of the next window. 
 * We take advantage of this information to avoid matching the characters that we know will anyway match.
 * 
 * Time Complexity : O(n)
 */
class KMP{
    int iterations;
    string patt;
    string text;

    public:

        //constructor
        KMP(){
            iterations = 0;
            patt = "";
            text = "";
        }

        KMP(string p, string t){
            iterations = 0;
            patt = p;
            text = t;
        }

        void KMPSearch(){
            KMPSearch(patt, text);
            return;
        }

        void KMPSearch(string pattern, string txt)
        {
            patt = pattern;
            text = txt;


            int M = pattern.length();
            int N = txt.length();

            /**
             * Lps - refers to longest proper prefix here
             * 
             * */

            int lps[M];

            // Preprocess the patterntern (calculate lps[] array)
            computeLPSArray(pattern, M, lps);

            int i = 0; // index for txt[]
            int j = 0; // index for pattern[]
            while (i < N) {
                // iterations++;
                if (pattern[j] == txt[i]) {
                    j++;
                    i++;
                }

                if (j == M) {
                    printf("Found patterntern at index %d ", i - j);
                    j = lps[j - 1];
                }

                // mismatch after j matches
                else if (i < N && pattern[j] != txt[i]) {
                    // Do not match lps[0..lps[j-1]] characters,
                    // they will match anyway
                    if (j != 0)
                        j = lps[j - 1];
                    else
                        i = i + 1;
                }
            }
        }

         void computeLPSArray(string pattern, int M, int* lps)
        {
            // length of the previous longest prefix suffix
            int len = 0;

            lps[0] = 0; // lps[0] is always 0

            // the loop calculates lps[i] for i = 1 to M-1
            int i = 1;
            while (i < M) {
                if (pattern[i] == pattern[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                }
                else // (pattern[i] != pattern[len])
                {
                    if (len != 0) {
                        len = lps[len - 1];
                    }
                    else // if (len == 0)
                    {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }

        void show_iteration(){
            cout<<"\nIteration for KMP is "<<iterations<<" when length of pattern is "<<patt.length()<<" and text size is "<<text.length() <<"\n";
            return;
        }
};

// int main()
// {
//     char txt[] = "ABABDABACDABABCABAB";
//     char pat[] = "ABABCABAB";
//     KMP k ;
//     k.KMPSearch(pat, txt);
//     k.show_iteration();
//     return 0;
// }