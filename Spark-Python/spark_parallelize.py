from pyspark import SparkContext, SparkConf

import os

'''
初始化Spark
在一个Spark程序中要做的第一件事就是创建一个SparkContext对象来告诉Spark如何连接一个集群。为了创建SparkContext，你首先需要创建一个SparkConf对象，这个对象会包含你的应用的一些相关信息。
conf = SparkConf().setAppName(appName).setMaster(master)
sc = SparkContext(conf=conf)
appName参数是在集群UI上显示的你的应用的名称。master是一个Spark、Mesos或YARN集群的URL,如果你在本地运行那么这个参数应该是特殊的”local”字符串。在实际使用中，当你在集群中运行你的程序，你一般不会把master参数写死在代码中，而是通过用spark-submit运行程序来获得这个参数。但是，在本地测试以及单元测试时，你仍需要自行传入”local”来运行Spark程序。
'''
appName = 'py-spark'
master = 'local'
conf = SparkConf().setAppName(appName).setMaster(master)
sc = SparkContext(conf=conf)
    
'''
弹性分布式数据集（RDD）
Spark是以RDD概念为中心运行的。RDD是一个容错的、可以被并行操作的元素集合。创建一个RDD有两个方法：在你的驱动程序中并行化一个已经存在的集合；从外部存储系统中引用一个数据集，这个存储系统可以是一个共享文件系统，比如HDFS、HBase或任意提供了Hadoop输入格式的数据来源。
并行化集合
并行化集合是通过在驱动程序中一个现有的迭代器或集合上调用SparkContext的parallelize方法建立的。为了创建一个能够并行操作的分布数据集，集合中的元素都会被拷贝。比如，以下语句创建了一个包含1到5的并行化集合：
'''

data = [1, 2, 3, 4, 5]
distData = sc.parallelize(data)
'''
分布数据集（distData）被建立起来之后，就可以进行并行操作了。比如，我们可以调用disData.reduce(lambda a, b: a+b)来对元素进行叠加。在后文中我们会描述分布数据集上支持的操作。
并行集合的一个重要参数是将数据集划分成分片的数量。对每一个分片，Spark会在集群中运行一个对应的任务。典型情况下，集群中的每一个CPU将对应运行2-4个分片。一般情况下，Spark会根据当前集群的情况自行设定分片数量。但是，你也可以通过将第二个参数传递给parallelize方法(比如sc.parallelize(data, 10))来手动确定分片数量。注意：有些代码中会使用切片（slice，分片的同义词）这个术语来保持向下兼容性。
'''

if __name__ == '__main__':
    print(__file__)
    file_name = "words.txt"
    line = sc.textFile(file_name)
    print('%s line count: %d' % (file_name,line.count()))
    exit(0)