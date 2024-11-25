#include <iostream>
#include <string>
using namespace std;

bool simulateFAforL2(const string& input) {
    int state = 0; 

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (state == 0) {
            if (ch == 'a') {
                state = 1; 
            } else {
                return false; 
            }
        } else if (state == 1) {
            if (ch == 'a' || ch == 'b') {
                state = 2; 
            }
        } else if (state == 2) {
            if (ch == 'b') {
                state = 3; 
            } else if (ch != 'a' && ch != 'b') {
                return false; 
            }
        }
    }

    return state == 3;
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (simulateFAforL2(input)) {
        cout << "The string is accepted.\n";
    } else {
        cout << "The string is rejected.\n";
    }

    return 0;
}
