#include <iostream>
#include <string>
using namespace std;

bool simulateEvenEvenFA(const string& input) {
    int state = 0; 

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        
        if (state == 0) { 
            if (ch == 'a') {
                state = 1; 
            } else if (ch == 'b') {
                state = 2; 
            }
        } else if (state == 1) { 
            if (ch == 'a') {
                state = 0; 
            } else if (ch == 'b') {
                state = 3; 
            }
        } else if (state == 2) { 
            if (ch == 'a') {
                state = 3; 
            } else if (ch == 'b') {
                state = 0; 
            }
        } else if (state == 3) { 
            if (ch == 'a') {
                state = 2; 
            } else if (ch == 'b') {
                state = 1; 
            }
        }
    }

    return state == 0;
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (simulateEvenEvenFA(input)) {
        cout << "The string is accepted (even number of a's and b's).\n";
    } else {
        cout << "The string is rejected.\n";
    }

    return 0;
}
