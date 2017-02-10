from pyspark import SparkConf, SparkContext
from operator import add

sc = SparkContext('local')

lines = sc.textFile("words-large.txt")
words = lines.flatMap(lambda line: line.split(' '))
wc = words.map(lambda x:(x,1))
counts = wc.reduceByKey(add)
print(counts)
counts.saveAsTextFile("r")