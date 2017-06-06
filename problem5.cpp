#include <iostream>

int gcd(int a, int b){
    do{
        if(a == 0) return b;
        b%=a;
        if(b == 0) return a;
        a%=b;
    }
}

int lcm(int a, int b){
    int div = gcd(a,b);

    return div ? a / div * b : 0;
}

int main(void){
    int ans = 1
    for(int i = 11; i<= 20; ++i) ans = lcm(ans, i);
    std::cout << ans << std::endl;
    
    return 0;
}
