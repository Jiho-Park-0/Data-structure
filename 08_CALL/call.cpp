#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <ctype.h>

using namespace std;

#define FOR(i,a,b) for(int i = int(a); i < int(b); i ++)
#define REP(i,b) FOR(i,0,b)
#define f first
#define s second
typedef stack<string> stack_s;
typedef pair<char, stack_s> Pair;

void input(vector<Pair> &vec ,int &N, int &k1, int &k2){
    cin >> N >> k1 >> k2;
    stack_s s;
    char c;
    string str;
    REP(i,N){
        cin >> c;
        while (true)
        {
            cin >> str;
            s.push(str);
            if(str == "$") break;
        }
        vec.push_back(make_pair(c, s));
        while( !s.empty() ) s.pop();
    }
}
bool H = true;
void make_line(vector<Pair> vec, stack_s &result, vector<int> &count,  char check, int N){
    int i;
    string make = "-";
    for(i = 0; i < N; i++){
        if(vec[i].f == check) break;
    }
    stack_s con = vec[i].s;
    count[i] += 1;
    if(count[i] > 1){ H = false; return; }
    
    while(!vec[i].s.empty()){
        if(vec[i].s.top() == "$") { vec[i].s.pop(); }
        if(vec[i].s.empty()) break;
        check = vec[i].s.top().front();
        if( isupper(check) ){
            
            make_line(vec,result,count,check,N);
            vec[i].s.pop();
        }
        if(vec[i].s.empty()) break;
        make = vec[i].f + make + vec[i].s.top();
        
        result.push(make);
        vec[i].s.pop();
        make = "-";
    }
    count[i] -= 1;
    vec[i].s = con;
}

void make_answer(stack_s result, int k){
    stack_s answer = result;
    if(answer.size() < k || k == 0) {
            cout << "NONE" "\n";
            return;
        }
    REP(i,k-1){
        answer.pop();
    }
    cout << answer.top() << "\n";
}

int main(){
    
    int N, k1, k2;
    vector<Pair> vec;
    input(vec,N,k1,k2);

    vector<int> count(N,0);
    stack_s result;
    char cheak = vec[0].f;

    make_line(vec,result,count,cheak,N);

    if(H){
        make_answer(result, k1);
        make_answer(result, k2);
    }
    else {
        cout << "DEADLOCK" <<"\n";
    }
    
    return 0;
}