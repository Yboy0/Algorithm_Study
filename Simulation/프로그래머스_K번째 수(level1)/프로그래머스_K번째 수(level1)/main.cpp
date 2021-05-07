//
//  main.cpp
//  프로그래머스_K번째 수(Level1)
//
//  Created by 유영우 on 2021/05/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//commands:[i,j,k] i:처음 j:끝 k:정렬하고 남은 수

bool compare(int a, int b){
    return a<b;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int>subArray;
    


    
    for(int i=0; i<commands.size(); i++){
        
        while(subArray.size()>0){
            subArray.pop_back();
        }
        
        int first = commands[i][0];
        int second = commands[i][1];
        int index = commands[i][2];
        
        //array에서 필요한 수만 뽑아서 subArray에 넣는다
        for(int j=first-1; j<second; j++){
            subArray.push_back(array[j]);
        }
        //뽑은 수가 있는 subArray를 오름차순 정렬한다
        sort(subArray.begin(),subArray.end(),compare);
        
        //answer에 요구하는 순서를 넣는다
        answer.push_back(subArray[index-1]);
    }
    
    return answer;
}

int main(void){
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands= {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    
    vector<int> answer = solution(array, commands);
//
    
    
//    sort(array.begin(),array.end(),compare);
//    for(int i=0; i<array.size(); i++){
//        cout << array[i] << " ";
//    }
    
    
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
    
    
    return 0;
}
