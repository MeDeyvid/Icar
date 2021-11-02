#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include "lib/libdb.h"

using namespace std;

int main(int argc, char *argv[]) {

    string operation = argv[1];

    if (operation == "-authentication") {
        if (argc != 3) {
            cout << "Quantidade parametros inválidos";
            exit(1);
        }
        MYSQL* mysql;
        // if (!db_connect(mysql, "users")) {
        //     cout << "Falha ao conectar no banco de dados";
        //     exit(1);
        // }

        // mysql_close(mysql);
    }
}