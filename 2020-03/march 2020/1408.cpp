#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

class Time {
public:
	int hour, min, sec;
	Time(int h, int m, int s) {
		this->hour = h;
		this->min = m;
		this->sec = s;
	}
};

int timeToSecond(Time t);
string timeToString(int sec);

int main() {
	int hour, min, sec;

	scanf("%d:%d:%d", &hour, &min, &sec);
	Time current(hour, min, sec);

	scanf("%d:%d:%d", &hour, &min, &sec);
	Time start(hour, min, sec);

	cout << timeToString(abs(timeToSecond(start) - timeToSecond(current))) << '\n';
}

int timeToSecond(Time t) {
	return t.hour * 3600 + t.min * 60 + t.sec;
}
string timeToString(int sec) {
	int h = sec / 3600;
	int m = (sec - h * 3600) / 60;
	int s = sec - h * 3600 - m * 60;

	string time = to_string(h) + ":" + to_string(m) + ":" + to_string(s);
	return time;
}