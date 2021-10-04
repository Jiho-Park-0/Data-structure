#include <iostream>
#include <vector>
#define swap(a,b) {int t; t = a; a = b; b = t;}
#define pm(a,b,c) {a += c; b -= c;}
#define FOR(i,a,b) for(int i = int(a); i < int(b); i ++)
#define REP(i,b) FOR(i,0,b)

using namespace std;

int nstate(int a, int b);
int plusminus(int x, int next);

int main(void) {
    
    double time;
    int size;

    cin >> size;
    vector<vector<int>> box(size, vector<int>(2, 0));
    REP(i,size) {
        cin >> box[i][0] >> box[i][1];
    }
    cin >> time;

    int v = 1;
    int sec = 0;
    int sec2 = 0;
    int nowX1 = box[0][0];
    int nowY1 = box[0][1];
    int nowX2 = box[size / 2 - 1][0];
    int nowY2 = box[size / 2 - 1][1];
    int next1 = 1;
    int next2 = size / 2 - 2;
    while (sec != time) {    
    repeat:
    next1 = nstate(next1, size);
    next2 = nstate(next2, size);
    nowX1 += plusminus(nowX1, box[next1][0]);
    nowY1 += plusminus(nowY1, box[next1][1]);
    if (nowX1 == box[next1][0] && nowY1 == box[next1][1])
        next1 += v;
    nowX2 += plusminus(nowX2, box[next2][0]);
    nowY2 += plusminus(nowY2, box[next2][1]);
    if (nowX2 == box[next2][0] && nowY2 == box[next2][1])
        next2 -= v;
    sec++;
    if ((nowX1 == nowX2) && (nowY1 == nowY2)) {
        v *= (-1);
        pm(next1, next2, v);
        if (next1 == next2) {
            pm(next1, next2, v);
            goto repeat;
        }
        if ((abs(next1 - next2) > 1)) {
            if (abs(next1 - next2) == size - 1)
                goto repeat;
            v *= (-1);
            pm(next1, next2, v);
        }
    }
    if ((nowX1 == nowX2) && abs(nowY1 - nowY2) == 1) {
        sec2++;
        if (sec2 % 2 == 1) {
            if (sec == time) {
                break;
            }
            goto repeat;
        }
        swap(nowY1, nowY2);
        v *= (-1);
        pm(next1, next2, v);
    }
    if ((nowY1 == nowY2) && abs(nowX1 - nowX2) == 1) {
        sec2++;
        if (sec2 % 2 == 1) {
            if (sec == time) {
                break;
            }
            goto repeat;
        }
        swap(nowX1, nowX2);
        v *= (-1);
        pm(next1, next2, v);
    }
}
    cout << nowX1 << " " << nowY1 << endl;
    cout << nowX2 << " " << nowY2 << endl;
}

int nstate(int a, int b) {
    if (a == b)
        return 0;
    else if (a == -1)
        return (b - 1);
    return a;
}

int plusminus(int x, int next) {
    if (x > next) {
        return -1;
    }
    else if (x < next) {
        return 1;
    }
    return 0;
}