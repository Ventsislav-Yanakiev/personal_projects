#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
    int a,b,c,D;

    double x1, x2;

    cout << "Input a:";

    cin >> a ;

    cout << "Input b:";

    cin >> b ;

    cout << "Input c:";
    cin >> c ;

    D=b*b-4*a*c;

    x1 = (-b+sqrt(D))/ (2*a);

    x2 = (-b-sqrt(D))/(2*a);
    if(D<0)
    {
        cout<<"D<0";
    }
    else{
    cout<<a<<"x^2+"<<b<<"x+"<<c<<endl;
    cout<<"x1="<<x1<<endl;
    cout<<"x1="<<x2<<endl;
    return 0;
    }
}
