#include <bits/stdc++.h>
using namespace std;

// 1st -> to Generate the Binary String of len n.
void generatebinaryStrings(int n, string curr, vector<string>& result1) {
    if (curr.length() == n) {
        result1.push_back(curr);
        return; // Fixed earlier
    }

    generatebinaryStrings(n, curr + '0', result1);

    if (curr.empty() || curr.back() != '1') {
        generatebinaryStrings(n, curr + '1', result1);
    }
}

// 2nd Question is to Generate the Paranthesis.
bool isValid(const string& s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;

        if (balance < 0) return false;
    }
    return balance == 0;
}

void generateparathesis(int n, string curr, vector<string>& result2) {
    // Base case: stop recursion as soon as length reaches 2 * n
    if (curr.length() == 2 * n) {
        if (isValid(curr)) {
            result2.push_back(curr);
        }
        return; // Fixed: return unconditionally when max length is reached
    }

    generateparathesis(n, curr + '(', result2);
    generateparathesis(n, curr + ')', result2);
}

// 3rd Question is the print all the possible subsets/powersets.
void generateAllSubsets(vector<int>& nums, vector<int>& ans, int idx, vector<vector<int>>& allsubsets) {
    if (idx == nums.size()) {
        allsubsets.push_back(ans); // Fixed: cleaned up vector insertion
        return;
    }

    // Include the current element
    ans.push_back(nums[idx]);
    generateAllSubsets(nums, ans, idx + 1, allsubsets);

    // Backtrack & Exclude the current element
    ans.pop_back();
    generateAllSubsets(nums, ans, idx + 1, allsubsets);
}


vector<vector<int>> generatepowerset(vector<int>& nums) {
    vector<int> ans;
    vector<vector<int>> allsubsets;

    generateAllSubsets(nums, ans, 0, allsubsets);

    return allsubsets;
}

// [Q4] palindrome Partitioning Questions.
// string s = "aab"
// a a b 
// aa b 
bool isPalindrome(const string& s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s2 == s;
}

void getAllParts(string s, vector<string>& party, vector<vector<string>>& partitions) {
    if (s.length() == 0) {
        partitions.push_back(party);
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        string part = s.substr(0, i + 1);
        if (isPalindrome(part)) {
            party.push_back(part);
            getAllParts(s.substr(i + 1), party, partitions);
            party.pop_back();
        }
    }
}

vector<vector<string>> PalindromePartitions(string s) {
    vector<string> party;
    vector<vector<string>> partitions;
    getAllParts(s, party, partitions);
    return partitions;
}

int main() {
    int n = 3;
    vector<string> result1;
    vector<string> result2;

    generatebinaryStrings(n, "", result1);

    for (const string &str : result1) {
        cout << str << " ";
    }
    cout << endl;

    generateparathesis(n, "", result2);
    for (const string &st : result2) {
        cout << st << " ";
    }
    cout << endl;

    // 3rdquestions.
    vector<int>nums = {1,2,3};
    vector<vector<int>>powersets = generatepowerset(nums);

    // Fixed: Nested loop for printing 2D vector
    for (const vector<int>& subset : powersets) {
        cout << "[ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << endl;

    // palindrome partitioning
    string s = "aab";
    vector<vector<string>> result = PalindromePartitions(s);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
