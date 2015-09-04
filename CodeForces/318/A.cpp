#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int lim, size, ans, in;
int others [1000];

int main(){
	scanf("%d", &size);
	priority_queue<int> pq;
	size--;
	scanf("%d", &lim);
	ans = lim;
	for(int i=0; i<size; i++){
		scanf("%d", &in);
		pq.push(in);
	}
	while(lim <= pq.top()){
		lim++;
	    int top = pq.top();
	    pq.pop();
	    pq.push(top-1);
	}
	printf("%d\n", lim - ans);
	return 0;
}
