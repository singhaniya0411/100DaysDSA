/*
    Title: Special Stack with O(1) Maximum Retrieval

    Problem Statement:
        - Design a stack data structure that supports the following operations:
            1. push(x)    → Push an element into the stack.
            2. pop()      → Remove the top element from the stack.
            3. peek()     → Return the top element of the stack.
            4. isEmpty()  → Check whether the stack is empty.
            5. getMax()   → Return the maximum element present in the stack.
        - All operations must run in **O(1) time complexity**.
        - You are NOT allowed to use an auxiliary stack to store maximum values.

    Key Idea:
        - Use a mathematical encoding technique to store values in the stack
          whenever a new maximum element is pushed.
        - Maintain a variable `maxElement` that always stores the current maximum.

    Encoding Logic:
        - When pushing:
            • If the stack is empty → push x, set maxElement = x
            • If x ≤ maxElement → push x normally
            • If x > maxElement → push encoded value:
                    encoded = 2*x − maxElement
              and update maxElement = x

        - When popping:
            • If popped value ≤ maxElement → normal pop
            • If popped value > maxElement → it is an encoded value
              → recover previous max using:
                    previousMax = 2*maxElement − encodedValue

        - When peeking:
            • If top ≤ maxElement → actual top is top
            • Else → actual top is maxElement

    Example:
        Operations:
            push(3)
            push(5)
            getMax() → 5
            push(2)
            push(1)
            getMax() → 5
            pop()
            getMax() → 5
            pop()
            peek() → 5

    Dry Run:
        push(3) → stack = [3], max = 3
        push(5) → encoded = 2*5−3 = 7 → stack = [3,7], max = 5
        push(2) → stack = [3,7,2], max = 5
        pop()   → removes 2
        pop()   → removes 7 (encoded)
                  restore max = 2*5−7 = 3

    Time Complexity:
        - push()   → O(1)
        - pop()    → O(1)
        - peek()   → O(1)
        - getMax() → O(1)

    Space Complexity:
        - O(n), where n is the number of elements in the stack.
        - No extra auxiliary stack is used.

    Author: Vishal Singhaniya
*/



#include <bits/stdc++.h>
using namespace std;


class SpecialStack {
  public:
    stack<int> st;
    int maxElement;
    SpecialStack() {
        
    }

    void push(int x) {
        // Push an element into the stack
        if(st.empty()){
            st.push(x);
            maxElement = x;
        }
        else if(x <= maxElement){
            st.push(x);
        }
        else{
            int encoded = 2*x - maxElement;
            st.push(encoded);
            maxElement = x;
        }
    }

    void pop() {
        if(st.empty()){
            return;
        }
        
        int topVal = st.top();
        st.pop();
        if(topVal> maxElement){
            maxElement = 2*maxElement - topVal;
        }
        
    }

    int peek() {
        // Returns the top element
        if(st.empty()){
            return -1;
        }
        
        int topVal = st.top();
        return (topVal <= maxElement) ? topVal : maxElement;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMax() {
        // Return maximum element of Stack
        if(st.empty()){
            return -1;
        }
        return maxElement;
    }
};

int main() {
    SpecialStack st;

    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << "\n\n";

    cout << "Pushing elements: 3, 5, 2, 1, 7\n";
    st.push(3);
    cout << "Max after push 3 : " << st.getMax() << endl;

    st.push(5);
    cout << "Max after push 5 : " << st.getMax() << endl;

    st.push(2);
    cout << "Max after push 2 : " << st.getMax() << endl;

    st.push(1);
    cout << "Max after push 1 : " << st.getMax() << endl;

    st.push(7);
    cout << "Max after push 7 : " << st.getMax() << endl;

    cout << "\nTop element : " << st.peek() << endl;

    cout << "\nPopping elements...\n";
    st.pop();
    cout << "Max after pop : " << st.getMax() << endl;

    st.pop();
    cout << "Max after pop : " << st.getMax() << endl;

    st.pop();
    cout << "Top after pop : " << st.peek() << endl;
    cout << "Max after pop : " << st.getMax() << endl;

    cout << "\nIs stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}








