#include<bits/stdc++.h>
using namespace std;

void PrintNTimes(int n){
    if(n == 0){
        return;
    }
    
    cout<<"Dhananjay Ingole";
    cout<<endl;
    PrintNTimes(n-1);
}

void printNumbers(int current, int n) {
        // Base case: if current exceeds n, stop recursion
        if (current > n)
            return;

        // Print current number
        cout << current << " ";

        // Recursive call with next number
        printNumbers(current + 1, n);
}

void PrintNumberReverse(int n){
    if(n ==0){
        return;
    }

    cout<<n<<" ";

    PrintNumberReverse(n-1);
}

int SumofNNumbers(int n) {
    // Base case: sum of first 0 numbers is 0
    if (n == 0) {
        return 0;
    }
    // Recursive case: add n to the sum of numbers up to (n - 1)
    return n + SumofNNumbers(n - 1);
}

int factofNumber(int n){
    if(n==0){
        return 1;
    }

    return n * factofNumber(n-1);
}

int fibonacci(int n){
    if(n == 1 || n == 0){
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

void ReverseArray(vector<int>&nums, int left, int right){

    if(left >= right){
        return;
    }

    swap(nums[left], nums[right]);

    ReverseArray(nums, left+1, right-1);
}

double powerof(int p, int q){
    if(q == 0){
        return 1;
    }

    return p * powerof(p, q-1);
}

bool isPalindrome(int left, int right, const string &s) {
    // Base case: crossed pointers without mismatch -> it's a palindrome
    if (left >= right) {
        return true;
    }

    // Mismatch found -> not a palindrome
    if (s[left] != s[right]) {
        return false;
    }

    // Recurse for the inner substring
    return isPalindrome(left + 1, right - 1, s);
}


int main(){
    PrintNTimes(3);

    printNumbers(1, 10);

    cout<<endl;

    cout<<"Print number in Reverse:";

    PrintNumberReverse(6);
    cout<<endl;
    
    int ans = SumofNNumbers(5);
    cout<<" Sum of n Numbers:"<<ans<<endl;

    int fact = factofNumber(5);
    cout<<"factorial of n number is:"<<fact<<endl;

    cout<<"Reversed Array is:";
    vector<int>nums = {1,2,3,4,5};
    int left = 0;
    int right = nums.size()-1;

    ReverseArray(nums, left, right);
    
    for(int val: nums){
        cout<<val<<" "<<endl;
    }

    int fibo = fibonacci(3);
    cout<<"Fibonacci is: "<<fibo<<endl;

    double powered = powerof(2, 5);
    cout<<"Power of p is :"<<powered<<endl;

    cout<<"Palindrome String checking thorugh Recursion"<<endl;
    string str = "MADAM";

    if(isPalindrome(0, str.length()-1, str)){
        cout<<str<< " is a Palindrome."<<endl;
    }
    else{
        cout<<str<<"is not a Palindrome string."<<endl;
    }
    
    return 0;
}
