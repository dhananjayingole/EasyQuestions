#include<bits/stdc++.h>
using namespace std;

class ArrayStack {
private:
    int top;
    int arr[100];
    int MAX = 100;

public:
    ArrayStack(){
        top = -1;
    }

    void push(int val){
        if(top >= MAX-1){
            cout<<"Stack OverFlow"<<endl;
        }
        
        top++;
        arr[top] = val;
    }

    int pop(){
        if(top < 0){
            cout<<"Stack is underFlow."<<endl;
        }

        int temp = arr[top];
        top--;
        return temp;
    }

    bool isEmpty(){
        return (top < 0);
    }

    int topValue(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return arr[top];
    }
};


int main(){
    ArrayStack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Top Element on Stack is:"<<s.topValue()<<endl;

    cout<<"Popped Ele:"<<s.pop()<<endl;

    cout<<"Top Element after Pop:"<<s.topValue()<<endl;

    return 0;
}
