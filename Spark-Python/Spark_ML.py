from pyspark import SparkContext, SparkConf
'''
spark机器学习笔记：（二）用Spark Python进行数据处理和特征提取
http://blog.csdn.net/u013719780/article/details/51768720
'''
appName = 'spark-ml'
master = 'local'
scconf = SparkConf().setAppName(appName).setMaster(master)
sc = SparkContext(conf=scconf)

def plot():
    import matplotlib.pyplot as plt
    from matplotlib.pyplot import hist
    ages = user_fields.map(lambda x: int(x[1])).collect()
    hist(ages, bins=20, color='lightblue',normed=True)
    fig = plt.gcf()
    fig.set_size_inches(12,6)
    plt.show()

if __name__ == '__main__':
    print(__file__)
    file_name = "ml-100k/u.user"
    user_data = sc.textFile(file_name)
    print(user_data.first())
    user_fields = user_data.map(lambda line: line.split('|'))
    num_users = user_fields.map(lambda fields: fields[0]).count()   #统计用户数
    num_genders = user_fields.map(lambda fields : fields[2]).distinct().count()   #统计性别个数
    num_occupations = user_fields.map(lambda fields: fields[3]).distinct().count()   #统计职业个数
    num_zipcodes = user_fields.map(lambda fields: fields[4]).distinct().count()   #统计邮编个数
    print ("Users: %d, genders: %d, occupations: %d, ZIP codes: %d"%(num_users,num_genders,num_occupations,num_zipcodes))
    plot()
    exit(0)