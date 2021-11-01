#include <iostream>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i = int(a); i < int(b); i ++)
#define REP(i,b) FOR(i,0,b)

enum string_code{
    efront, eback, ecut, edouble, eflip, ereport
};
string_code hashit (string const& inString) {
    if (inString == "cut")    return ecut;
    if (inString == "front")  return efront;
    if (inString == "back")   return eback;
    if (inString == "double") return edouble;
    if (inString == "flip")   return eflip;
    if (inString == "report") return ereport;
}
list<char> readfile() {
	list<char> g;
	ifstream file("/NESPA/sapiens.txt");
	string line;
	char t;
	getline(file, line);
	while (file.get(t))
	{
		if (t != '\n') {
			g.push_back(t);
		}
	}
	file.close();
	return g;
}
void print_list(list<char> genome){
    for(char cr : genome){
        cout << cr;
    }
    cout << "\n";
}

int main(){
    
    list<char> genome = readfile();
    int N, x, y;
    string input_;
    vector<list<char>> result;
    list<char> box;
    cin >> N;
    REP(i,N){
        cin >> input_;
        cin >> x >> y;
        auto it1 = genome.begin(); advance(it1, x-1);
        auto it2 = genome.begin(); advance(it2, y);
    switch (hashit(input_)) {
    case efront:
        genome.splice(genome.begin(),genome,it1,it2);  
        continue;
    case eback:
        genome.splice(genome.end(),genome,it1,it2);  
        continue;
    case ecut:
        genome.erase(it1,it2);  
        continue;
    case edouble:
        box.splice(box.begin(), genome, it1, it2);
        REP(i,2){
            it1 = genome.begin(); advance(it1, x-1);
            genome.insert(it1,box.begin(),box.end());  
        }
        box.clear(); continue;
    case eflip:
        box.splice(box.begin(), genome, it1, it2); box.reverse();
        it1 = genome.begin(); advance(it1, x-1);
        genome.insert(it1,box.begin(),box.end());  
        box.clear(); continue;
    case ereport:
        if(it1 == it2) box.push_back(*it1);
        else for(it1; it1 != it2; it1++){
            box.push_back(*it1);
        }
        result.push_back(box);
        box.clear();
        continue;
    }
    }
    REP(i,result.size()){
        print_list(result[i]);
    }
}