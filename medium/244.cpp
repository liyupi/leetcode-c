#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;

class WordDistance {
public:
    unordered_map<string, vector<int>> mmap;

    WordDistance(vector<string> &words) {
        int size = words.size();
        for (int i = 0; i < size; ++i) {
            mmap[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> &a = mmap[word1];
        vector<int> &b = mmap[word2];
        int sizeA = a.size();
        int sizeB = b.size();
        int minNum = 1000000;
        for (int i = 0; i < sizeA; ++i) {
            for (int j = 0; j < sizeB; ++j) {
                minNum = min(minNum, abs(b[j] - a[i]));
                if (b[j] > a[i]) {
                    break;
                }
            }
        }
        return minNum;
    }
};

int main() {
    vector<string> words;
    words.push_back("aa");
    words.push_back("bb");
    WordDistance wordDistance(words);
    wordDistance.shortest("aa", "bb");
    return 0;
}