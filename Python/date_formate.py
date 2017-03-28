#!/usr/bin/python3

import time;  # 引入time模块

ticks = time.time()
print ("当前时间戳为:", ticks)

localtime = time.localtime(time.time())
print ("本地时间为 :", localtime)

localtime = time.asctime( time.localtime(time.time()) )
print ("本地时间为 :", localtime)

# 格式化成Sat Mar 28 22:24:24 2016形式
time_str_asc = "%a %b %d %H:%M:%S %Y"
print (time.strftime(time_str_asc, time.localtime()))

# 格式化成2016-03-20 11:45:39形式
time_str_commom = "%Y-%m-%d %H:%M:%S"
print (time.strftime(time_str_commom, time.localtime()))

# 格式化成20170325-183546形式
time_str_simple = "%Y%m%d_%H%M%S"
print (time.strftime(time_str_simple, time.localtime()))

# 将格式字符串转换为时间戳
a = "20170325_184120"
print (time.mktime(time.strptime(a,time_str_simple)))

if __name__=='__main__':
    print(__file__)

    exit(0)