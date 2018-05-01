import os
import sys

import mxnet as mx

print(mx.__version__)

a = mx.nd.array([[1,2,3], [4,5,6]])

print(a.size)
print(a.shape)
print(a.dtype)

print(a)
print(a.T)
print(mx.nd.dot(a, a.T))
c = mx.nd.uniform(low=0, high=1, shape=(1000,1000), ctx=mx.cpu(0))
# d = mx.nd.normal(loc=1, scale=2, shape=(1000,1000), ctx=mx.gpu(0))

print('end')