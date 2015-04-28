maple: maple.o
	g++ maple.o -o maple
maple.o: maple.cpp
	g++ maple.cpp -c