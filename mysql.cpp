#include <iostream>
#include <memory> 

#include "mysql_connection.h"

/* Le package sur Homebrew s'appelle mysql-connector-c++ */

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

int main()
{
  // Recuperation d'une instance (globale!) du driver. Ne doit pas etre delete.
  sql::Driver* driver{get_driver_instance()};
  // Creation d'un smart pointer autour de la connexion.
  std::unique_ptr<sql::Connection> con{driver->connect("tcp://127.0.0.1:3306", "root", "root")};
  // Selection du schema.
  con->setSchema("ful");
  // Creation d'un smart pointer autour d'un statement.
  std::unique_ptr<sql::Statement> stmt{con->createStatement()};
  // Execution de la requete SQL, recuperation des enregistrements
  std::unique_ptr<sql::ResultSet> res{stmt->executeQuery("SELECT 1 as champ")};
  while (res->next()) {
    std::cout << "Champ: " << res->getInt("champ") << "\n";
  }
}
