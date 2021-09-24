#include "testai.hpp"
#include "laikas.hpp"
#include "headeriai.hpp"

void TestoPasirinkimas(int pasirinkimas)
{
    if(pasirinkimas == 1) VartotojoIvedimas();
    if(pasirinkimas == 2) DviejuFailuLyginimas();
    if(pasirinkimas == 3) PoVienaEilute();
    if(pasirinkimas == 4) HashuPoruLyginimas();
}

void DviejuFailuLyginimas()
{
    //4 kintamieji lyginimui
    string hashas1;
    string hashas2;
    string hashas3;
    string hashas4;

    //failu pavadinimai
    string failas1;
    string failas2;

    /////////////////////////////////////////////////////////////
    //failai su 1 simboliu

    cout<<"\nPradedamas darbas su 1 simbolio ilgio failais..."<<endl;

    failas1 = "test/1s.txt";
    failas2 = "test/2s.txt";

    hashas1 = DarbasSuFailu(failas1);
    hashas2 = DarbasSuFailu(failas1);

    hashas3 = DarbasSuFailu(failas2);
    hashas4 = DarbasSuFailu(failas2);

    cout<<"\n1 simbolio failo nr.1 hash'as: "<<hashas1<<endl;
    cout<<"Tas pats failas perhash'intas: "<<hashas2<<endl;
    cout<<"Pirmo failo hash'ai sutampa = "<<boolalpha<<(hashas1 == hashas2)<<endl;

    cout<<"\n1 simbolio failo nr.2 hash'as: "<<hashas3<<endl;
    cout<<"Tas pats failas perhash'intas: "<<hashas4<<endl;
    cout<<"Antro failo hash'ai sutampa = "<<boolalpha<<(hashas3 == hashas4)<<endl;

    cout<<"\nSiu failu hashai nesutampa = "<<boolalpha<<(hashas1 != hashas3)<<endl;

    cout<<"------------------------------------------------------"<<endl;

    //failai su 1 simboliu
    /////////////////////////////////////////////////////////////
    //failai is 1000 random simboliu

    cout<<"\nPradedamas darbas su 1000 simboliu ilgio failais..."<<endl;

    failas1 = "test/1000s1.txt";
    failas2 = "test/1000s2.txt";

    hashas1 = DarbasSuFailu(failas1);
    hashas2 = DarbasSuFailu(failas1);

    hashas3 = DarbasSuFailu(failas2);
    hashas4 = DarbasSuFailu(failas2);

    cout<<"\n1000 simboliu failo nr.1 hash'as: "<<hashas1<<endl;
    cout<<"Tas pats failas perhash'intas:    "<<hashas2<<endl;
    cout<<"Pirmo failo hash'ai sutampa = "<<boolalpha<<(hashas1 == hashas2)<<endl;

    cout<<"\n1000 simboliu failo nr.2 hash'as: "<<hashas3<<endl;
    cout<<"Tas pats failas perhash'intas:    "<<hashas4<<endl;
    cout<<"Antro failo hash'ai sutampa = "<<boolalpha<<(hashas3 == hashas4)<<endl;

    cout<<"\nSiu failu hashai nesutampa = "<<boolalpha<<(hashas1 != hashas3)<<endl;

    cout<<"------------------------------------------------------"<<endl;

    //failai is 1000 random simboliu
    /////////////////////////////////////////////////////////////
    //failai, kurie skiriasi tik 1 simboliu (ilgis = 1500)

    cout<<"\nPradedamas darbas su 1500 simboliu ilgio failais (su 1 skirtingu simboliu)..."<<endl;

    failas1 = "test/1500+diff1.txt";
    failas2 = "test/1500+diff2.txt";

    hashas1 = DarbasSuFailu(failas1);
    hashas2 = DarbasSuFailu(failas1);

    hashas3 = DarbasSuFailu(failas2);
    hashas4 = DarbasSuFailu(failas2);

    cout<<"\n1500 simboliu failo nr.1 hash'as: "<<hashas1<<endl;
    cout<<"Tas pats failas perhash'intas:    "<<hashas2<<endl;
    cout<<"Pirmo failo hash'ai sutampa = "<<boolalpha<<(hashas1 == hashas2)<<endl;

    cout<<"\n1500 simboliu failo nr.2 hash'as: "<<hashas3<<endl;
    cout<<"Tas pats failas perhash'intas:    "<<hashas4<<endl;
    cout<<"Antro failo hash'ai sutampa = "<<boolalpha<<(hashas3 == hashas4)<<endl;

    cout<<"\nSiu failu hashai nesutampa = "<<boolalpha<<(hashas1 != hashas3)<<endl;

    cout<<"------------------------------------------------------"<<endl;
}

void PoVienaEilute()
{
    cout<<"\nHash'inamas failas 'konstitucija.txt po eilute...'\n"<<endl;

    LaikoMatavimas l;
    double visasLaikas = 0;
    string failas1 = "test/konstitucija.txt"; //is kur imsim faila
    string eilute;
    vector<string> hashai;

    ifstream in(failas1);

    while(in)
    {
        getline(in, eilute);

        l.reset();
        hashai.push_back(DuomenuHashinimas(eilute));
        visasLaikas += l.elapsed();
    }

    cout<<"'"<<failas1<<"' failo hash'avimas uztruko "<<visasLaikas<<" s."<<endl;

    /* for(int i = 0; i<hashai.size()-1; i++) //jei norim hashus paziuret
    {
        cout<<i<<" hash'as: "<<hashai[i]<<endl;
    } */
}

void HashuPoruLyginimas()
{
    string failas[4] = { "test/poros10.txt", "test/poros100.txt", "test/poros500.txt", "test/poros1000.txt"};
    int kolizijos;
    int visosKolizijos = 0;

    string eilute1;
    string eilute2;
    string hashas1;
    string hashas2;

    for(int i = 0; i<4; i++)
    {
        kolizijos = 0;
        cout<<"\nPradedamas darbas su failu '"<<failas[i]<<"'...\n"<<endl;
        
        ifstream in (failas[i]);

        while(in)
        {
            getline(in, eilute1);
            hashas1 = DuomenuHashinimas(eilute1);

            getline(in, eilute2);
            hashas2 = DuomenuHashinimas(eilute2);
            if(hashas1 == hashas2 && eilute1 != eilute2) ++kolizijos;
        }
        cout<<"Po "<<i+1<<"-ojo failo ("<<failas[i]<<") eiluciu hashavim'o rasta "<<kolizijos<<" koliziju(-os)."<<endl;
        visosKolizijos+=kolizijos;
    }
    cout<<"\nViso rasta "<<visosKolizijos<<" koliziju(-os)."<<endl;
}

/* void FailoGeneravimas(int ilgis, bool simbolioSkirtumas) //might add later
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
} */