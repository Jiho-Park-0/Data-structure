#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i = int(a); i < int(b); i ++)
#define REP(i,b) FOR(i,0,b)

void input_queue(vector <queue<int>> &vec, int N){
    int input;
    queue <int> q;
    REP(i,N){
        while(true){
            cin >> input;
            q.push(input);
            if(input == 0) break;
        }
        vec.push_back(q);
        while(!q.empty()) q.pop();
    }
}

void Print_result(vector <queue<int>> vec, int N){
    while(true){
        int index = 0;
        int small_value = vec[0].front();
        FOR(i,1,N){
            if(vec[i].front() != 0 && (small_value > vec[i].front() || small_value == 0)){
                small_value = vec[i].front();
                index = i;
            }
        }
        if(small_value == 0) break;
        cout << small_value <<"\n";
        vec[index].pop();
    }
}

int main(){
    int N;
    vector <queue<int>> vec;
    cin >> N;
    input_queue(vec,N);
    Print_result(vec, N);
    return 0;
}