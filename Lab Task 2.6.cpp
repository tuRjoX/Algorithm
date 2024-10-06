#include <iostream>
using namespace std;

int converter(double c){
    double f=(c*9/5)+32;
    cout<<"Celsius to Fahrenheit : "<<f<<" C";

    cout<<endl;

    double f2c=(f-32)*5/9;
    cout<<"Fahrenheit to Celsius : "<<f2c<<" F";

}

int main()
{
    int x;
    cout<<"Enter The Value : ";
    cin>>x;

    converter(x);
    return 0;
}
