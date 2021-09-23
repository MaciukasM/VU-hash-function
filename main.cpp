#include "headeriai.hpp"
#include "testai.hpp"

int main()
{
    int sk;

    do
    {
        cout<<"Iveskite savo pasirinkima ivede skaiciu: "<<endl;
        cout<<"\n1 - Duomenu ivedimas ir hash'inimas\n2 - Paprastu failu hash'inimas ir lyginimas\n3 - konstitucija.txt hash'avimo matavimas\n4 - Sugeneruotu poru hash'inimas ir lyginimas" <<endl;
        cin>>sk;
    } while (sk<1 && sk>4);
    
    TestoPasirinkimas(sk);
    

    
}