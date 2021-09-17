#include <iostream>
#include <vector>
#define t 5
#define for(i,a,b) for(int i = int(a); i<int(b); i++)

using namespace std;

int main(void) {

    int print = 0;
    int time[t];
    int size;
    cin >> size;
    vector<vector<int>> p(size, vector<int>(2, 0));
    for (i ,0 , size) {
        cin >> p[i][0] >> p[i][1];
    }
    for (i, 0, t) {
        cin >> time[i];
    }
    
    
    for(print, 0 ,t){
        int sec = 0;
        int nowX = p[0][0];
        int nowY = p[0][1];
        int next = 1;
        while (true) {

            while (nowX != p[next][0]) {

                if (nowX > p[next][0]) {
                    nowX -= 1;
                    sec++;
                    if (sec == time[print])
                        break;
                }
                else {
                    nowX += 1;
                    sec++;
                    if (sec == time[print])
                        break;
                }
            }
            while (nowY != p[next][1]) {

                if (nowY > p[next][1]) {
                    nowY -= 1;
                    sec++;
                    if (sec == time[print])
                        break;
                }
                else {
                    nowY += 1;
                    sec++;
                    if (sec == time[print])
                        break;
                }
            }
            next++;
            if (next == size)
                next = 0;
            if (sec == time[print]) {
                cout << nowX << " " << nowY << endl;
                break;
            }
        }        
    }   
}