# Hash-function
This is a repository for the first assignment of VU Blockchain Technologies course (hash function).

## Getting started
First, you need to compile the files:
```shell
g++ -o program main.cpp funkcijos.cpp testai.cpp hashFunkcijos/sha256.cpp hashFunkcijos/sha1.cpp hashFunkcijos/md5.cpp -O2
```
Alternatively, you can use a makefile command:
```shell
mingw32-make all
```
After that, you can simply run your program:
```
.\program.exe 
```

## Requirements for the hash
1. Input's length is not fixed;
2. Output's length is fixed (preferably 256-bit length);
3. The hash function is deterministic;
4. Hashing is reasonably fast/effective;
5. It is practically impossible to find out how the input looks just by using the output;
6. The hash function is resistant to collisions (i.e. it is practically impossible to find two different inputs that result in the same outputs);
7. Any changes made to the input drastically changes the output (also known as the avalanche effect).

## Hash analysis
A few tests were created to find out if this hash function passes these requirements.

### 1. Basic files
**Task**: 

"Susikurkite testinių įvedimo failų pavyzdžių, tokių kad:
* Bent du failai būtų sudaryti tik iš vieno, tačiau skirtingo, simbolio.
* Bent du failai būtų sudaryti iš daug (> 1000) atsitiktinai sugeneruotų simbolių.
* Bent du failai būtų sudaryti iš daug (> 1000) simbolių, bet skirtųsi vienas nuo kito tik vienu (pvz. vidurinėje pozicijoje esančiu) simboliu.
* Tuščio failo."


In total, 7 files were created for this test. 

This test hashes pairs of files twice, so as to check that the function is deterministic (the output of the same input file stays the same), as well as checking that inputs from two different files do not result with the same outputs.

In order to run this test, the user needs to input "2". If we use the files that I provided in the *test* folder, the output should look something like this:
```shell
Pradedamas darbas su 1 simbolio ilgio failais...

1 simbolio failo nr.1 hash'as: 4d791a1ec026a74a9f7c67d5e74821d5bb8966e1ed70f154b9a28c2f900c9b7a
Tas pats failas perhash'intas: 4d791a1ec026a74a9f7c67d5e74821d5bb8966e1ed70f154b9a28c2f900c9b7a
Pirmo failo hash'ai sutampa = true

1 simbolio failo nr.2 hash'as: 3098a865892c2988cd3a5b5de139b76aa8a07fe5e2b26c55c77509f695a27e05
Tas pats failas perhash'intas: 3098a865892c2988cd3a5b5de139b76aa8a07fe5e2b26c55c77509f695a27e05
Antro failo hash'ai sutampa = true

Siu failu hashai nesutampa = true
------------------------------------------------------

Pradedamas darbas su 1000 simboliu ilgio failais...

1000 simboliu failo nr.1 hash'as: 846e921556b093152f3a2388c0488738bde6cc942aefeac44b81a813ac1b2d85
Tas pats failas perhash'intas:    846e921556b093152f3a2388c0488738bde6cc942aefeac44b81a813ac1b2d85
Pirmo failo hash'ai sutampa = true

1000 simboliu failo nr.2 hash'as: 2f2266ceb2f61697091c2f9f5c611bc58fd6a85cb688c6f915d90615bd32c18c
Tas pats failas perhash'intas:    2f2266ceb2f61697091c2f9f5c611bc58fd6a85cb688c6f915d90615bd32c18c
Antro failo hash'ai sutampa = true

Siu failu hashai nesutampa = true
------------------------------------------------------

Pradedamas darbas su 1500 simboliu ilgio failais (su 1 skirtingu simboliu)...

1500 simboliu failo nr.1 hash'as: 50e31a1cdd2f29c18250bbfcec3c1da7304cbc3239e55cde3c3ebdf034f62de5
Tas pats failas perhash'intas:    50e31a1cdd2f29c18250bbfcec3c1da7304cbc3239e55cde3c3ebdf034f62de5
Pirmo failo hash'ai sutampa = true

1500 simboliu failo nr.2 hash'as: 283777bb1b15397707b2d085afb9135ed31afa2e6d5e28a8dc0f63031f4010dd
Tas pats failas perhash'intas:    283777bb1b15397707b2d085afb9135ed31afa2e6d5e28a8dc0f63031f4010dd
Antro failo hash'ai sutampa = true

Siu failu hashai nesutampa = true
------------------------------------------------------
```
### 2. Benchmark (time test)
**Task**: 

"Ištirkite Jūsų sukurtos hash funkcijos efektyvumą: tuo tikslu suhash'uokite kiekvieną eilutę iš konstitucija.txt failo ir išmatuokite kiek laiko
visa tai užtruko. Reiktų matuoti, tik hash'avimo funkcijos veikimo laiką (be input'o nuskaitymo/parengimo). Reiktų pateikti bendrą suminį
visų hash'avimų laiką."


The function hashes every single line of 'konstitucija.txt' file.

In order to run this test, the user needs to input "3". If we use the files that I provided in the *test* folder, the output should look something like this:
```shell
Hash'inamas failas 'konstitucija.txt po eilute...'

'test/konstitucija.txt' failo hash'avimas (mano funkcija) uztruko 0.0012093 s.
```
-O2 optimization was used for this test.

### 3. Collision test
**Task**:

"Susigeneruokite bent 100 000 skirtingo ilgio atsitiktinių simbolių eilučių porų. Rekomenduojame susigeneruoti taip: 25 000 porų, kurių ilgis 10 simbolių, kitas 25 000 porų, kurių ilgis - 100, dar kitas 25 000 poras - 500, ir galiausiai likusias 25 000 poras, kurių ilgis - 1000 simbolių. Tuomet naudodami šias sugeneruotas poras, patikrinkite, ar tikrai visais atvejais gautieji porų hash'ai nesutampa."


The function hashes lines in pairs and checks if the hashes match.

In order to run this test, the user needs to input "4". If we use the files that I provided in the *test* folder, the output should look something like this:
```shell
Pradedamas darbas su failu 'test/poros10.txt'...

Po 1-ojo failo (test/poros10.txt) eiluciu hashavim'o rasta 0 koliziju(-os).

Pradedamas darbas su failu 'test/poros100.txt'...

Po 2-ojo failo (test/poros100.txt) eiluciu hashavim'o rasta 0 koliziju(-os).

Pradedamas darbas su failu 'test/poros500.txt'...

Po 3-ojo failo (test/poros500.txt) eiluciu hashavim'o rasta 0 koliziju(-os).

Pradedamas darbas su failu 'test/poros1000.txt'...

Po 4-ojo failo (test/poros1000.txt) eiluciu hashavim'o rasta 0 koliziju(-os).

Viso rasta 0 koliziju(-os).
```
As you can see, no collisions were found.

### 4. Hash difference in percentage
**Task**:

"Susigeneruokite bent 100 000 atsitiktinių simbolių eilučių porų, apsiribojant iki 1000 simbolių eilučių ilgiu (kaip ir aukščiau) ir kad jos skirtųsi tik vienu simboliu pvz.: (asdfg, bsdfg). Įvertinkite Jūsų gautų hash'ų procentinį "skirtingumą":
* bitų lygmenyje;
* hex'ų lygmenyje.

Išveskite minimalią, maksimalią ir vidurkines "skirtingumo" reikšmes."

Pairs of hashes are compared in terms of hex/bit similarity (more character/bit values that are different = bigger difference). The test uses 4 files in total that can be generated using other files.

In order to run this test, the user needs to input "5". If we use the files that I provided in the *test* folder, the output should look something like this (only the stats of all files combined are shown):
```shell
Ar sugeneruoti failus testavimui (tam bus sukurti nauji modifikuoti failai is koliziju testavimo)? (y/n): n

//skipping the stats of every single file (would take up too much space here)
-----------------------------------------------

Galutiniai rezultatai:

Bit min: 23.2422%
Bit max: 42.9688%

Hex min: 79.6875%
Hex max: 100%

Bit avg: 32.9982%
Hex avg: 93.7406%
```

### 5. Comparing to other functions
**Task**:

"Pabandykite kaip įmanoma objektyviau palyginti Jūsų Hash funkcijos spartą su MD5, SHA-1, SHA-256 ar kita gerai žinoma hash funkcija."

For this comparison, I use the 2-nd test (benchmark/time test).

Each function hashes every single line of 'konstitucija.txt' file.

In order to run this test, the user needs to input "6". If we use the files that I provided in the *test* folder, the output should look something like this:
```shell
Hash'inamas failas 'konstitucija.txt po eilute...'

'test/konstitucija.txt' failo hash'avimas (mano funkcija) uztruko 0.0012905 s.
MD5 hash'avimas uztruko 0.0006443 s.
SHA256 hash'avimas uztruko 0.0011712 s.
SHA1 hash'avimas uztruko 0.0010647 s.
```
-O2 optimization was used for this test.

It seems that, on average, MD5 is the fastest hash function (0.6 ms). SHA1 and SHA256 come next, somewhere around 1.0 and 1.1 ms, respectively. My function is not far behind them, though - the time, on average, is around 1.2-1.3 ms.
