# Hash-function
This is a repository for the first assignment of VU Blockchain Technologies course (hash function).

Contents:
* [Getting started](#getting-started)
* [User's input](#Users-input)
* [How it (the function) works](#How-it-the-function-works)
* [Requirements for the hash](#requirements-for-the-hash)
* [Hash analysis](#hash-analysis)
  * [Test with basic files](#1-basic-files)
  * [Benchmark (time test)](#2-benchmark-time-test)
  * [Collision test](#3-collision-test)
  * [Hash difference in percentage](#4-hash-difference-in-percentage)
  * [Comparing to other functions](#5-comparing-to-other-functions)
* [Conclusion](#conclusion)

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

## User's input

After running the program, the user will be greeted with the following options:
```shell
PS C:\VU-hash-function> .\program.exe

Iveskite savo pasirinkima ivede skaiciu:                                                    //enter your choice

1 - Duomenu ivedimas ir hash'inimas                                                         //Basic input from files or by hand (user's choice)
2 - Paprastu failu hash'inimas ir lyginimas                                                 //Testing the function with basic files
3 - konstitucija.txt hash'avimo matavimas                                                   //Benchmark/time test
4 - Sugeneruotu poru hash'inimas ir lyginimas (atsparumas kolizijoms)                       //Collision test
5 - Hash'u procentinio skirtingumo tikrinimas                                               //Hash difference in percentage
6 - Spartos lyginimas su SHA-256, SHA-1 ir MD-5 funkcijomis (tam naudojama 3-ioji uzduotis) //Comparing to other functions
```
If the user wishes to hash their input, the user needs to input "1":
```shell
1
Ar duomenis imti is failo? (y/n):                                                                         //Should the input be taken from a file? y/n
```
If the answer is 'y', then the user will be able to type in the directory of the file, after which, the function will output the hash and its length.

Alternatively, if the answer is 'n', then the user will be able to type in their input by hand, after which, the function will output the hash and its length.


Other options (i.e. the tests, options 2-6) are showcased later (see [Test #1](#1-basic-files), [Test #2](#2-benchmark-time-test), [Test #3](#3-collision-test), [Test #4](#4-hash-difference-in-percentage), [Test #5](#5-comparing-to-other-functions)).

## How it (the function) works

1. The function takes the first character of the input and proceeds to convert it to an ascii value, which it then multiplies with our starting number/seed. After some additions, the bits of that number are shifted to the left and the whole number is raised to the power of three.

This operation #1 is then repeated for every single character of the input.

2. The number that we got is now multiplied again. From there, the function takes some of the digits from our number and add/multiply them together and assign this new number to a new variable. This variable is then divided in a way that we can get an ascii value which is converted to 0-9 + a-f and added to our hash.

The function repeats this operation #2 63 more times until we get 64 characters in our hash.

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
If the user wishes to see the output of an empty input, the user needs to input "1", then "y" (to input data from a file) and lastly type in the directory of an empty .txt file (e.g. test/empty.txt):
```shell
1
Ar duomenis imti is failo? (y/n): y
Iveskite failo pavadinima (pvz. failas.txt): test/empty.txt
hash'as: 3cd5bf8a71c0517b5e79fd35813a1e00285fcc3b77d8fcc1b50ce3764ec97afb
hash'o ilgis: 64
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
The hex difference on average is very satisfactory - 93.7% is a good score.

The bit difference, meanwhile, isn't as impressive - 33% somewhat passes the requirement, although, ideally it should be somewhere closer to 50%.

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

## Conclusion
The hash is, more or less, capable of passing the aforementioned requirements.
1. It accepts a string of any length as an input and the output is always 256-bit long. Also, you can't find out the input just by looking at the output.
2. It is deterministic (i.e. the same input always generates the same output).
3. It is reasonably fast and compares well with other popular hash functions (see [test #5](#5-Comparing-to-other-functions)). The time complexity of this function is linear (O(n)).
4. The hash seems to be collision resistant as well (see [test #3](#3-Collision-test)).
5. Lastly, the function somewhat satisfies the 'avalanche effect' requirement (see [test #4](#4-Hash-difference-in-percentage)).

All in all, it is an effective function that is both collision resistant and showcases some properties of the 'avalanche effect'. In terms of speed, it compares pretty well with other functions, although, it goes without saying that these hash functions are way more reliable in terms of security.

Probably the main way of upgrading this function would be to improve the average bit difference between two hashes.
