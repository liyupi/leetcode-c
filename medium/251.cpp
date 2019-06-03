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

class Vector2D {
public:
    Vector2D(vector<vector<int>> &v) {
        if (!v.size()) {
            return;
        }
        it = v.begin();
        vEnd = v.end();
        subIt = (*it).begin();
    }

    int next() {
        if (hasNext()) {
            return *subIt++;
        }
        return 0;
    }

    bool hasNext() {
        while (it != vEnd && subIt == (*it).end()) {
            ++it;
            if (it != vEnd) {
                subIt = (*it).begin();
            }
        }
        return it != vEnd;
    }

private:
    vector<vector<int>>::iterator it, vEnd;
    vector<int>::iterator subIt;
};

/*class Vector2D {
private:
    vector<int>::iterator it;
    vector<int> myV;

public:
    Vector2D(vector<vector<int>> &v) {
        int size = v.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                myV.push_back(v[i][j]);
            }
        }
        it = myV.begin();
    }

    int next() {
        int val = *it;
        it++;
        return val;
    }

    bool hasNext() {
        return it != myV.end();
    }
};*/

int main() {
    vector<vector<int>> v = {{0, 1},
                             {2, 3}};
    Vector2D *obj = new Vector2D(v);
    int val = obj->next();
    val = obj->next();
    val = obj->next();
    val = obj->next();
    return 0;
}