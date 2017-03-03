import tushare as ts
df = ts.realtime_boxoffice()
print(df)
df.rank()
print(df)
df.sort_index()
print(df)
print(type(df))

