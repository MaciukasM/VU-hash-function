all: program

program: main.o funkcijos.o testai.o hashFunkcijos/sha256.o hashFunkcijos/sha1.o hashFunkcijos/md5.o
		g++ -o program main.o funkcijos.o testai.o sha256.o sha1.o md5.o -O2

main.o: main.cpp
		g++ -c main.cpp -O2

funkcijos.o: funkcijos.cpp
		g++ -c funkcijos.cpp -O2

testai.o: testai.cpp
		g++ -c testai.cpp -O2

hashFunkcijos/sha256.o: hashFunkcijos/sha256.cpp
		g++ -c hashFunkcijos/sha256.cpp -O2

hashFunkcijos/sha1.o: hashFunkcijos/sha1.cpp
		g++ -c hashFunkcijos/sha1.cpp -O2

hashFunkcijos/md5.o: hashFunkcijos/md5.cpp
		g++ -c hashFunkcijos/md5.cpp -O2
