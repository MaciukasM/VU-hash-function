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

string DuomenuHashinimas(string duomenys)
{
    string hash; // cia saugojamas hashas
    unsigned int temp = 12345; //kintamasis, kuriame laikomas skaicius, kuri vis keisime dauginant is ivairiu skaiciu (is pradziu sudauginsime su simboliu ascii vertemis ir pan.)
    int ascii = 0; //skaicius gautas is 'temp', kuri naudosim grazinti kokia nors ascii reiksme i hasha

    for(int i = 0; i<duomenys.length(); i++) //input'as keicia pati skaiciu
    {
        temp = (temp * (int(duomenys[i])+2))+pow((i+1), 2);
    }

    string paverstasSkaicius; //vertimui skaiciu i string
    char simbolis; //char'as kuris eis i hasha (gaunamas is 'ascii' reiksmes)

    //hash'o sudarymas
    for(int i = 0; i<64; i++)
    {
        temp = temp * M_PI;
        paverstasSkaicius = to_string(temp);
        ascii = (paverstasSkaicius[1] + paverstasSkaicius[3] + paverstasSkaicius[5] + paverstasSkaicius[7]*i) % 16 + 48; //gaunam ascii reiksmes 48-63
        if (ascii>57) ascii += 39; //kad gauti raides a-f
        simbolis = ascii;
        hash += simbolis;
    }
    return hash;
}

void VartotojoIvedimas()
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
            exit;
        }
        hashas = DarbasSuFailu(failas);
    }
    else 
    {
        cout<<"Iveskite duomenis ranka: ";
        getline(cin >> ws, duomenys);
        hashas = DuomenuHashinimas(duomenys);
    }

    cout<<"hash'as: "<<hashas<<endl;
    cout<<"hash'o ilgis: "<<hashas.length()<<endl;
}