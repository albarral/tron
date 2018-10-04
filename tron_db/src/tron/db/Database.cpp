
/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/db/Database.h"

namespace tron 
{
Database::Database() 
{
    binitialized = false;

    res = 0;
}

void Database::init(std::string url, std::string user, std::string password, std::string database)
{
    setURL(url);
    setUser(user, password);
    setTargetDatabase(database);
    binitialized = true;    
}

sql::Connection* Database::getConnectionDB()
{
    driver = get_driver_instance();
    con = driver->connect(url, user, password); 
    // leave autocommit set, otherwise consecutive selects won't change
    //con->setAutoCommit(0);    // turn off the autocommit 
    
    return con;
}

void Database::closeConnectionDB()
{
    con->close();
    delete con;
}

bool Database::update(std::string insert, sql::Connection* con)
{ 
    con->setSchema(database);    
    prep_stmt = con->prepareStatement (insert);    
    bool bok = prep_stmt->execute();  
    delete prep_stmt;
    return bok;
}

sql::ResultSet* Database::select(std::string sel, sql::Connection* con)
{  
    if (res != 0)
        delete res;
    
    con->setSchema(database);   
    stmt = con->createStatement();   
    res = stmt->executeQuery(sel);   
    delete stmt;

    return res;
}

}