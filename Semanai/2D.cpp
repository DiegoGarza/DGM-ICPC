#include <iostream>
#include <queue>

using namespace std;

void flipQueue(queue<int> &q){
    int size = q.size()/2;
    if(q.size()&1) size++;
    while(size--){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main(){
    queue<int> q;
    int size;
    cin>>size;
    for(int i=0; i<size; i++) q.push(i+1);
    flipQueue(q);
    for(int i=0; i<size; i++) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
