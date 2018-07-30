#include "MyORM.hh"

int main()
{
  MyOrm db;
  db.connect("tcp://127.0.0.1:3306", "root", "");
  db.AssignTable("test");
  db.getElementFrom("champ");
}
