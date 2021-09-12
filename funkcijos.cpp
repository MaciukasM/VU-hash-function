#include "headeriai.hpp"

bool FailoTikrinimas(string failas)
{
    ifstream in(failas);
    return in.good();
}

string DarbasSuFailu(string failas)
{
    ifstream in(failas);
    string eilute;
    string duomenys;

    while(!in.eof())
    {
        getline(in, eilute);
        duomenys += eilute;
    }
    return DuomenuHashinimas(duomenys);
}

string VartotojoIvedimas()
{
    string ats;
    string failas;
    string duomenys;
    string hashas;

    while(ats!="y" && ats!="n")
    {
        cout<<"Ar duomenis imti is failo? (y/n): ";
        cin>>ats;
        if(ats!="y" && ats!="n") cout<<"\nIveskite atsakyma is naujo.\n"<<endl;
    }
    if(ats=="y")
    {
        cout<<"Iveskite failo pavadinima (pvz. failas.txt): ";
        cin>>failas;
        if(!FailoTikrinimas(failas))
        {
            cout<<"Tokio failo nerasta. Programos darbas baigiamas."<<endl;
            return 0;
        }
        hashas = DarbasSuFailu(failas);
    }
    else 
    {
        cout<<"Iveskite duomenis ranka: ";
        cin>>duomenys;
        hashas = DuomenuHashinimas(duomenys);
    }

    return hashas;
}