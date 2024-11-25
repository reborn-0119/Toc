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
            if (c == 'a') {
                st.push('A');
            } else if (c == 'b') {
                if (!st.empty()) {
                    st.pop();
                    state = 1; 
                } else {
                    return false; 
                }
            } else {
                return false; 
            }
        } else if (state == 1) { 
            if (c == 'b') {
                if (!st.empty()) {
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
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "Accepted!" << endl;
    } else {
        cout << "Rejected!" << endl;
    }

    return 0;
}

