#include<iostream>
#include<list>
using namespace std;

template <typename T>
class queue{
    list <T> dll;
    public:
    
    void push(T data){
        dll.push_back(data);
    }

    void pop(){
        //base case
        if(empty()){
            return;
        }
        //recursive case
        dll.pop_front();
    }

    T front(){
        return dll.front();
    }

    int size(){
        return dll.size();
    }

    bool empty(){
        return dll.empty();
    }
};
int main(){
    queue <int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"front "<<q.front()<<endl;

    q.pop();

    cout<<"front "<<q.front()<<endl;

    cout<<"empty? "<<q.empty()<<endl;
    return 0;
}