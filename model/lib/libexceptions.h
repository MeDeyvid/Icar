#include <iostream>
#include <mysql/mysql.h>
#include <jsoncpp/json/json.h>
#include <string>

using namespace std;

class Throw_exceptions {
private:
  Json::Value error, message;
public:
  void throw_exception(string message);
  void throw_db_exception(MYSQL &mysql, string message);
};