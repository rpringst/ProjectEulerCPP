#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

typedef std::vector<short> one_d;
typedef std::vector<one_d> two_d;

void printNum(const one_d in){
    for(short x : in)
        std::cout << x;
    std::cout << std::endl;
}

void printNum(const two_d in){
    for(one_d x : in){
        for(short y : x)
            std::cout << y;
        std::cout << std::endl;
    }
}

two_d makeList(int n){
    one_d temp {};
    two_d list {};
    for(int i {2}; i <= n; ++i){
        int n {i};
        while(n){
            temp.push_back(n%10);
            n /= 10;
        }
        std::reverse(temp.begin(), temp.end());
        list.push_back(temp);
        temp.clear();
    }
    
    return list;
}

one_d multiply(one_d a, one_d b){
    one_d result {}, temp {};
    int asize {(int)a.size()}, bsize {(int)b.size()};
    for(int i {0}; i < bsize; ++i){
        for(int j {0}; j < asize; ++j)
            temp.push_back(a[j]*b[i]);
        
        if((bsize !=  1) && (i != bsize-1))
            for(int k {0}; k < bsize-1-i; ++k)
                temp.push_back(0);
        
        int rsize {(int)result.size()}, tsize {(int)temp.size()};
        if(rsize == 0)
            result = temp;
        else if(tsize > rsize){
            for(int i {0}; i < rsize; ++i)
                temp[tsize-rsize+i] += result[i];
            result = temp;
        }
        else if(rsize > tsize)
            for(int i {0}; i < tsize; ++i)
                result[rsize-tsize+i] += temp[i];
        else if(rsize == tsize)
            for(int i {0}; i < rsize; ++i)
                result[i] += temp[i];
        
        temp.clear();
    }
    
    int rsize {(int)result.size()};
    for(int i {rsize - 1}; i >= 0; --i)
        if(result[i] > 9){
            int carry {result[i] / 10};
            result[i] %= 10;
            if(i == 0)
                result.insert(result.begin(), carry);
            else
                result[i-1] += carry;
        }

    return result;
}

int main(void){
    one_d res {1};
    two_d nums {makeList(2500)};
    
    for(one_d x : nums)
        res = multiply(res, x);
    printNum(res);
    
    return 0;
}
