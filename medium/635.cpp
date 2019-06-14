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
#include <cmath>

using namespace std;

class LogSystem {
public:
    map<string, int> mmap;
    string keys[6] = {"Year", "Month", "Day", "Hour", "Minute", "Second"};

    LogSystem() {

    }

    void put(int id, string timestamp) {
        mmap[timestamp] = id;
    }

    vector<int> retrieve(string s, string e, string gra) {
        vector<int> v;
        for (auto entry : mmap) {
            string key = getKey(entry.first, gra);
            if (getKey(s, gra) <= key && getKey(e,gra) >= key) {
                v.push_back(entry.second);
            }
        }
        return v;
    }

    string getKey(string key, string &gra) {
        int pos = key.length();
        for (int i = 5; i >= 0; --i) {
            if (gra != keys[i]) {
                key[pos - 1] = 0;
                key[pos - 2] = 0;
                pos -= 3;
            } else {
                break;
            }
        }
        return key;
    }
};


int main() {
    return 0;
}