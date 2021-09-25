#include "headeriai.hpp"
#include "testai.hpp"

int main()
{
    int sk;

    do
    {
        cout<<"Iveskite savo pasirinkima ivede skaiciu: "<<endl;
        cout<<"\n1 - Duomenu ivedimas ir hash'inimas\n2 - Paprastu failu hash'inimas ir lyginimas\n3 - konstitucija.txt hash'avimo matavimas\n4 - Sugeneruotu poru hash'inimas ir lyginimas (atsparumas kolizijoms)\n5 - Hash'u procentinio skirtingumo tikrinimas\n6 - Spartos lyginimas su SHA-256, SHA-1 ir MD-5 funkcijomis (tam naudojama 3-ioji uzduotis)\n" <<endl;
        cin>>sk;
    } while (sk<1 && sk>5);
    
    TestoPasirinkimas(sk);
    

    
}