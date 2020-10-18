#include"leveldb/db.h"
#include<iostream>
#include<cassert>
using namespace std;
using namespace leveldb;
int main(){
    leveldb::DB  *db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options,"testdb",&db);
    assert(status.ok());
    status = db->Put(WriteOptions(),"test","hello levelDb");
    assert(status.ok());
    string res;
    status = db->Get(ReadOptions(),"test",&res);
    assert(status.ok());
    cout << res << endl;
    delete db;
    return 0;
}