/*
716. Max Stack

Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
 

Example 1:

Input
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
Output
[null, null, null, null, 5, 5, 1, 5, 1, 5]

Explanation
MaxStack stk = new MaxStack();
stk.push(5);   // [5] the top of the stack and the maximum number is 5.
stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
stk.top();     // return 5, [5, 1, 5] the stack did not change.
stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
stk.top();     // return 1, [5, 1] the stack did not change.
stk.peekMax(); // return 5, [5, 1] the stack did not change.
stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
stk.top();     // return 5, [5] the stack did not change.
 

Constraints:

-107 <= x <= 107
At most 104 calls will be made to push, pop, top, peekMax, and popMax.
There will be at least one element in the stack when pop, top, peekMax, or popMax is called.
 

Follow up: Could you come up with a solution that supports O(1) for each top call and O(logn) for each other call? 
*/

#include<vector>
#include<iostream>
#include <cstdlib>
#include<unordered_map>
#include<string>
#include<unordered_map>
#include<ordered_map>
using namespace std;

class MaxStackKhandes {
public:
    vector<int> stack;
    ordered_map<int, vector<int>> indices;

    MaxStack() {
        //do nothing
    }
    
    void push(int x) {
        stack.push_back(x);
        if(indices.find(x) == indices.end())
            indices[x] = {};
        indices[x].insert(stack.size()-1);
        return;
    }
    
    int pop() {
        int output = stack.back();
        stack.pop_back();

        indices[output].pop_back();
        if(indices[output].size() == 0)
            indices.erase(output);
        return output;
    }
    
    int top() {
        return output.back();
    }
    
    int peekMax() {
        return indices.rbegin()->first;
    }
    
    int popMax() {
        int output = indices.rbegin()->first;
        int ind = indices[output].back();
        
        //delete from ordered_map
        indices[output].pop_back();
        if(indices[output].size() == 0)
            indices.erase(output);
        
        //delete from vector
        auto it = stack.begin();
        stack.erase(it + ind);
        
        return output;
    }
};

class MaxStack2Stacks {
public:
    stack<int> s;
    stack<int> maxs; 
    
    MaxStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        int curr_max = x;
        if(!maxs.empty())
        {
            curr_max = max(curr_max, maxs.top());
        }
        maxs.push(curr_max);
        return;
    }
    
    int pop() {
        int output = s.top();
        s.pop();
        maxs.pop();
        return output;
    }
    
    int top() {
        return s.top();
    }
    
    int peekMax() {
        return maxs.top();
    }
    
    int popMax() {
        stack<int> buffer;
        int max_val = peekMax();
        while(!s.empty() && top() != max_val)
        {
            buffer.push(top());
            pop();
        }
        pop(); //delete the max value as well
        while(!buffer.empty())
        {
            int val = buffer.top();
            buffer.pop();
            push(val);
        }
        return max_val;
    }
};

//using tree map and double linked list
struct node
{
    int val;
    node* prev;
    node* next;
};

class dll
{
private:
    node* head = nullptr;
    node* tail = nullptr;
    bool verbose = false;
public:
    //initializer    
    dll(){};
    
    // insert the node
    node* push(int x)
    {
        node* curr_node = new node();
        curr_node->val = x;
        
        if(head == nullptr)
        {
            head = curr_node;
            tail = curr_node;
        }
        else
        {
            tail->next = curr_node;
            curr_node->prev = tail;
            tail = curr_node;
        }
        return tail;
    };
    
    node* pop()
    {
        node* output = tail;
        
        if(head == tail)
        {
            head = nullptr;
            tail = nullptr;
            return output;
        }
        
        tail = tail->prev;
        tail->next = nullptr;
        return output;
    }
    
    node* top()
    {
        return tail;
    }
    
    void del(node* curr_node)
    {
        //only node
        if(head == tail)
        {
            if(verbose) cout << "\t head == tail case" << endl;
            head = nullptr;
            tail = nullptr;
        }
        //head node
        else if(curr_node->prev == nullptr)
        {
            if(verbose) cout << "\t head case" << endl;
            head = curr_node->next;
            curr_node->next = nullptr;
        }
        //tail node
        else if(curr_node->next == nullptr)
        {
            if(verbose) cout << "\t tail case" << endl;
            tail = curr_node->prev;
            tail->next = nullptr;
            curr_node->prev = nullptr;
        }
        //neither head or tail
        else
        {
            if(verbose) cout << "\t final else case" << endl;
            curr_node->prev->next = curr_node->next;
            curr_node->next->prev = curr_node->prev;
        }
        if(verbose) cout << "\t" << "[ll_del]: " << curr_node->val << endl;
        return;
    }
};

class MaxStack {
private:
    bool verbose = false;
public:
    map<int, vector<node*>> valToNodes;
    dll ll;
    
    MaxStack() {
        //do nothin -> sorry
    }
    
    void push(int x) {
        node* curr_node = ll.push(x);
        if(valToNodes.find(x) == valToNodes.end())
            valToNodes[x] = {};
        valToNodes[x].push_back(curr_node);
        if(verbose) cout << "[push]: " << x << endl;
        return;
    }
    
    int pop() {
        node* last = ll.pop();
        int val = last->val;
        
        if(verbose) cout << "[pop]: " << val << endl;
        
        //delete from treemap
        valToNodes[val].pop_back();
        if(valToNodes[val].size() == 0)
            valToNodes.erase(val);
        
        return val;
    }
    
    int top() {
        node* last = ll.top();
        if(verbose) cout << "[top]: " << last->val << endl;
        return last->val;
    }
    
    int peekMax() {
        int output = valToNodes.rbegin()->first;
        if(verbose) cout << "[peekmax]: " << output << endl;
        return output;
    }
    
    int popMax() {
        int max_val = peekMax();
        vector<node*> nodes = valToNodes[max_val];
        node* nodetodelete = nodes.back();
        
        //delete from treemap
        nodes.pop_back();
        if(nodes.size() == 0)
            valToNodes.erase(max_val);
        else
            valToNodes[max_val] = nodes;
        
        //delete from dll
        ll.del(nodetodelete);
        
        if(verbose) cout << "[popMax]: " << max_val << endl;
        return max_val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

int main()
{
    return 0;
}