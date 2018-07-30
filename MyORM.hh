#ifndef MYORM_HH
#define MYORM_HH

#include <iostream>
#include <string>
#include <memory>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class MyOrm {
  private :
    sql::Connection* connect_ptr;
  public :
    void connect(std::string, std::string, std::string);
    void getElementFrom(std::string);
    void AssignTable(std::string);
};

#endif
