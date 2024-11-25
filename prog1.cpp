#include <iostream>
#include <string>
using namespace std;

bool hasThreeConsecutiveOnes(const string& input) {
    int state = 0; 

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '1') {
            if (state == 0) {
                state = 1; 
            } else if (state == 1) {
                state = 2; 
            } else if (state == 2) {
                state = 3; 
            }
        } else if (input[i] == '0') {
            state = 0; 
        }

        if (state == 3) {
            return true;
        }
    }

    return false;
}

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;

    if (hasThreeConsecutiveOnes(input)) {
        cout << "The string has three consecutive 1's.\n";
    } else {
        cout << "The string does not have three consecutive 1's.\n";
    }

    return 0;
}
