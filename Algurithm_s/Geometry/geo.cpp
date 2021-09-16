#include<bits/stdc++.h>
using namespace std;

int dot(int[] A, int[] B, int[] C){

    AB = new int[2];
    BC = new int[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    BC[0] = C[0]-B[0];
    BC[1] = C[1]-B[1];
    int dot = AB[0] * BC[0] + AB[1] * BC[1];

    return dot;
}
int cross(int[] A, int[] B, int[] C){

    AB = new int[2];
    AC = new int[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    AC[0] = C[0]-A[0];
    AC[1] = C[1]-A[1];
    int cross = AB[0] * AC[1] - AB[1] * AC[0];

    return cross;
}

double distance(int[] A, int[] B){

    int d1 = A[0] - B[0];
    int d2 = A[1] - B[1];

    return sqrt(d1d1+d2d2);
}

double linePointDist(int[] A, int[] B, int[] C, boolean isSegment){

    double dist = cross(A,B,C) / distance(A,B);

    if(isSegment){

        int dot1 = dot(A,B,C);
        if(dot1 > 0)return distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return distance(A,C);
    }
    return abs(dist);
}
double linePointDist(point A, point B, point C, bool isSegment){

    double dist = ((B-A)^(C-A)) / sqrt((B-A)(B-A));

    if(isSegment){

        int dot1 = (C-B)(B-A);
        if(dot1 > 0)return sqrt((B-C)(B-C));
        int dot2 = (C-A)(A-B);
        if(dot2 > 0)return sqrt((A-C)*(A-C));
    }
    return abs(dist);
}
int main(){


    return 0;
}

