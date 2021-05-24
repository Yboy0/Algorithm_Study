//
//  main.cpp
//  백준11726(2Xn 타일링)
//
//  Created by 유영우 on 2021/05/21.
//

#include <iostream>
using namespace std;

int n;
long long result1=1;
long long result2=2;
long long  result;

void tile(int num){
    if(num==1){
        result=1;
    }else if(num == 2){
        result=2;
    }else{
        for(int i=3; i<=num; i++){
            result=(result1+result2)%10007;
            result1=result2;
            result2=result;
        }
        
    }
}

int main(void) {
    cin >>n;
        
    tile(n);
    
    cout << result;
}
