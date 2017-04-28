import os

print(os.path)

def fun(N, num, array):
    if num == 0:
        array[num][num] = 1
    if N<=0:
        return False
    elif N - 2*(num-1) == 0:
        print("0*********8")
        pass
    elif N - 2*(num-1) == 1:
        print("1***********")
        array[int(N/2)][int(N/2)] = N*N
    else:
        for i in range(N-num*2-1):
            if i == 0:
                if num != 0:
                    array[num][num] = array[num][num-1] +1
            array[num][i+num] = array[num][num]+i
            array[i+num][N-num-1] = array[num][num]+i+N-num*2-1
            array[N-num-1][N-num-1-i] = array[num][num]+i+2*(N-num*2-1)
            array[N-num-1-i][num] = array[num][num]+i+3*(N-num*2-1)
        fun(N, num+1, array)
                
N = int(input("please input a number: "))
array = [[0 for col in range(N)] for row in range(N)]
print(array)
num = 0
fun(N,num,array)
for list in array:
    print(list)
for list in array:
    for var in list:
        print(var,end =',')

