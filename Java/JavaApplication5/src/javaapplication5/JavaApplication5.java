package javaapplication5;

import java.util.*;

class Java
{
    int sum(int a,int b)
    {
        System.out.println(a+b); 
        return 0;
    }
}
class number extends Java
{
    double input;
    int a;
    int b;
}
public class JavaApplication5
{
    int num;
    
    class number1
    {
        void call()
        {
            System.out.println("OK\n");
        }
    }
    void check()
    {
        System.out.println("CHECK\n");
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        
        number n = new number();
        
       JavaApplication5 n1 = new JavaApplication5();
       
       n1.check();
        
       n.a = scan.nextInt();
       n.b = scan.nextInt();
       n.input = scan.nextDouble();
       
       n.sum(n.a,n.b);
       
    }
}

