#!/bin/bash

g++ -c src/board.cpp
g++ -c src/main.cpp
g++ -c src/game_session.cpp
g++ -c src/cli.cpp
g++ main.o game_session.o board.o cli.o -o prod
rm cli.o main.o game_session.o board.o 
./prod
rm prod