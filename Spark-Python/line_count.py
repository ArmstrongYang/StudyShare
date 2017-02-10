from pyspark import SparkContext
import os


if __name__ == '__main__':
    print(__file__)
    sc = SparkContext('local')
    file_name = "words.txt"
    line = sc.textFile(file_name)
    print('%s line count: %d' % (file_name,line.count()))
    exit(0)