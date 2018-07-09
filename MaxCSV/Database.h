#pragma once
#include <iostream>
#include <string>
#include "sqlite3.h"
#include  "Combined.h"
using namespace std;
class database {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char* data = "Callback function called";
	int j;

public:
	database();
	void insertData(Combined c);
	void databaseclose();
	void insertJ48Result(int s, int q, string decision);
	void insertSVMResult(int s, int q, double result, string decision);
	void insertNNResult(int s, int q, double success, double fail, string decision);
	void insertNBResult(int s, int q, double success, double fail, string decision);

};