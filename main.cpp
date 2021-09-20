#include "headeriai.hpp"
#include "testai.hpp"

int main()
{
    int sk;

    do
    {
        cout<<"Iveskite savo pasirinkima ivede skaiciu: "<<endl;
        cout<<"\n1 - Duomenu ivedimas ir hash'inimas\n2 - failu poru hash'u lyginimas\n" <<endl;
        cin>>sk;
    } while (sk<1 && sk>2);
    
    TestoPasirinkimas(sk);
    

    
}