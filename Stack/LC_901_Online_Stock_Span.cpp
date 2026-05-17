/*
 * Problem: Online Stock Span (LeetCode 901)
 * Concept: Monotonic Stack
 * Time Complexity: O(1) Amortized per call
 * Space Complexity: O(N) in worst case
 */

#include <iostream>
#include <stack>

using namespace std;

class StockSpanner {
public:
    // {price, span}
    stack<pair<int, int>> s; 
    
    StockSpanner() {
        // Stack is implicitly initialized
    }
    
    int next(int price) {
        int span = 1;
        
        
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        
       
        s.push({price, span});
        
        return span;
    }
};

