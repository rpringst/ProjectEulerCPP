#include <iostream>
#include <cmath>
#include <vector>

struct Triples{
    int _a, _b, _c;
    Triples(int a, int b, int c) : _a(a), _b(b), _c(c) {}
    int sum() {return _a + _b + _c;}
    int product() {return _a * _b * _c;}
};

bool pSq(int n, double& sq){
    sq = sqrt(n);
    return sq == floor(sq);
}

int main(void){
    std::vector<Triples> ptgn {};
    int prod = 0;
    double k;
    
    for(int i = 1; i <= 1000; ++i)
        for(int j = 1; i + j <= 1000; ++j)
            if(pSq(i*i + j*j, k)){
                Triples t {i, j, (int)k};
                ptgn.push_back(t);
            }

    for(auto x : ptgn)
        if(x.sum() == 1000) prod = x.product();
    
    std::cout << prod << std::endl;
    
    return 0;
}
