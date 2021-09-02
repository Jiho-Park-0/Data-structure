#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = int(a); i < int(b); i ++)
#define REP(i,b) FOR(i,0,b)
#define show(x) cout << x << " "
#define line_ cout << "\n";

using namespace std;
 
int main()
{
    vector<vector<int>> k;
    vector<int> input, l;
    int input_i;
    int i = 0;
    while(true){
        cin >> input_i;
        input.push_back(input_i);
        if(input[i] == 0) break;
        i++;
    }
    input_i = 1;
    int size = input.size();
    REP(i,size){
        l.clear();
        REP(j,input[i]){
            l.push_back(input_i);
        }
        l.push_back(0);
        k.push_back(l);
    }
    vector<int> add(input[0]);

    REP(i,k.size()){
        REP(j,k[i].size()){
            if(k[i][j] == 1){
            add[j] += 1;
        }
        }
    }
    add.push_back(0);
    REP(i,add.size()){
        show(add[i]);
    }

    return 0;
}