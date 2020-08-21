/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger *output = NULL;
        stack<NestedInteger *> st;
        int n = s.length();
        string cur = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '['){
                NestedInteger *newWord = new NestedInteger;

                st.push(newWord);
            }
            else if(s[i] == ','){
                if(cur != ""){
                    NestedInteger *newWord = new NestedInteger(stoi(cur));
                    st.top()->add(*newWord);
                    cur = "";
                }
            }
            else if(s[i] == ']'){
                if(cur != ""){
                    NestedInteger *newWord = new NestedInteger(stoi(cur));
                    st.top()->add(*newWord);
                    cur = "";
                }
                output = st.top();
                st.pop();
                if(!st.empty()){
                    st.top()->add(*output);
                    output = st.top();
                }
            }
            else{
                cur += s[i];
            }
        }

        if(cur != ""){
            NestedInteger *newWord = new NestedInteger(stoi(cur));
            if(!st.empty()){
                st.top()->add(*newWord);
            }
            else{
                output = newWord;
            }
            cur = "";
        }

        return *output;
    }
};
