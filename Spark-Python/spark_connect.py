from pyspark import SparkContext, SparkConf

import os


if __name__ == '__main__':
    print(__file__)
    #appName参数是在集群UI上显示的你的应用的名称。master是一个Spark、Mesos或YARN集群的URL,如果你在本地运行那么这个参数应该是特殊的”local”字符串。
    appName = 'py-spark'
    master = 'local'
    conf = SparkConf().setAppName(appName).setMaster(master)
    sc = SparkContext(conf=conf)
    file_name = "words.txt"
    line = sc.textFile(file_name)
    print('%s line count: %d' % (file_name,line.count()))
    exit(0)