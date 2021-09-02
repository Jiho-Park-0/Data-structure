#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = int(a); i < int(b); i ++)
#define REP(i,b) FOR(i,0,b)
#define show(x) cout << x << " "

using namespace std;

//2차원벡터에 입력값만큼 1추가, 마지막에는 끝을 표기하기위해 0추가
void push_2nd_vector(vector<vector<int>> &k, vector<int> vec){ 
    vector<int> l;
    int i = 0, input_i = 1;
    int size = vec.size();
    REP(i,size){
        l.clear();
        REP(j,vec[i]){
            l.push_back(input_i);
        }
        l.push_back(0);
        k.push_back(l);
    }
}
//값 입력
void input_vector(vector<int> &vec){ 
    int input, i=0;
    while(true){
        cin >> input;
        vec.push_back(input);
        if(vec[i] == 0) break;
        i++;
    }
}
//출력(0~end)
void print_vector(vector<int> vec){
    REP(i,vec.size()){
        show(vec[i]);
    }
}
//stdout값 저장 stdin의 첫번째값만큼 확보, 각행이 1일때 +1
void make_result(vector<int> &result, vector<vector<int>> k){
    REP(i,k.size()){
        REP(j,k[i].size()){
            if(k[i][j] == 1){
            result[j] += 1;
        }
        }
    }
    result.push_back(0);
}

int main()
{
    vector<vector<int>> k;
    vector<int> input;

    input_vector(input);
    push_2nd_vector(k,input);

    vector<int> add(input[0]);
    make_result(add, k);
    print_vector(add);

    return 0;
}