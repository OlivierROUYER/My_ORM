#include "MyORM.hh"

void MyOrm::connect(std::string ip, std::string username, std::string password) {
  sql::Driver* driver{get_driver_instance()};

  sql::Connection* tmp_con{driver->connect(ip, username, password)};
  this->connect_ptr = tmp_con;
}

void MyOrm::AssignTable(std::string Table) {
  this->connect_ptr->setSchema(Table);
}

void MyOrm::getElementFrom(std::string champ) {
  std::unique_ptr<sql::Statement> stmt{this->connect_ptr->createStatement()};

  std::unique_ptr<sql::ResultSet> res{stmt->executeQuery("SELECT * from " + champ)};

  while (res->next()) {
    std::cout << "ID: " << res->getString("id") << "\n";
    std::cout << "Name: " << res->getString("name") << "\n";
  }
  
}
