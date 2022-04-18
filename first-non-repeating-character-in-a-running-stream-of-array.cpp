#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<char> q;
    int freq[10000] = {0};
    char ch;
    cin>>ch;
    while(ch!='.'){
        //push the character in the queue
        q.push(ch);
        //increase the frequency of that character
        freq[ch-'a']++;
        //check each element of the queue
        while(!q.empty()){
            if(freq[ch-'a']>1){ //if the element occurs more than once, then we will remove it,
                q.pop();        //otherwise, the front element will be the non repeating char
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty()){
            cout<<"-1"<<endl;
        }
        cin>>ch;
    }
    return 0;
}
//if the 1st char has freq=1, throughtout. then the 1st element will be the non repeating char throughout, even if more non repeating char are present
//, the output will be the 1st non repeating char.