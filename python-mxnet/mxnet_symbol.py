import numpy as np
import mxnet as mx
a = mx.symbol.Variable('A')
b = mx.symbol.Variable('B')
c = mx.symbol.Variable('C')
d = mx.symbol.Variable('D')
e = (a*b)+(c*d)
print(e)

print(e.list_arguments())
print(e.list_inputs())
print(e.list_outputs())
print(e.get_internals())

"""
将Symbol定义的计算步骤应用给NDArray中存储的数据，需要一种名为“绑定（Binding）”的操作，例如将一个NDArray分配给Graph的每个输入变量。
"""
a_data = mx.nd.array([1], dtype=np.int32)
b_data = mx.nd.array([2], dtype=np.int32)
c_data = mx.nd.array([3], dtype=np.int32)
d_data = mx.nd.array([4], dtype=np.int32)
executor = e.bind(
    mx.cpu(), {'A': a_data, 'B': b_data, 'C': c_data, 'D': d_data})

print(executor)
e_data = executor.forward()
print(e_data[0].asnumpy())
print(e_data)


a_data = mx.nd.uniform(low=0, high=1, shape=(1000, 1000))
b_data = mx.nd.uniform(low=0, high=1, shape=(1000, 1000))
c_data = mx.nd.uniform(low=0, high=1, shape=(1000, 1000))
d_data = mx.nd.uniform(low=0, high=1, shape=(1000, 1000))

e_data = executor.forward()
print(e_data)


executor = e.bind(
    mx.cpu(0,1), {'A': a_data, 'B': b_data, 'C': c_data, 'D': d_data})
e_data = executor.forward()
print(e_data)
