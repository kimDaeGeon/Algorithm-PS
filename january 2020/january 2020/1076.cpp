#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

string returnValue(const string* color);

int main() {
	string color1, color2, color3;
	cin >> color1;
	cin >> color2;
	cin >> color3;

	cout << returnValue(&color1) << returnValue(&color2);
	if (stoi(returnValue(&color3)) == 0) cout << "0";
	else
		for (int i = 0; i < stoi(returnValue(&color3)); i++) cout << "0";

	return 0;
}

string returnValue(const string* color) {
	if (*color == "black") return "0";
	if (*color == "brown") return "1";
	if (*color == "red") return "2";
	if (*color == "orange") return "3";
	if (*color == "yellow") return "4";
	if (*color == "green") return "5";
	if (*color == "blue") return "6";
	if (*color == "violet") return "7";
	if (*color == "grey") return "8";
	if (*color == "white") return "9";
}