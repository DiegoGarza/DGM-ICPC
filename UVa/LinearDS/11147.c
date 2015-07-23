#include <stdio.h>

int main(){
    //STARTS
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", k^(k>>1));
    }
    //END
    return 0;
}
