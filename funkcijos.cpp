#include "headeriai.hpp"

bool FailoTikrinimas(string failas)
{
    ifstream in(failas);
    return in.good();
}

string Hashinimas(bool ivedimas, string duomenys)
{
    if (ivedimas) return "a";
    else return "b";
}