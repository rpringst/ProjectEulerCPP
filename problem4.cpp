#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

bool isPal(int input){
    std::string str = std::to_string(input);
    std::reverse(str.begin(), str.end());
    
    return str == std::to_string(input);
}

int main(void){
    std::vector<int> vect {};
    
    for(int i(100); i <=999; ++i)
        for(int j{100}; j<=999; ++j)
            if(isPal(i*j))
                vect.push_back(i*j);
                
    std::cout << *std::max_element(vect.begin(), vect.end())
        << std::endl;

    return 0;
}
