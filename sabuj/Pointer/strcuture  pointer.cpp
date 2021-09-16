#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

struct student
{
    char a[20];
    int id;
};
int main()
{
    struct student st;
    struct student *p;

    p = &st;

    sf("%s",p->a);
    sf("%d",&p->id);

    pf("name is : %s\n",(*p).a);
    pf("id is : %d\n",(*p).id);

///    pf("name is : %s\n",p->a); we can use also this type.
///    pf("id is : %d\n",p->id);


    pf("name is : %s\n",st.a);
    pf("id is : %d\n",st.id);

    return 0;
}
