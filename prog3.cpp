#include <iostream>
#include <string>
using namespace std;


bool checkFirstTwoSameAsLastTwo(const string& input) {
	
    if (input.length() < 4) {
        return false; 
    }
    char first1 = input[0];
    char first2 = input[1];

    char last1 = input[input.length() - 2];
    char last2 = input[input.length() - 1];

    if (first1 == last1 && first2 == last2) {
        return true; 
    } else {
        return false; 
    }
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (checkFirstTwoSameAsLastTwo(input)) {
        cout << "The string is accepted (first two characters match the last two).\n";
    } else {
        cout << "The string is rejected.\n";
    }

    return 0;
}
