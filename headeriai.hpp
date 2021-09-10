#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string VartotojoIvedimas();
bool FailoTikrinimas(string failas);
string Hashinimas(bool ivedimas, string duomenys); //jei duomenys imami is failo, tai kintamasis duomenys laikys failo pavadinima
