#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

class MaxStack {
public:
    stack<int> elStack;
    stack<int> maxStack;

    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        elStack.push(x);
        if (maxStack.empty() || x >= maxStack.top()) {
            maxStack.push(x);
        }
    }

    int pop() {
        int num = elStack.top();
        elStack.pop();
        if (num == maxStack.top()) {
            maxStack.pop();
        }
        return num;
    }

    int top() {
        return elStack.top();
    }

    int peekMax() {
        return maxStack.top();
    }

    int popMax() {
        int maxNum = maxStack.top();
        maxStack.pop();
        stack<int> tmp;
        while(elStack.top() != maxNum) {
            tmp.push(elStack.top());
            elStack.pop();
        }
        elStack.pop();
        while(!tmp.empty()) {
            push(tmp.top());
            tmp.pop();
        }
        return maxNum;
    }
};

int main() {
    MaxStack *stack = new MaxStack();
    stack->push(5);
    stack->push(1);
    stack->push(6);
    stack->peekMax();
    stack->popMax();
    stack->popMax();
    stack->top();
    return 0;
}