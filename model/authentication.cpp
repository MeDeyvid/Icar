/* 
    compilar
    g++ authentication.cpp lib/libdb.cpp lib/libexceptions.cpp -o authentication  -lmysqlclient -ljsoncpp
*/
#include <iostream>
#include <mysql/mysql.h>
#include <jsoncpp/json/json.h>
#include <string>
#include "lib/libdb.h"
#include "lib/libexceptions.h"

using namespace std;

int main(int argc, char *argv[]) {

  try {
    Throw_exceptions throw_exceptions;

    if (argc < 2)
      throw_exceptions.throw_exception("Parametro nao informado.");

     string operation = argv[1];

    if (operation == "-authentication") {
      if (argc != 3)
        throw_exceptions.throw_exception("Quantida de parametros incorreto.");

      MYSQL mysql;
      if (db_connect(mysql, "users") != 0)
        throw_exceptions.throw_db_exception(mysql,"Falha ao conectar ao banco de dados.");

      mysql_close(&mysql);
    } else {
      cout << "Opção desconhecida" << endl;
      exit(0);
    }
  }
  catch(const exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}