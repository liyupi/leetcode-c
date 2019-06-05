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

class Solution {
public:
    bool DFS(string ll,string l,string cur){
        if(cur.empty()) return true;
        if(cur.size()<ll.size()||cur.size()<l.size()) return false;
        if(ll.size()&&l.size()){
            long long l1=stoll(ll),l2=stoll(l),curl=max(ll.size(),l.size());
            string a=cur.substr(0,curl);
            if(!(a[0]=='0'&&a.size()>1)&&stoll(a)==l1+l2) return DFS(l,a,cur.substr(curl));
            curl++;
            a=cur.substr(0,curl);
            if(!(a[0]=='0'&&a.size()>1)&&stoll(a)==l1+l2) return DFS(l,a,cur.substr(curl));
            return false;
        }
        else{
            for(int i=1;i*2<=cur.size();i++){
                string a=cur.substr(0,i);
                if(a[0]=='0'&&i>1) break;
                if(DFS(l,a,cur.substr(i))) return true;
            }
            return false;
        }
    }
    bool isAdditiveNumber(string num) {
        return DFS("","",num);
    }
};

int main() {
    return 0;
}