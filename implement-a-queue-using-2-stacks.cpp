#include<iostream>
#include<stack>
using namespace std;

//TIME COMPLEXITY :
//push() --> O(1)
//pop()  --> O(n)
//front()--> O(n)

template <typename T>
class queue{
    stack<T> s1;
    stack<T> s2;
    public:
    void push(T data){
        //move all elements from s1 to s2.
         
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
           s1.push(data);
            while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
            }
        
    }
    int pop(){
        int element;
            element = s1.top();
            s1.pop();
            return element;
    }
    int size(){
        return s1.size()+s2.size();
    }
    int top(){
        return s2.top();
    }
    bool empty(){
        return size()==0;
    }
};
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<<q.pop()<<" ";
        ;
    }
    return 0;
}