all: run

run: main.o dynamicArray.o linkedList.o multiSetHelp.o dynamicSet.o dynamicMultiSet.o dynamicMap.o dynamicMultiMap.o linkedSet.o linkedMultiSet.o linkedMap.o linkedMultiMap.o hashSet.o hashMultiSet.o hashMap.o hashMultiMap.o
	g++ main.o dynamicArray.o linkedList.o multiSetHelp.o dynamicSet.o dynamicMultiSet.o dynamicMap.o dynamicMultiMap.o linkedSet.o linkedMultiSet.o linkedMap.o linkedMultiMap.o hashSet.o hashMultiSet.o hashMap.o hashMultiMap.o -o run

main.o:main.cpp
	g++ -c main.cpp
	
dynamicArray.o: baseStructures/dynamicArray/dynamicArray.cpp
	g++ -c baseStructures/dynamicArray/dynamicArray.cpp
	
linkedList.o: baseStructures/linkedList/linkedList.cpp
	g++ -c baseStructures/linkedList/linkedList.cpp

multiSetHelp.o: baseStructures/multiSetHelp/multiSetHelp.cpp
	g++ -c baseStructures/multiSetHelp/multiSetHelp.cpp

dynamicSet.o: Set/dynamicSet/dynamicSet.cpp
	g++ -c Set/dynamicSet/dynamicSet.cpp
	
dynamicMultiSet.o: MultiSet/dynamicMultiSet/dynamicMultiSet.cpp
	g++ -c MultiSet/dynamicMultiSet/dynamicMultiSet.cpp
	
dynamicMap.o: Map/dynamicMap/dynamicMap.cpp
	g++ -c Map/dynamicMap/dynamicMap.cpp
	
dynamicMultiMap.o: MultiMap/dynamicMultiMap/dynamicMultiMap.cpp
	g++ -c MultiMap/dynamicMultiMap/dynamicMultiMap.cpp
	
linkedSet.o: Set/linkedSet/linkedSet.cpp
	g++ -c Set/linkedSet/linkedSet.cpp
	
linkedMultiSet.o: MultiSet/linkedMultiSet/linkedMultiSet.cpp
	g++ -c MultiSet/linkedMultiSet/linkedMultiSet.cpp
	
linkedMap.o: Map/linkedMap/linkedMap.cpp
	g++ -c Map/linkedMap/linkedMap.cpp
	
linkedMultiMap.o: MultiMap/linkedMultiMap/linkedMultiMap.cpp
	g++ -c MultiMap/linkedMultiMap/linkedMultiMap.cpp
	
hashSet.o: Set/hashSet/hashSet.cpp
	g++ -c Set/hashSet/hashSet.cpp
	
hashMultiSet.o: MultiSet/hashMultiSet/hashMultiSet.cpp
	g++ -c MultiSet/hashMultiSet/hashMultiSet.cpp
	
hashMap.o: Map/hashMap/hashMap.cpp
	g++ -c Map/hashMap/hashMap.cpp
	
hashMultiMap.o: MultiMap/hashMultiMap/hashMultiMap.cpp
	g++ -c MultiMap/hashMultiMap/hashMultiMap.cpp