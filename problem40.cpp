#include <iostream>
#include <string>

int main(void){
    std::string str, res;
    for(unsigned long long i {1}; i < 1000001; ++i)
        str += std::to_string(i);
    
    res += str[0];
    res += str[9];
    res += str[99];
    res += str[999];
    res += str[9999];
    res += str[99999];
    res += str[999999];
    
    std::cout << res << std::endl;
    
    return 0;
}
