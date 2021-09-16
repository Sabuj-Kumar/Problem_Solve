 #include<stdio.h>
 #include<bits/stdc++.h>

 using namespace std;

 int main()
 {
     int test,value,i,j;

     scanf("%d",&test);

     for(i = 1; i <= test; i++)
     {
         deque<int> input;
         int s,limit;

         cout<<"Case " << i <<":\n";
         cin>>s;
         cin>>limit;

         for(j = 0; j < limit; j++)
         {
            string a;
            cin>>a;

            if(a == "pushLeft"  || a  == "pushRight")
            {
                cin>>value;

                if(input.size() < s)
                {
                    if(a == "pushLeft")
                    {
                        input.push_front(value);
                        cout<<"Pushed in left: "<<input.front()<<"\n";
                    }
                    else
                    {
                        input.push_back(value);
                        cout<<"Pushed in right: "<<input.back()<<"\n";
                    }
                }
                else
                    cout<<"The queue is full\n";
            }

            else if(a == "popLeft" || a == "popRight")
            {
                if(input.size() > 0)
                {
                    if(a == "popLeft")
                    {
                        cout<<"Popped from left: "<<input.front()<<"\n";
                        input.pop_front();
                    }
                    else
                    {
                        cout<<"Popped from right: "<<input.back()<<"\n";
                        input.pop_back();
                    }
                }
                else
                    cout<<"The queue is empty\n";
            }
         }
     }
     return 0;
 }
