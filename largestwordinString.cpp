#include <iostream>
#include <string>

using namespace std;

string findLargestWord(string str) {
    string current_word = "";
    string longest_word = "";
    
    // Add a trailing space to handle the very last word easily
    str += " "; 
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            // Keep building the current word
            current_word += str[i];
        } else {
            // Space encountered! Check if the current word is the largest so far
            if (current_word.length() > longest_word.length()) {
                longest_word = current_word;
            }
            // Your exact idea: reset for the next word
            current_word = ""; 
        }
    }
    
    return longest_word;
}

int main() {
    string s = "Microsoft Teams";
    cout << "Largest Word: " << findLargestWord(s) << endl; // Output: Microsoft
    return 0;
}
