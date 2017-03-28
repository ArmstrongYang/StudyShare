import os
import pymongo

# 需要通过cmd打开数据库服务器：mongod --dbpath=E:/onedrive/databases/db --port 2222 --logpath=E:/onedrive/databases/log/mongodb.log 
# 如果需要后台运行，添加--fork,即
# mongod --dbpath=E:/onedrive/databases --port 2222 --fork

def get_client(host = 'localhost', port='2222'):
    client = pymongo.MongoClient('localhost', 2222)
    return client

def get_dblist(client):
    db_list = client.database_names()
    return db_list

def get_db(name='infinity'):
    client = get_client()
    return client[name]

def get_colist(db):
    co_list = db.collection_names()
    return co_list

def get_collection(name='family', db_name='infinity'):
    db = get_db(db_name)
    return db[name]

def db_by_name(name):
    client = get_client()
    return client[name]

def table_by_name(name):
    client = get_client()
    return client[name]['startup_log']

if __name__=='__main__':
    print(__file__)
    client = get_client()
    db_blog = client.blog
    print(client)
    print(get_dblist(client))
    print(get_colist(client['local']))
    print(db_by_name('local'))
    print(table_by_name('local'))
    print(get_db())
    print(get_collection())
    exit(0)