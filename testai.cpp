#include "testai.hpp"
#include "laikas.hpp"

void FailoGeneravimas(int ilgis, bool simbolioSkirtumas)
{
    srand(time(NULL));

    int sk;
    char simbolis;
    string tekstas;

    for (int i = 0; i<ilgis; i++)
    {
        sk = rand() % 93 + 32;
        simbolis = sk;
        tekstas += simbolis;
    }
    string failas = "test\test"+ilgis;
    ofstream out(failas);
    out<<tekstas;
    out.close();

    if (simbolioSkirtumas)
    {
        failas += "1skirt"; 
        sk = tekstas[0]+1;
        simbolis = sk;
        tekstas[0] = simbolis;
        ofstream out(failas);
        out<<tekstas;
        out.close();
    }
}