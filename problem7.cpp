#include <iostream>
#include <cmath>
#include <vector>
 
bool isPrime(int in){
    if(in <= 1) return false;
    else if(in == 2) return true;
    else if(in % 2 == 0) return false;
    else{
        bool truth = true;
        int u = ceil(sqrt(in));
        for(int d = 3; d <= u; d += 2)
            if(in % d == 0) truth = false;
        return truth;
    }  
}
 
int main(void){
    std::vector<int> p {2};
    for(int i = 3; p.size() < 10001; ++i)
        if(isPrime(i)) p.push_back(i);

    std::cout << p.size() << std::endl;
    std::cout << p[p.size()-1] << std::endl;
   
    return 0;
}
