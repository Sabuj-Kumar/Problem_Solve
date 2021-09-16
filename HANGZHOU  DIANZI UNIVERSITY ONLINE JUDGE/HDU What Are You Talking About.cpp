#include<bits/stdc++.h>
#define in freopen("in.txt","r",stdin);

using namespace std;

const int N = 1003333;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct stn{

    char s[ 12 ],d[ 12 ];
};

struct node{

    int x;
    node *next[ 26 ];
    node(){

        x = 0;
        for(int i = 0; i < 26; i++) next[ i ] = NULL;
    }

}* root;

void insert_(char *s,int flag){

    node *temp = root;

    for(int i = 0; s[ i ] != '\0'; i++){

        int id = s[ i ] - 'a';

        if(temp -> next[ id ] == NULL) temp -> next[ id ] = new node();

        temp = temp -> next[ id ];
    }
    temp -> x = flag;
}

int search_(char *s){

    node *temp = root;

    for(int i = 0; s[ i ] != '\0'; i++){

        int id = s[ i ] - 'a';

        if(temp -> next[ id ] == NULL) return 0;

        temp = temp -> next[ id ];
    }
    return temp -> x;
}

void Delete(node *temp){

    for(int i = 0; i < 26; i++)
        if(temp -> next[ i ] != NULL) Delete(temp -> next[ i ]);

    delete(temp);
}
stn ch[ N ];

int main(){

    file();

    char st[ 12 ],ss[ 1003 ],c[ 12 ];
    int k = 1;
    scanf("%s",st);
    root = new node();

    while(scanf("%s",ch[ k ].s) && strcmp(ch[ k ].s,"END")){

        scanf("%s",ch[ k ].d);
        insert_(ch[ k ].d,k);
        ++k;
    }

    scanf("%s",st);

    getchar();

    while(gets(ss) && strcmp(ss,"END")){

        k = 0;

        for(int i = 0; ss[ i ] != '\0'; i++){

            if(ss[ i ] >= 'a' && ss[ i ] <= 'z') c[ k++ ] = ss[ i ];
            else{

                if(k){

                    c[ k ] = '\0';

                    int idx = search_(c);

                    if(idx) printf("%s",ch[ idx ].s);
                    else printf("%s",c);
                    k = 0;
                }
                printf("%c",ss[ i ]);
            }
        }
        printf("\n");
    }
    //Delete( root );

    return 0;
}
