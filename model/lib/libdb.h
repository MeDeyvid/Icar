#include <iostream>
#include <mysql/mysql.h>
#include <jsoncpp/json/json.h>
#include <string>

using namespace std;

/* Conecta ao banco de dados */
int db_connect(MYSQL &mysql, string database);
void stringToJson(string strJson, Json::Value json);
string to_db(string value);