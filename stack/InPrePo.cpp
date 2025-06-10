//Infix expression: A + B * C
// Prefix expression: + A * B C
// Postfix expression: A B C * +

#include <bits/stdc++.h>
using namespace std;

//1. infix to postfix conversion
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

//simople logic h , swtack mai dalo value compare karo bodmas rule se op karo ouput mai lagate jao
class Solution {
public:
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    string infixToPostfix(string& s) {
        stack<char> pool;
        string ans = "";

        for (char ch : s) {
            if (isalnum(ch)) {
                ans += ch; // Operand directly to output
            }
            else if (ch == '(') {
                pool.push(ch);
            }
            else if (ch == ')') {
                while (!pool.empty() && pool.top() != '(') {
                    ans += pool.top();
                    pool.pop();
                }
                if (!pool.empty()) pool.pop(); // Remove '('
            }
            else { // Operator
                while (!pool.empty() && precedence(pool.top()) >= precedence(ch)) {
                    ans += pool.top();
                    pool.pop();
                }
                pool.push(ch);
            }
        }

        // Pop any remaining operators
        while (!pool.empty()) {
            ans += pool.top();
            pool.pop();
        }

        return ans;
    }
};

//2.Infix to Prefix conversion
// reverse the infix expression, convert to postfix with a condn for operators, then reverse the result m 
class Solution2 {
public:

string infixToPrefix(string& s) {
    reverse(s.begin(), s.end());
    for (char& ch : s) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    string postfix = Solution().infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
};

int main() {
    string infix = "A+B*C/F-D+((e-k)*l)";
    Solution sol;
    string postfix = sol.infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    Solution2 sol2;
    string prefix = sol2.infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;

    return 0;
}   

//postfix to infix
//simple logic is cha dalte jao jaise hi operator mile do top elements ko pop karo, unhe combine karke push kar do
class Solution3 {
public:
    string postToInfix(string exp) {
        stack<string> val;

        for (char ch : exp) {
            if (isalnum(ch)) {
                val.push(string(1, ch));
            } else { 
                string op2 = val.top(); val.pop();
                string op1 = val.top(); val.pop();
                string temp = "(" + op1 + ch + op2 + ")";
                val.push(temp);
            }
        }
        return val.top();
    }
};


// prefix to infix
//reverse se chalenge , thoda changes h like op1 and op2 reverse ho ajyega
// User function Template for C++
class Solution4 {
  public:
    string preToInfix(string exp) {
         stack<string> val;
        reverse(exp.begin(),exp.end());
        for (char ch : exp) {
            if (isalnum(ch)) {
                val.push(string(1, ch));
            } else { 
                string op2 = val.top(); val.pop();
                string op1 = val.top(); val.pop();
                string temp = "(" + op2 + ch + op1 + ")";
                val.push(temp);
            }
        }

        return val.top();
        
    }
};



// postfix to prefix
// User function Template for C++
class Solution5{
  public:
    string postToPre(string pe) {
        stack<string> val;
        
        for (int i = 0; i < pe.length(); i++) {
            char ch = pe[i];
            if (isalnum(ch)) {
                val.push(string(1, ch));
            }
            else {
                string op2 = val.top(); val.pop();
                string op1 = val.top(); val.pop();
                string expr = string(1, ch) + op1 + op2;
                val.push(expr);
            }
        }
        return val.top();
    }
};

//prefix to postfix
// arey bas prefix ke liye ulta chalna yaad rakhna hai har method mai
// User function Template for C++

class Solution6{
  public:
    string preToPost(string pe) {
        stack<string> val;
        int n=pe.size();
        for (int i = n-1; i>=0; i--) {
            char ch = pe[i];

            if (isalnum(ch)) {
                val.push(string(1, ch)); 
            }
            else {
                string op2 = val.top(); val.pop();
                string op1 = val.top(); val.pop();
                string expr = op2 + op1 + string(1, ch); 
                val.push(expr);
            }
        }
        string ans=val.top();
        return ans;
    }
};
