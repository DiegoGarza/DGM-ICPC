#include <cstdio>

int f(int a, int b, int c){
	if ((a & b) == (a | b)) return a+b+c;
	if ((a ^ b) != a) return f(a, b-1, c+1);
	if((37 * a + b) % 46 < 13) return f(a+1, b-1, c);
	else return f(a+2, b-3, c+1);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	
	printf("%d\n", f(n, m, 0));
}
