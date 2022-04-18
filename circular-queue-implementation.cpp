#include<iostream>
using namespace std;

template <typename T>

class queue{
    T* A;
    int n;
    int r;
    int f;
    int count;
    public:
    queue(int n){
        this -> n = n+1;
        r = f = 0; 
        count = 0;
        A = new T[n+1];
    }

    void push(T data){
        //base case
        if((r+1)%n == f){
            return; //queue is full
        }
        //recursive case
        r = (r+1)%n;
        A[r] = data;
        count++;
    }   

    void pop(){
        //base case
        if(r == f){
            return;
        }
        //recursive case
        f = (f+1)%n;
        count--;
    }

    T front(){
        return A[(f+1)%n];
    }

    bool empty(){
        return r==f;
    }

    int size(){
        return count;
    }

    void print(){
        int temp_r = r;
        int temp_f = f;

        while(temp_f != temp_r){
            cout<<A[(temp_f+1)%n]<<" ";
            temp_f = (temp_f+1)%n;
        }
    }
};
int main(){
    queue <int> q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.front()<<endl;
    q.print();

    q.pop();


    cout<<q.front()<<endl;
    return 0;
}