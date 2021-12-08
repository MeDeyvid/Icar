#include "libexceptions.h"

void Throw_exceptions::throw_exception(string message) {
  this->message["message"] = message;
  this->error["error"].append(this->message);
  cout << error << endl;
  exit(1);
};

void Throw_exceptions::throw_db_exception(MYSQL &mysql, string message) {
  mysql_close(&mysql);
  throw_exception(message);
}