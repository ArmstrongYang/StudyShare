import os
import requests 
from lxml import etree
session = requests.Session()

for id in range(0,251,25):
  URL = 'http://movie.douban.com/top250/?start=' + str(id)
  req = session.get(URL)
  req.encoding = 'utf8'			  # 设置网页编码格式
  root=etree.HTML(req.content)					   #将request.content 转化为 Element
  items = root.xpath('//ol/li/div[@class="item"]')
  for item in items:	
    #注意可能只有中文名，没有英文名；可能没有quote简评
    rank,name,alias,rating_num,quote,url = "","","","","",""
    try:
      url = item.xpath('./div[@class="pic"]/a/@href')[0]
      rank = item.xpath('./div[@class="pic"]/em/text()')[0]
      title = item.xpath('./div[@class="info"]//a/span[@class="title"]/text()')
      name = title[0].encode('gb2312','ignore').decode('gb2312')
      alias = title[1].encode('gb2312','ignore').decode('gb2312') if len(title)==2 else ""
      rating_num = item.xpath('.//div[@class="bd"]//span[@class="rating_num"]/text()')[0]
      quote_tag = item.xpath('.//div[@class="bd"]//span[@class="inq"]')
      if len(quote_tag)  is not 0:
        quote = quote_tag[0].text.encode('gb2312','ignore').decode('gb2312').replace('\xa0','')
      print(rank,rating_num,quote)
      print(name.encode('gb2312','ignore').decode('gb2312') ,alias.encode('gb2312','ignore').decode('gb2312') .replace('/',','))
    except:
      print('faild!')
      pass

if __name__=='__main__':
    print(__file__)
    dir = os.getcwd()
    print(dir)
    filelist = os.listdir(dir)
    print(filelist)
    exit(0)