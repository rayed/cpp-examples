
#include <iostream>

#include <pqxx/pqxx>


void postgres_test()
{
    pqxx::connection c("dbname=rayed user=rayed");
    pqxx::work txn(c);

    pqxx::result r = txn.exec("SELECT * FROM users");
    for (auto row: r) {
        std::cout << row["id"].as<int>() << " " << row["email"] << std::endl;
    }
}


int main()
{
    postgres_test();
    return 0;
}
