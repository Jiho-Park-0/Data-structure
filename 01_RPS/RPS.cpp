#include <iostream>

using namespace std;

char answer(char player1, char player2){
    if(player1 == player2){ return 'D'; }
    else{
        if( ((player1 == 'R') && (player2 == 'S')) || ((player1 == 'S') && (player2 == 'P')) || ((player1 == 'P') && (player2 == 'R')) )  return player1; 
        else  return player2; 
    }
}

int main()
{
    char player1, player2;
    cin >> player1 >> player2;
    cout << answer(player1,player2) << "\n";
    
    return 0;
}