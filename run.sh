#!/bin/bash

g++ -c board.cpp
g++ -c main.cpp
g++ -c game_session.cpp
g++ -c cli.cpp
g++ main.o game_session.o board.o cli.o -o prod
rm cli.o main.o game_session.o board.o 
./prod
rm prod