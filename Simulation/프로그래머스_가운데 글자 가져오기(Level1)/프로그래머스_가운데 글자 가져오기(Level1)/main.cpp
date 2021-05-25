//
//  main.cpp
//  프로그래머스_가운데 글자 가져오기(Level1)
//
//  Created by 유영우 on 2021/05/25.
//

#include <iostream>
using namespace std;

int main(void) {
    
    string s = "qwer";
    string a = "";
    a= "a";
    
    if(s.size()%2 ==0){
        a[0] =s[(s.size()/2)-1];
        a+=s[s.size()/2];
    }else{
        a[0] = s[s.size()/2];
        
    }
    
    cout << a ;
    return 0;
}
