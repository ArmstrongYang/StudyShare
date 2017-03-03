import os
import pymongo

# 需要通过cmd打开数据库服务器：mongod --dbpath=E:/onedrive/databases/db --port 2222 --logpath=E:/onedrive/databases/log/mongodb.log 
# 如果需要后台运行，添加--fork,即
# mongod --dbpath=E:/onedrive/databases --port 2222 --fork
client = pymongo.MongoClient('localhost', 2222)


if __name__=='__main__':
    print(__file__)
    
    exit(0)