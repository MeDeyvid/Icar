#include "libdb.h"

int db_connect(MYSQL &mysql, string database) {
    mysql = mysql_init(0);
    if (!mysql_real_connect(mysql, "localhost", "root", database, 0, NULL, 0)) {
        mysql_close(mysql);
        return 1;
    }

    return 0;
}