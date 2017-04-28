#! usr/bin/python
# coding :utf-8
import copy
def shuffle(dic):
    lst = []
    if dic['k'] == 0:
        return dic['l']
    else:
        lst = copy.deepcopy(dic['l'])
        for i in range(dic['n']):
            dic['l'][2*i] = lst[i]
            dic['l'][2*i+1] = lst[i+dic['n']]
        dic['k'] = dic['k'] - 1
        return shuffle(dic)

T = int(input())
dic = {}
for i in range(T):
    dic[i] = {}
    dic[i]['n'], dic[i]['k'] = input().split()
    dic[i]['n'] = int(dic[i]['n'])
    dic[i]['k'] = int(dic[i]['k'])
    dic[i]['l'] = input().split()
    print('n ',dic[i]['n'])
    print('k ',dic[i]['k'])
    print('l ',dic[i]['l'])
    #for j in len(dic[i]['l']):
    #    dic[i]['l'][j] = int(dic[i]['l'][j])
    

for i in range(T):
    print(shuffle(dic[i]))
