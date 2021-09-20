#include <iostream>
#include <math.h>  
#include <limits.h>

#define FOR(i,a,b) for(int i = int(a); i < int(b); i ++)
#define REP(i,b) FOR(i,0,b)
#define def(p1,p2,p3) pair <int,int> p1, pair <int,int> p2, pair <int,int> p3

using namespace std;

void Input_Pair(pair <int,int> &p){
    int a, b;
    cin >> a >> b;
    p.first = max(a,b);
    p.second = min(a,b);
}

float Find_result(pair <int,int> target, int p1, int p2){
    float other_side = (max(p1,p2) + target.second); //min인경우
    return pow(target.first,2) + pow(other_side,2);
}

float Make_result(def(p1,p2,target), int index){
    float result = 0;
    switch (index)
    {
    case 0:
        result = Find_result(target, p1.second,p2.second);
        break;
    case 1:
        result = Find_result(target, p1.second,p2.first);
        break;
    case 2:
        result = Find_result(target, p1.first,p2.second);
        break;
    case 3:
        result = Find_result(target, p1.first,p2.first);
        break;
    }
    return result;
}

void Find_closet(def(p1,p2,target)){
    int a[4];
    a[0] = p1.first+p2.first;
    a[1] = p1.first+p2.second;
    a[2] = p1.second+p2.first;
    a[3] = p1.second+p2.second;
    int intDiff = 0;
    int intDiffMin = INT_MAX;
    int intNear = 0;
    int index=0;
    float cmp_1, cmp_2;
    REP(i,4){
        intDiff = a[i] - target.first;
        if(abs(intDiffMin) >= abs(intDiff))
        {
            intDiffMin = intDiff;
            intNear = a[i];
            index = i;
        }
    }
    FOR(j,1,4){
        if(a[j] == a[j-1]){
            cmp_1 = j; cmp_2 = j-1;
        }
    }
    if(intNear > target.first) target.first = intNear;
    float result = Make_result(p1,p2,target,index);
    if(cmp_1 != 0){
    result = min(result, Make_result(p1,p2,target,cmp_2));
    result = min(result, Make_result(p1,p2,target,cmp_1));
    }   
    cout <<result<<"\n";
}

void Find_biggest_pair(def(p1,p2,p3)){
    if(p1.first >= p2.first && p1.first >= p3.first){
        Find_closet(p2,p3,p1);
    }
    else if(p2.first >= p1.first && p2.first >= p3.first){
        Find_closet(p1,p3,p2);
    }
    else if(p3.first >= p1.first && p3.first >= p2.first){
        Find_closet(p2,p1,p3);
    }
}

float Other_result(def(p1,p2,p3)){
    float target, other;
    if(p1.first == p2.first){
        target = p1.first+p2.second;
        other = p1.second+p3.second;
        return pow(target,2) + pow(other,2);
    }
    if(p1.first == p3.first){
        target = p1.first+p3.second;
        other = p1.second+p2.second;
        return pow(target,2) + pow(other,2);
    }
}

int main(){
    pair <int,int> p1, p2, p3;
    Input_Pair(p1);
    Input_Pair(p2);
    Input_Pair(p3);
    if(p1.first == p2.first || p1.first == p3.first){
    float result = Other_result(p1,p2,p3);
    cout << result << "\n";
    }
    else Find_biggest_pair(p1,p2,p3);
    return 0;
}