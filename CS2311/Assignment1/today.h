//	today.h
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>

const int baseYear = 1900;

// return current year
int ThisYear() {
	// use ctime
	time_t t = time(NULL);
	tm* time_ptr = localtime(&t);
	return time_ptr->tm_year + baseYear;
}

// retrun current month
int ThisMonth() {

	// use ctime
	time_t t = time(NULL);
	tm* time_ptr = localtime(&t);
	return time_ptr->tm_mon + 1;
}

// retrun current day
int ThisDay() {
	// use ctime
	time_t t = time(NULL);
	tm* time_ptr = localtime(&t);

	return time_ptr->tm_mday;
}
