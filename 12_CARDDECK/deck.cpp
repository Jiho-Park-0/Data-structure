#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i = int(a); i < int(b); i ++)
#define REP(i,b) FOR(i,0,b)

typedef struct
{
    string str;
    int i = 0;
    int j = 0;
}Input;

void shuffle_deck(list<int> &li, int N){
    list<int>::iterator it = li.begin();
    
    advance(it,N/2);
    list<int> li2, box;
    li2.splice(li2.begin(), li, it, li.end());
    list<int>::iterator it3 = li.begin();
    list<int>::iterator it2 = li2.begin();
    
    REP(i,N/2){
        box.push_back(*it3); it3++;
        box.push_back(*it2); it2++;
    }
    li = box;
}

void cut_deck(list<int> &li, int N, int K, vector<Input> vec){
    REP(i,K){
        if(vec[i].str == "Shuffle"){
            shuffle_deck(li,N);
        }
        if(vec[i].str == "Cut"){
            list<int>::iterator it = li.begin();
            list<int>::iterator it2 = li.begin();
            advance(it,vec[i].i-1);
            advance(it2,vec[i].j);

            li.splice(li.end(), li, it, it2);
        }
            
    }
}

void print_deck(list<int> li, int N){
    auto it1 = li.begin();
    cout << *it1 <<" ";
    advance(it1, N/2-1);
    cout << *it1 <<" ";
    advance(it1, N/2);
    cout << *it1 <<"\n";
}

void input_list(list<int> &li, int &N, int &K, vector<Input> &vec2){
    cin >> N >> K;
    REP(i,N){
        li.push_back(i+1);
    }
    vector<Input> vec(K);
    REP(i,K){
        int i_, j_;
        string str;
        cin >> str;
        if(str == "Shuffle") vec[i].str = str;
        if(str == "Cut") {
            vec[i].str = str;
            cin >> i_ >> j_;
            vec[i].i = i_; vec[i].j = j_;
        }
    }
    vec2 = vec;
}

int main(){

    int N, K;
    list<int> li;
    vector<Input> vec;
    input_list(li,N,K,vec);
    cut_deck(li,N,K,vec);
    print_deck(li,N);
    
    return 0;         
}