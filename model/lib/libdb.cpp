#include "libdb.h"

int db_connect(MYSQL &mysql, string database) {
  mysql_init(&mysql);
  if (!mysql_real_connect(&mysql, "localhost", "root", "", database.c_str(), 0, NULL, 0)) {
    return 1;
  }

  return 0;
}

void stringToJson(string strJson, Json::Value json) {
  Json::Reader reader;
  bool parsingSuccessful = reader.parse( strJson.c_str(), json );
  if ( !parsingSuccessful )
    cout  << "Failed to parse" << reader.getFormattedErrorMessages();
}

string to_db(string value) {
  return "'" + value + "'";
}