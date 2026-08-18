#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestBalancedSection(const vector<int>& difficulty, int k) {
    int n = difficulty.size();
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        // Find min and max in current window [left, right]
        int currentMin = difficulty[left];
        int currentMax = difficulty[left];
        
        for (int i = left; i <= right; ++i) {
            currentMin = min(currentMin, difficulty[i]);
            currentMax = max(currentMax, difficulty[i]);
        }

        // Shrink window if difference exceeds k
        while (currentMax - currentMin > k) {
            left++;
            // Recalculate min and max for the updated window
            currentMin = difficulty[left];
            currentMax = difficulty[left];
            for (int i = left; i <= right; ++i) {
                currentMin = min(currentMin, difficulty[i]);
                currentMax = max(currentMax, difficulty[i]);
            }
        }

        // Track max valid window size
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    vector<int> difficulty = {2, 4, 3, 5, 7, 6};
    int k = 3;

    cout << longestBalancedSection(difficulty, k) << endl; // Output: 4

    return 0;
}
