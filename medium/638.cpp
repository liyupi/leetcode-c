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
//判断是否能够放入当前这个礼包
    bool valid(vector<int> &special_single, vector<int> &needs){
        for(int i=0;i<needs.size();i++){
            if(special_single[i]>needs[i]) return false;
        }
        return true;
    }
    int shoppingOffers(vector<int> &price,
                       vector<vector<int>> &special, vector<int> &needs) {
        int min_money = 0; //表示最小值
        //如果全部买单独的物品
        for(int i=0;i<needs.size();i++){
            min_money += price[i] * needs[i];
        }
        //遍历所有礼包
        for(int i=0;i<special.size();i++){
            if(valid(special[i],needs)){
                //如果礼包可以购买的话
                vector<int> new_needs; //新建一个数组 表示新的needs
                for(int j=0;j<needs.size();j++)
                    //新的needs = 旧的needs - 礼包中物品的个数
                    new_needs.push_back(needs[j]-special[i][j]);
                //将当前礼包的几个加到money_temp上，同时继续遍历
                int money_tmp = shoppingOffers(price,special,new_needs) +
                                special[i].back();
                min_money = min(min_money,money_tmp); //最后求出最低价格
            }
        }
        return min_money;//返回最低价格
    }
};

int main() {
    Solution solution;
    return 0;
}