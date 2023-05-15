all: fincat

fincat:
	g++ -std=c++11 fincat.cpp -o fincat

test: fincat
	echo "company1 50000 600000 5000000 2000000\ncompany2 100000 1800000 4000000 10000000\n" >> raw.dat
	./fincat raw.dat analyzed.txt
	cat analyzed.txt

clean:
	rm fincat raw.dat analyzed.txt
