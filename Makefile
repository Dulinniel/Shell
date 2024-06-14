all: main

main: 
	g++ -Wextra -Wall -Wno-deprecated -Wno-deprecated-declarations -pedantic src/main.cpp -o build/shell

remove: 
	del -r dist/