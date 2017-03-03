import os
import pymongo

# 需要通过cmd打开数据库服务器：mongod --dbpath=E:/onedrive/databases --port 2222
client = pymongo.MongoClient('localhost', 2222)


if __name__=='__main__':
    print(__file__)
    
    exit(0)