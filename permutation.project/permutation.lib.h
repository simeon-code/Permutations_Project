#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdarg>


//Същински и помощни функции
int fill2Set(int**set, int R, int C);//zad2
int printSet(int** set, int R, int C);
bool isFunction(int**, int, int);
bool isInjection(int**, int, int);//zad3
bool isSurjection(int** , int, int);//zad4
bool isPermutation(int**, int, int, bool, bool);//zad5
int numberOfPermutations(int **, int);//zad6
bool anyFixedPoints(int**, int, int);//zad7
int fixedPointsCounter(int**, int, int);//zad8
bool isIdentity(int**, int, int);//zad9
int cycleNotation(int**, char*, int, int);//zad10
int cycleSizeCounter(char*, int*);//zad 11
int cycleSizePrinter(int*);
int fillCycleNotation(char*, int);
int printCycleNotation(char*);
int cycleToSet(char*, int**); //zad12
int composition(char*, int, char*, int);//zad13
bool compositionCheck(int**, int**, int, int);
int reversePermutation(char*);//zad14
int reverseComposition(char*, int, int);//zad15
int compositionOnly(int**, int**, int**, int, int);
int zad16(char*, char*, int);//zad16
bool matrixEquality(int**, int**, int, int);
int nok(int, int);
int findNOK(int*, int);
int matrixcopy(int**, int**, int, int);
int iterationA(int**, int, int);//zad17A
int iterationB(char*, int);//zad17B
int** create2dArray(int, int);
int delete2dArray(int**, int);
bool checkInput(int**, int, int);

//Помощни функции, необходими за изпълнението на задачите през конзолата
//-създават памет
//-извикват други функции, които са същинските задачи от проекта
int zad1and2base();
int zad3to10base(int);
int zad11base();
int zad12base();
int zad13base();
int zad14base();
int zad15base();
int zad16base();
int zad17base(int);