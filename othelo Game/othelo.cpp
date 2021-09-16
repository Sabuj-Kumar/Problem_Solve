/**
        University Of Asia Pacific

        Sabuj Kumar Tarofdar

        ID:  17101139       "Believe Yourself" "Play With Brain".

        "Othelo Game.
**/

#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

char matrix[ 9 ][ 9 ];
int x,y;

void print(){

    cout << "  0 1 2 3 4 5 6 7\n";

    for(int i = 0; i < 8; i++){

        cout << i << " ";

        for(int j = 0; j < 8; j++) cout << matrix[ i ][ j ] << " ";
        cout << endl;
    }
    cout << endl;
}

void matrix_build(){

     for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {

            if(i == 3 and j == 3 or i == 4 and j == 4) matrix[ i ][ j ] = 'O';
            else if((i == 3 and j == 4) or (i == 4 and j == 3)) matrix[ i ][ j ] = '#';

            else  matrix[ i ][ j ] = '.';
        }

    print();
}
bool check(){

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++) {

            if(matrix[ i ][ j ] == '.') return true;
        }
    }
    return false;
}

/// 64 * 64 * 64 = 262,144; Time Complexity

bool diagonal1(bool flag,int x,int y){

    int c1 = 0,c2 = 0,x1 = 0,y1 = 0;

    if(flag){

        x1 = x,y1 = y;

        while(x1 < 7 and y1 < 7){

            x1++;
            y1++;

            if(matrix[ x1 ][ y1 ] == '#' and matrix[ x1 ][ y1 ] != '.' and matrix[ x1 ][ y1 ] != 'O') c1++;
            else if(matrix[ x1 ][ y1 ] == '.' or matrix[ x1 ][ y1 ] == 'O') {

                if(matrix[ x1 ][ y1 ] == '.') c1 = 0;
                break;
            }
            if(x1 == 7 or y1 == 7 and matrix[ x1 ][ y1 ] == '#')c1 = 0;
        }

        x1 = x,y1 = y;

        while(x1 > 0 and y1 > 0){

            x1--;
            y1--;

            if(matrix[ x1 ][ y1 ] == '#' and matrix[ x1 ][ y1 ] != '.' and matrix[ x1 ][ y1 ] != 'O') c2++;
            else if(matrix[ x1 ][ y1 ] == '.' or matrix[ x1 ][ y1 ] == 'O') {

                if(matrix[ x1 ][ y1 ] == '.') c2 = 0;
                break;
            }
            if(x1 == 0 or y1 == 0 and matrix[ x1 ][ y1 ] == '#')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        x1 = x,y1 = y;

        matrix[ x ][ y ] = 'O';

        for(int i = 0; i < c1; i++){

            x1++;
            y1++;

            matrix[ x1 ][ y1 ] = 'O';
        }

        x1 = x,y1 = y;

        for(int i = 0; i < c2; i++){

            x1--;
            y1--;

            matrix[ x1 ][ y1 ] = 'O';
        }
        return true;
    }
    else {

        x1 = x,y1 = y;
        c1 = 0,c2 = 0;

        while( x1 < 7 and y1 < 7){

            x1++;
            y1++;

            if(matrix[ x1 ][ y1 ] == 'O' and matrix[ x1 ][ y1 ] != '.' and matrix[ x1 ][ y1 ] != '#') c1++;
            else if(matrix[ x1 ][ y1 ] == '.' or matrix[ x1 ][ y1 ] == '#') {

                if(matrix[ x1 ][ y1 ] == '.') c1 = 0;
                break;
            }
            if(x1 == 7 or y1 == 7 and matrix[ x1 ][ y1 ] == 'O') c1 = 0;
        }

        x1 = x,y1 = y;

        while(x1 > 0 and y1 > 0){

            x1--;
            y1--;

            if(matrix[ x1 ][ y1 ] == 'O' and matrix[ x1 ][ y1 ] != '.' and matrix[ x1 ][ y1 ] != '#') c2++;
            else if(matrix[ x1 ][ y1 ] == '.' or matrix[ x1 ][ y1 ] == '#') {

                if(matrix[ x1 ][ y1 ] == '.') c2 = 0;
                break;
            }
            if(x1 == 0 or y1 == 0 and matrix[ x1 ][ y1 ] == 'O')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        x1 = x,y1 = y;

        matrix[ x ][ y ] = '#';

        for(int i = 0; i < c1; i++){

            x1++;
            y1++;

            matrix[ x1 ][ y1 ] = '#';
        }
        x1 = x,y1 = y;

        for(int i = 0; i < c2; i++){

            x1--;
            y1--;

            matrix[ x1 ][ y1 ] = '#';
        }
        return true;
    }
}

bool diagonal2(bool flag,int x,int y){

    int c1 = 0,c2 = 0,x1 = 0,y1 = 0;

    if(flag){

        x1 = x,y1 = y;

        while(x1 < 7 and y1 > 0){

            x1++;
            y1--;

            if(matrix[ x1 ][ y1 ] == '#' and matrix[ x1 ][ y1 ] != '.' and matrix[ x1 ][ y1 ] != 'O') c1++;
            else if(matrix[ x1 ][ y1 ] == '.' or matrix[ x1 ][ y1 ] == 'O') {

                if(matrix[ x1 ][ y1 ] == '.') c1 = 0;
                break;
            }
            if(x1 == 7 or y1 == 0 and matrix[ x1 ][ y1 ] == '#')c1 = 0;
        }

        x1 = x,y1 = y;

        while(x1 > 0 and y1 < 7){

            x1--;
            y1++;

            if(matrix[ x1 ][ y1 ] == '#' and matrix[ x1 ][ y1 ] != '.' and matrix[ x1 ][ y1 ] != 'O') c2++;
            else if(matrix[ x1 ][ y1 ] == '.' or matrix[ x1 ][ y1 ] == 'O') {

                if(matrix[ x1 ][ y1 ] == '.') c2 = 0;
                break;
            }
            if(x1 == 0 or y1 == 7 and matrix[ x1 ][ y1 ] == '#')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        x1 = x,y1 = y;

        matrix[ x ][ y ] = 'O';

        for(int i = 0; i < c1; i++){

            x1++;
            y1--;

            matrix[ x1 ][ y1 ] = 'O';
        }

        x1 = x,y1 = y;

        for(int i = 0; i < c2; i++){

            x1--;
            y1++;

            matrix[ x1 ][ y1 ] = 'O';
        }
        return true;
    }
    else {

        x1 = x,y1 = y;
        c1 = 0,c2 = 0;

        while( x1 < 7 and y1 > 0){

            x1++;
            y1--;

            if(matrix[ x1 ][ y1 ] == 'O' and matrix[ x1 ][ y1 ] != '.' and matrix[ x1 ][ y1 ] != '#') c1++;
            else if(matrix[ x1 ][ y1 ] == '.' or matrix[ x1 ][ y1 ] == '#') {

                if(matrix[ x1 ][ y1 ] == '.') c1 = 0;
                break;
            }
            if(x1 == 7 or y1 == 0 and matrix[ x1 ][ y1 ] == 'O')c1 = 0;
        }

        x1 = x,y1 = y;

        while(x1 > 0 and y1 < 7){

            x1--;
            y1++;

            if(matrix[ x1 ][ y1 ] == 'O' and matrix[ x1 ][ y1 ] != '.' and matrix[ x1 ][ y1 ] != '#') c2++;
            else if(matrix[ x1 ][ y1 ] == '.' or matrix[ x1 ][ y1 ] == '#') {

                if(matrix[ x1 ][ y1 ] == '.') c2 = 0;
                break;
            }
            if(x1 == 0 or y1 == 7 and matrix[ x1 ][ y1 ] == 'O')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        x1 = x,y1 = y;

        matrix[ x ][ y ] = '#';

        for(int i = 0; i < c1; i++){

            x1++;
            y1--;
            matrix[ x1 ][ y1 ] = '#';
        }

        x1 = x,y1 = y;

        for(int i = 0; i < c2; i++){

            x1--;
            y1++;

            matrix[ x1 ][ y1 ] = '#';
        }
        return true;
    }
}

bool row(bool flag,int x,int y){

    int y1 = 0;
    int c1 = 0,c2 = 0;

    if( flag ){

        y1 = y;

        while(y1 < 7){

            y1++;

            if(matrix[ x ][ y1 ] == '#' and matrix[ x ][ y1 ] != '.' and matrix[ x ][ y1 ] != 'O') c1++;
            else if(matrix[ x ][ y1 ] == '.' or matrix[ x ][ y1 ] == 'O'){

                if(matrix[ x ][ y1 ] == '.') c1 = 0;
                break;
            }
            if(y1 == 7 and matrix[ x ][ y1 ] == '#')c1 = 0;
        }

        y1 = y;

        while(y1 > 0){

            y1--;

            if(matrix[ x ][ y1 ] == '#' and matrix[ x ][ y1 ] != '.' and matrix[ x ][ y1 ] != 'O') c2++;
            else if(matrix[ x ][ y1 ] == '.' or matrix[ x ][ y1 ] == 'O'){

                if(matrix[ x ][ y1 ] == '.') c2 = 0;
                break;
            }
            if(y1 == 0 and matrix[ x ][ y1 ] == '#')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        y1 = y;

        matrix[ x ][ y1 ] = 'O';

        for(int i = 0; i < c1; i++) {

            y1++;
            matrix[ x ][ y1 ] = 'O';
        }

        y1 = y;

        for(int i = 0; i < c2; i++) {

            y1--;
            matrix[ x ][ y1 ] = 'O';
        }
        return true;
    }
    else{

        c1 = 0,c2 = 0;

        y1 = y;

        while(y1 < 7){

            y1++;

            if(matrix[ x ][ y1 ] == 'O' and matrix[ x ][ y1 ] != '.' and matrix[ x ][ y1 ] != '#') c1++;
            else if(matrix[ x ][ y1 ] == '.' or matrix[ x ][ y1 ] == '#'){

                if(matrix[ x ][ y1 ] == '.') c1 = 0;
                break;
            }
            if(y1 == 7 and matrix[ x ][ y1 ] == 'O') c1 = 0;
        }

        y1 = y;

        while(y1 > 0){

            y1--;

            if(matrix[ x ][ y1 ] == 'O' and matrix[ x ][ y1 ] != '.' and matrix[ x ][ y1 ] != '#') c2++;
            else if(matrix[ x ][ y1 ] == '.' or matrix[ x ][ y1 ] == '#'){

                if(matrix[ x ][ y1 ] == '.') c2 = 0;
                break;
            }
            if(y1 == 0 and matrix[ x ][ y1 ] == 'O')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        y1 = y;

        matrix[ x ][ y1 ] = '#';

        for(int i = 0; i < c1; i++) {

            y1++;
            matrix[ x ][ y1 ] = '#';
        }

        y1 = y;

        for(int i = 0; i < c2; i++) {

            y1--;
            matrix[ x ][ y1 ] = '#';
        }
        return true;
    }
}

bool cullume(bool flag,int x,int y){

    int x1 = 0;
    int c1 = 0,c2 = 0;

    if( flag ){

        x1 = x;

        while(x1 < 7){

            x1++;

            if(matrix[ x1 ][ y ] == '#' and matrix[ x1 ][ y ] != '.' and matrix[ x1 ][ y ] != 'O') c1++;
            else if(matrix[ x1 ][ y ] == '.' or matrix[ x1 ][ y ] == 'O'){

                if(matrix[ x1 ][ y ] == '.') c1 = 0;
                break;
            }
            if(x1 == 7 and matrix[ x1 ][ y ] == '#')c1 = 0;
        }

        x1 = x;

        while(x1 > 0){

            x1--;

            if(matrix[ x1 ][ y ] == '#' and matrix[ x1 ][ y ] != '.' and matrix[ x1 ][ y ] != 'O') c2++;
            else if(matrix[ x1 ][ y ] == '.' or matrix[ x1 ][ y ] == 'O'){

                if(matrix[ x1 ][ y ] == '.') c2 = 0;
                break;
            }
            if(x1 == 0 and matrix[ x1 ][ y ] == '#')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        x1 = x;

        matrix[ x1 ][ y ] = 'O';

        for(int i = 0; i < c1; i++) {

            x1++;
            matrix[ x1 ][ y ] = 'O';
        }

        x1 = x;

        for(int i = 0; i < c2; i++) {

            x1--;
            matrix[ x1 ][ y ] = 'O';
        }
        return true;
    }
    else{

        c1 = 0,c2 = 0;

        x1 = x;

        while(x1 < 7){

            x1++;

            if(matrix[ x1 ][ y ] == 'O' and matrix[ x1 ][ y ] != '.' and matrix[ x1 ][ y ] != '#') c1++;
            else if(matrix[ x1 ][ y ] == '.' or matrix[ x1 ][ y ] == '#'){

                if(matrix[ x1 ][ y ] == '.') c1 = 0;
                break;
            }
            if(x1 == 7 and matrix[ x1 ][ y ] == 'O') c1 = 0;
        }

        x1 = x;

        while(x1 > 0){

            x1--;

            if(matrix[ x1 ][ y ] == 'O' and matrix[ x1 ][ y ] != '.' and matrix[ x1 ][ y ] != '#') c2++;
            else if(matrix[ x1 ][ y ] == '.' or matrix[ x1 ][ y ] == '#'){

                if(matrix[ x1 ][ y ] == '.') c2 = 0;
                break;
            }
            if(x1 == 0 and matrix[ x1 ][ y ] == 'O')c2 = 0;
        }

        if(c1 == 0 and c2 == 0) return false;

        x1 = x;

        matrix[ x1 ][ y ] = '#';

        for(int i = 0; i < c1; i++) {

            x1++;
            matrix[ x1 ][ y ] = '#';
        }

        x1 = x;

        for(int i = 0; i < c2; i++) {

            x1--;
            matrix[ x1 ][ y ] = '#';
        }
        return true;
    }
}

void invalid(){

    cout << "\n\n" << "Enter The Valid Point Please.\n\n";
}
bool white(int x,int y){

    if(matrix[ x ][ y ] != '.'){

        invalid();

        return true;
    }
    bool d1 = diagonal1(true,x,y);
    bool d2 = diagonal2(true,x,y);
    bool rw = row(true,x,y);
    bool clm = cullume(true,x,y);

    if(d1 or d2 or rw or clm){

        return false;
    }

    invalid();

    return true;
}

bool black(int x,int y){

    if(matrix[ x ][ y ] != '.'){

        invalid();

        return false;
    }
    bool d1 = diagonal1(false,x,y);
    bool d2 = diagonal2(false,x,y);
    bool rw = row(false,x,y);
    bool clm = cullume(false,x,y);

    if(d1 or d2 or rw or clm){

        return true;
    }

    invalid();

    return false;
}
void valid_move(){


}
void Othelo_game(){

    bool flag = false;

    while( check() ){

        while( flag and check() ){

            cout << "For White Enter The Valid Point =  ";
            cin >> x >> y;
            cout << endl;

            bool f = white(x,y);

            print();

            flag = f;
        }
        while(!flag and check()){

            cout << "For Black Enter The Valid Point =  ";
            cin >> x >> y;
            cout << endl;

            bool f = black(x,y);

            print();

            flag = f;
        }
    }
}

int main(){

    /// white = O black = #
    matrix_build();

    string s,p = "Opponent";
    int b = 0,w = 0;

    cout << "Enter Your Name Please =   ";
    cin >> s;

    Othelo_game();

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            if(matrix[ i ][ j ] == 'O') w++;
            else b++;
        }
    }

    cout << "Black " << b << " White " << w << endl << endl;

    if(b > w) cout << s << "  WIN" << endl;
    else cout << p << " WIN" << endl;

    return 0;
}
