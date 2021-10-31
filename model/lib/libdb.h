#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include <string>

using namespace std;

/* Conecta ao banco de dados */
int db_connect(MYSQL &mysql, string database);