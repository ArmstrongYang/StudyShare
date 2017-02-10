from pyspark import SparkContext
import os
os.environ["SPARK_HOME"] = "D:/Apps/Spark"
sc = SparkContext('local')
doc = sc.parallelize([['a', 'b', 'c'], ['b', 'd', 'd']])
words = doc.flatMap(lambda d: d).distinct().collect()
word_dict = {w: i for w, i in zip(words, range(len(words)))}
word_dict_b = sc.broadcast(word_dict)


def word_count_per_doc(d):
    dict_tmp = {}
    wd = word_dict_b.value
    for w in d:
        dict_tmp[wd[w]] = dict_tmp.get(wd[w], 0) + 1
    return dict_tmp

print(doc.map(word_count_per_doc).collect())
print("successful!")