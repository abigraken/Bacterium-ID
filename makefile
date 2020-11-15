CXX = g++
CXXFLAGS = -Wall

hackumbc: bacteria.o identify.o hackumbc.cpp
	$(CXX) $(CXXFLAGS) bacteria.o identify.o hackumbc.cpp -o hackumbc

identify.o: bacteria.o identify.h identify.cpp
	$(CXX) $(CSSFLAGS) -c identify.cpp

bacteria.o: bacteria.h bacteria.cpp
	$(CXX) $(CXXFLAGS) -c bacteria.cpp

run:
	./hackumbc microbiology.txt

clean:
	rm *.o
	rm *~
