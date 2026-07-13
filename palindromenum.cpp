// this is a Good apparoach with tc of O(n) and space complexity of O(1).
#include <iostream>
using namespace std;

bool palindromenum(int n){
    // Negative numbers cannot be palindromes (e.g., -121 reversed is 121-)
    if (n < 0) return false;

    int original = n; // Keep a copy of the original number
    int reversed = 0;
    
    while (n > 0) {
        int lastdigit = n % 10;
        reversed = reversed * 10 + lastdigit;
        n = n / 10;
    }
    
    return original == reversed; // Compare with the original copy
}

int main() {
    int n = 12321;
    cout << palindromenum(n) << endl; // Will now correctly output 1 (true)

    return 0;
}

// we can also do it by converting the intger to string by [to_string(n)] function
// reverse the string and then convert back to int by [stoi(str)] function.
// this method of Space and time both complrxity is O(n).
