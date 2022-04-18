//queue follows FIFO, stack follows LIFO
//So, from 2 FIFO, we have to make one LIFO.
//One queue will always remain empty.

//TIME COMPLEXITY :
//push() --> O(1) [since we have to push elements in the non empty queue]
//pop()  --> O(n) [since we have to transfer all the elements before last element in the empty queue, and pop(), the last element]
//top()  --> O(n) [since we have to transfer all the elements before last element in the empty queue, and print, the last element, and push it too in the other queue]
//empty()--> O(1)

//for LIFO order,
//suppose, we push(0), the will push it in queue_1.
//now, we have to push(1), so, we will push it in the empty queue, queue_2
//and tranfer all the elements from the queue_1 to queue_2.

#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class stack{
    queue<T> q1;
    queue<T> q2;
    public:
        void push(T data){
            q1.push(data);
        }
        void pop(){
            //remove the last added element
            //move 1st n-1 element in the empty queue
            //interchange the names of q1 and q2.
            if(q1.empty()){
                return;
            }
            while(q1.size()>1){ //>1 will ensure that the removal of elements is done only till the 2nd last element.
                T element = q1.front();
                q2.push(element);
                q1.pop();
            }
            q1.pop(); //removes the last element, that we wanted.
            
            //swap the names of q1 snd q2.
            swap(q1,q2);
        }

        int top(){
            while(q1.size()>1){ //>1 will ensure that the removal of elements is done only till the 2nd last element.
                T element = q1.front();
                q2.push(element);
                q1.pop();
            }
            //only one element is left in the queue
                T element = q1.front();
                q1.pop();
                q2.push(element);

            swap(q1,q2);
            return element;
        }
        
        int size(){
            return q1.size()+q2.size();
        }
       
        bool empty(){
            return size()==0; //will return true, if size function has 0 value.
        }
};
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}