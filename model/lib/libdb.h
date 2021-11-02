#include <iostream>
#include <mysql/mysql.h>
#include <string>

using namespace std;

/* Conecta ao banco de dados */
int db_connect(MYSQL &mysql, string database);