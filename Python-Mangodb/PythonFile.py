import os
import pymongo

# default 27017
# 需要通过cmd打开数据库服务器：mongod --dbpath=E:/onedrive/databases
client = pymongo.MongoClient('localhost', 2222)
# or
#client = pymongo.MongoClient('mongodb://localhost:27017/')  

# db lists
db_list = client.database_names()
for db_name in db_list:
    print(db_name)

db = client.test_database
# or
# db = client["test_database"]

# collection lists
co_list = db.collection_names()
for co_name in co_list:
    print(co_name)


# insure unique data but failed
# db.test.ensureIndex({'time':1},{'unique':True})

# insert data
import time
data = [{'time': time.time(),
        'tags':['test','first','learning','mongodb'],
        'content':"This is the first time learning the mongodb and pymongo module"
        },
        {'time': time.time()+2,
        'tags':['test','second','search-test'],
        'content':"This is the data for searching tags"
        }
       ]
data_add = [{'time': time.time()+2,
             'tags':['test','third','search-test'],
             'content':"This is the data for searching time"
            }
           ]
result = db.blog.insert_many(data_add)
account = db.test
# or
# account = db.get_collection('test')
print(account.find_one())
print(account.find_one().keys())

# search all
for tag in account.find():
    print(tag)

# search keyword in tags
for tag in account.find({'tags':'test'}):
    print(tag)

# search keyword in tags
for tag in account.find({'tags':'first'}):
    print(tag)

# search keyword in tags
for tag in account.find({'tags':'second'}):
    print(tag)

'''
mongodb条件操作符，"$lt", "$lte", "$gt", "$gte", "$ne"就是全部的比较操作符，对应于"<", "<=", ">", ">=","!="。
原子操作符："$and“, "$or“, "$nor“。
'''
# search by time
for tag in account.find({'time':{'$lt': time.time()}}):
    print(tag)

# search by time
for tag in account.find({'time':{'$lt': 1488543198.4748197}}):
    print(tag)

# search by time
for tag in account.find({'time':{'$gt': 1488543198,'$lt':1488543200}}):
    print(tag)

time_fmt = "%Y-%m-%d %H:%M:%S"
time_str = '2017-03-03 20:40:01'
time_sec = time.mktime( time.strptime(time_str, time_fmt))

# search by time
for tag in account.find({'time':{'$lt':time_sec}}):
    print(tag)

# search by time
for tag in account.find({'time':{'$gt':time_sec}}):
    print(tag)

# search by multi info
for tag in account.find({'time':{'$gt':time_sec},'tags':'test'}):
    print(tag)
    print(tag['content'])

# sort 默认为升序
for tag in account.find().sort('time'):
    print(tag)

# sort 
for tag in account.find().sort([('time', pymongo.ASCENDING),
                                ("tags", pymongo.DESCENDING)]):
    print(tag)
# update
# 注：如果数据中没有键-值"tags": "first"， 会新增"object": "For better database management"
account.update({"tags": "first"}, {"$set": {"object": "For better database management"}})

# remove
for tag in account.find({"tags": "third"}):
    print(tag)
state = account.remove({"tags": "third"})
print(state)
state = account.remove({"_id": "58b95dde3784783bb01fbbdf"})
print(state)
state = account.remove({"time": 1488543198.4748197})
print(state)

# ensure_index
# 本次目标式为了去除相同时间格式的数据
# 不允许重复，但之前已经重复的不会被删除
# @hiyangdong 2017-03-03 21:44:14：测试成功，如果insert，会出现BulkWriteError错误
print('----------------')
# account.ensure_index('time', cache_for=1, unique=True)
#data_copy = [{'time': 1488543200.4748197,
#             'tags':['test','second','search-test'],
#             'content':"This is the data for searching tags"
#            }
#           ]
#result = db.test.insert_many(data_copy)
#print(result)
# 还会删除之前重复的资料
# @hiyangdong 2017-03-03 21:38:40：并没有删除重复数据
# db.users.ensure_index('time', cache_for=0, unique=True, dropDups=True)

if __name__=='__main__':
    print(__file__)
    
    exit(0)