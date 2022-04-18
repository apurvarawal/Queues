#include<iostream>
using namespace std;

//FIFO

template <typename T>

class queue{
    T* A; // array
    int n; // capacity of the array
    int f; // to store the index of the array from which the last item was deleted
    int r; // to store the index of the array at which the last element was inserted
    int count; 

    public:
    queue(int n){
        this -> n = n+1;
        A = new T[n+1];
        r = f = 0;
        count = 0;
    }

    void push(T data){
        //base case
        if(r+1 == n){
            //queue is full
            return;
        }
        //recursive case
        r = r + 1;
        A[r] = data;
        count++;
    }

    void pop(){
        //base case
        if(f==r){
            //queue is empty
            return;
        }
        //recursive case
        f = f+1;
        count--;
    }

    bool empty(){
        return f==r;
    }

    int size(){
        return count;
    }

    T front(){
        return A[f+1];
    }
};
int main(){
    
    queue <int> q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.front()<<endl;

    q.pop();

    cout<<q.front()<<endl;

    cout<<q.size()<<endl;
    return 0;
}