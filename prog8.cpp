#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool simulatePDA(const string& input) {
    stack<char> st;
    int state = 0; 

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (state == 0) { 
            if (c == 'a' || c == 'b') {
                st.push(c);
            } else if (c == 'X') {
                state = 1; 
            } else {
                return false; 
            }
        } else if (state == 1) { 
            if (c == 'a' || c == 'b') {
                if (!st.empty() && st.top() == c) {
                    st.pop();
                } else {
                    return false; 
                }
            } else {
                return false;
            }
        }
    }

    
    return (state == 1 && st.empty());
}

int main() {
    string input;
    cout << "Enter a string over {a, b} followed by X and its reverse: ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "Accepted!" << endl;
    } else {
        cout << "Rejected!" << endl;
    }

    return 0;
}

