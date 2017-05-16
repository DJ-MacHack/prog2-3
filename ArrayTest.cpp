/**
* @file: ArrayTest.cpp
* @author:DJ MacHack
* @date: 16.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
* Partner: Julian Bruna
*/

#include <fstream>
#include<iostream>
#include <sstream>
#include "ArrayTools.h"
using namespace std;


/**
 * Splits a string
 * @param input
 * @param search
 * @return
 */
static vector<string> split(string input, char search) {
	vector<string> ausgabe;
	stringstream ss(input); //string 2 stream
	string token;
	string s(1, search);

	while(getline(ss, token, search)) {
		ausgabe.push_back(token);
		ausgabe.push_back(s);
	}
	ausgabe.pop_back(); //last string is too much

	return ausgabe;
}

/**
 * prints credits.txt
 */
static void credits() {
	ifstream inFile ("credits.txt");
	string input = "";
	//inFile.open("credits.txt");
	if (inFile.is_open()) {
		while (getline (inFile,input)) {
			if(input.find("Q") != string::npos){   //find
				vector<string> vector = split(input, 'Q');    //split
				int teile = vector.size();
				for(int i = 0; i < teile; i++){
					if(vector.at(i)=="Q") {     //only Q red
//                        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(handle, FOREGROUND_RED);
						cout << "\x1B[40m\x1B[5m\x1B[31m" + vector.at(i);
					} else {
//                        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
//                                                        FOREGROUND_BLUE);
						cout << "\x1B[0m\x1B[40m\x1B[37m"+vector.at(i);
					}
				}
				cout << endl;
			} else {
//                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
//                                                FOREGROUND_BLUE);
				std::cout << "\x1B[40m\x1B[37m"+input << std::endl;
			}
		}       //close file
		cout << "\x1B[0m" <<endl;
		inFile.close();
	} else {
		cout << "File could not be opened!";
	}

}

/**
 * starts tests
 */
void starteTests() {
	const size_t SIZE = 10;
	cout << "int-Array testen" << endl;
	int itab[SIZE];
	testeArray(itab, SIZE);

	cout << "\ndouble-Array testen" << endl;
	double dtab[SIZE];
	testeArray(dtab, SIZE);

	credits();
}

/**
 * main
 * @return
 */
int main() {
	starteTests();
}
