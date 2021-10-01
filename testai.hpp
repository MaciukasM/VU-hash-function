#ifndef TESTAI_HPP
#define TESTAI_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <bitset>

#include "hashFunkcijos/sha256.hpp"
#include "hashFunkcijos/sha1.hpp"
#include "hashFunkcijos/md5.hpp"

using namespace std;

void TestoPasirinkimas(int pasirinkimas);
void DviejuFailuLyginimas();
void PoVienaEilute(bool kitosHashFunkcijos = false);
void HashuPoruLyginimas();
void PanasausFailoGeneravimas(string failas);
void ProcentinisSkirtingumas(int f = 0);
//void FailoGeneravimas(int ilgis, bool simbolioSkirtumas);

#endif