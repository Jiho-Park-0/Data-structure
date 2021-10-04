#include <bits/stdc++.h>
using namespace std;

typedef struct{
    string stuname;
    vector <int> resports;
} Sreport;

void show_data( vector< Sreport > IN){
    for(auto Ones : IN) {
        cout << "\n" << Ones.stuname;
        for(auto w: Ones.resports){
            cout << " " << w << ", ";
        }
    }
}

void read_show( vector< Sreport > &X ){
    int N, score  ;
    string sname ; //학생 이름
    Sreport onerep ; // 학생이 제출한 보고서의 성적 vector

    cin >> N ;
    for(int i=1; i <= N; i++){
        cin >> sname ;
        onerep.stuname = sname;
        onerep.resports.clear();
        while( 1 ){
            cin >> score ;
            if( score == 0 ) break ;
            else onerep.resports.push_back( score ) ;
       }
       X.push_back( onerep ) ;
    } // end of for i

} // end of read_show( )

bool myorder ( Sreport A, Sreport B ) {
    int Amin, Bmin, Asu, Bsu ;
    Asu = A.resports.size();
    Bsu = B.resports.size();
    if( Asu > Bsu ) return(1) ;
    if( Asu < Bsu ) return(0) ;
    Amin = *min_element( A.resports.begin(), A.resports.end() );
    Bmin = *min_element( A.resports.begin(), A.resports.end() );
    return( Amin > Bmin );
}

void printout( vector < Sreport > &X) {
    cout << "\n In printout() " ;
    cout << "\n student num : " << X.size() ;
    for(auto W : X) {
        cout << "\n";
        cout << W.stuname ;
        for(int points : W.resports){
            cout << " " << points;
        }
    }
}

void set_rank( vector < Sreport > &X ) {
    cout << "\n In set_rank( ) " ;
    cout << "\n student num : " << X.size() ;
    sort( X.begin(), X.end(), myorder );
}

int main(){
    vector< Sreport > Dreport ;

    read_show(Dreport);
    show_data(Dreport);
    set_rank(Dreport);
    printout(Dreport);

    return 0;
}