def fun(n,cnt, array):
  if cnt==0:
    array[0][0] = 1
  if (n-2*cnt)==1:
    array[int(n/2)][int(n/2)]=n*n
    return array
  if (n-2*cnt)==0:
    return array
  else:
    for m in range(n-cnt*2-1):
      if m==0 and cnt!=0:
          array[cnt][cnt] = array[cnt][cnt-1]+1
      array[cnt][cnt+m] = array[cnt][cnt] + m
      array[cnt+m][n-cnt-1] = array[cnt][cnt] +m+ n-cnt*2-1
      array[n-cnt-1][n-cnt-1-m] = array[cnt][cnt] + m+ (n-cnt*2-1)*2
      array[n-cnt-1-m][cnt] = array[cnt][cnt] + m+ (n-cnt*2-1)*3
    return fun(n,cnt+1, array)

n = int(input(""))
array =[ [0 for i in range(n)] for j in range(n)]
a = fun(n,0,array)
print(a)
for i in a:
    print(i)
    
