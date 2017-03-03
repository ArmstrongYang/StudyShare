import re
import os

def GetUrl(num):
    str = os.popen("curl -G https://api.github.com/repositories?since=%d"%(num)).read()
    pattern = '"url"'
    pattern1='repos'
    urls=str.split(',\n')         
    for i in urls:
      if pattern in i and pattern1 in i:
           
#          text1=i.splite(':')
          text=re.compile('"(.*?)"').findall(i)[1]
          print (text)


if __name__=='__main__':
    GetUrl(1000)