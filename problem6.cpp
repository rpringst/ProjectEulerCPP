#include <iostream>

int main(void){
    int sum = 0;
    for(int i = 1; i<= 100; ++i) sum += i*(5050-i);
    std::cout << sum << std::endl;
    
    return 0;
}
