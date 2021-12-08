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
#include "lib/corporate.h"

using namespace std;

int main(int argc, char *argv[]) {

  try {
    Throw_exceptions *exception = new Throw_exceptions();

    if (argc < 2)
      exception->throw_exception("Parametro nao informado.");

     string operation = argv[1];

    if (operation == "-authentication") {
      if (argc != 3)
        exception->throw_exception("Quantidade de parametros incorretos.");

      string parameters = string(argv[2]);

      MYSQL mysql;
      MYSQL_RES *res;
      MYSQL_ROW row;

      if (db_connect(mysql, "users") != 0)
        exception->throw_db_exception(mysql,"Falha ao conectar ao banco de dados.");

      Json::Value json;
      stringToJson(parameters,json);

      string sql = "SELECT isModerator FROM users WHERE login = '" + json["login"].asString() + "'";
      if (mysql_query(&mysql, sql.c_str()))
        exception->throw_db_exception(mysql, "Falha ao buscar dados sobre o usuário");

      string isModerator;
      res = mysql_store_result(&mysql);

      if ((row = mysql_fetch_row(res))) {
        isModerator = row[0] ? string(row[0]) : "";
      }

      mysql_free_result(res);

      mysql_close(&mysql);
    } 
    else if (operation == "cad_corporate") {
      if (argc != 3)
        exception->throw_exception("Quantidade de parametros incorretos.");

      string parameters = string(argv[2]);

      MYSQL mysql;
      MYSQL_RES *res;
      MYSQL_ROW row;

      if (db_connect(mysql, "users") != 0)
        exception->throw_db_exception(mysql,"Falha ao conectar ao banco de dados.");
      
      Json::Value json;
      stringToJson(parameters, json);

      Corporate *corporate = new Corporate();
      corporate->setParamsCorporate(json);
      
      string sql = "INSERT INTO icar.users ("
      " name"
      ", corporate_name"
      ", phone"
      ", cell_phone"
      ", address"
      ", address_number"
      ", cnpj"
      ", city_id"
      ", state_id"
      ", country_id"
      ") VALUE ("
      + to_db(corporate->getName())
      + ", " + to_db(corporate->getCorporateName())
      + ", " + to_db(corporate->getPhone())
      + ", " + to_db(corporate->getCellPhone())
      + ", " + to_db(corporate->getAddress())
      + ", " + to_db(corporate->getAddressNumber())
      + ", " + to_db(corporate->getCnpj())
      + ", " + to_db(corporate->getCityId())
      + ", " + to_db(corporate->getStateId())
      + ", " + to_db(corporate->getCountryId())
      + ")";

      if (mysql_query(&mysql, sql.c_str()))
        exception->throw_db_exception(mysql, "Falha ao cadastrar");

      mysql_free_result(res);

      mysql_close(&mysql);

    }
    else {
      cout << "Opção desconhecida" << endl;
      exit(0);
    }
  }
  catch(const exception &e) {
    std::cerr << e.what() << '\n';
  }
}