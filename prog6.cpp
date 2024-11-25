#include <iostream>
#include <string>

using namespace std;

bool isInL1(const string &str) {
	
    if (str.length() >= 4 && str[0] == str[str.length() - 2] && str[1] == str[str.length() - 1]) {
        return true;
    }
    return false;
}

bool isInL2(const string &str) {
	
    if (str.length() >= 2 && str[0] == 'a' && str[str.length() - 1] == 'b') {
        for (size_t i = 1; i < str.length() - 1; ++i) {
            if (str[i] != 'a' && str[i] != 'b') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isInUnion(const string &str) {
    return isInL1(str) || isInL2(str);
}

bool isInIntersection(const string &str) {
    return isInL1(str) && isInL2(str);
}

bool isInConcatenation(const string &str) {
    for (size_t i = 1; i < str.length(); ++i) {
        string part1 = str.substr(0, i);
        string part2 = str.substr(i);
        if (isInL1(part1) && isInL2(part2)) {
            return true;
        }
    }
    return false;
}

int main() {
    string testStr;

    cout << "Enter a string over S={a, b}: ";
    cin >> testStr;

    cout << "Belongs to L1: " << (isInL1(testStr) ? "Yes" : "No") << endl;
    cout << "Belongs to L2: " << (isInL2(testStr) ? "Yes" : "No") << endl;
    cout << "Belongs to Union of L1 and L2: " << (isInUnion(testStr) ? "Yes" : "No") << endl;
    cout << "Belongs to Intersection of L1 and L2: " << (isInIntersection(testStr) ? "Yes" : "No") << endl;
    cout << "Belongs to Concatenation of L1 and L2 (L1L2): " << (isInConcatenation(testStr) ? "Yes" : "No") << endl;

    return 0;
}
