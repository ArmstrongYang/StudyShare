import os
# -*- coding: utf-8 -*-
 
import re,json
import urllib.request
#movie:
     #search engine:http://movie.douban.com/subject_search?search_text=+film_name+&cat=1002
     #info:https://api.douban.com/v2/movie/:id
 
print("please input the name of film u want to search:")
film_name = 'X-Men'
movie_search_engine = "http://movie.douban.com/subject_search?search_text="+film_name+"&cat=1002"
movie_search = movie_search_engine
with urllib.request.urlopen(movie_search) as response:
    html = response.read()

match = re.findall('<a class="nbg" href="(.+?)" >',html)
match = match[0]
movie_id = re.split(r'\D+',match)
movie_id = movie_id[1]
movie_url = "https://api.douban.com/v2/movie/"+movie_id
movie_url = urllib.urlopen(movie_url).read()
jsondata = json.loads(movie_url)
name = jsondata["alt_title"]
rate = jsondata["rating"]["average"]
director = jsondata["attrs"]["director"][0]
cast = jsondata["attrs"]["cast"]
pubdate = jsondata["attrs"]["pubdate"][0]
movie_duration = jsondata["attrs"]["movie_duration"][0]
country = jsondata["attrs"]["country"][0]
movie_type = jsondata["attrs"]["movie_type"]
print("name:" + name)
print("rate:" + rate)
print("director:" + director)
print("casts:" + cast[0] +"\\"+ cast[1] +"\\"+ cast[2])
print("country:" + country)
print("duration:" + movie_duration)
print("pubdate:" + pubdate)
print("country:" + movie_type[0] +"\\"+ movie_type[1] +"\\"+ movie_type[2])
print("--------------------------------------------------------By Douban")

if __name__=='__main__':
    print(__file__)
    dir = os.getcwd()
    print(dir)
    filelist = os.listdir(dir)
    print(filelist)
    exit(0)