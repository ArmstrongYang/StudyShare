import cv2
import numpy as np
import mxnet as mx


sym, arg_params, aux_params = mx.model.load_checkpoint('Inception-BN', 126)

mod = mx.mod.Module(symbol=sym)

mod.bind(for_training=False, data_shapes=[('data', (1, 3, 224, 224))])
mod.set_params(arg_params, aux_params)

image_path = '00.jpg'
img = cv2.imread(image_path)
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
img = cv2.resize(img, (224, 224,))
img = np.swapaxes(img, 0, 2)
img = np.swapaxes(img, 1, 2)

img = img[np.newaxis, :]
array = mx.nd.array(img)
print('array.shape: ', array.shape)

from collections import namedtuple
Batch = namedtuple('Batch', ['data'])
mod.forward(Batch([array]))
prob = mod.get_outputs()[0].asnumpy()

prob = np.squeeze(prob)
print('prob.shape: ', prob.shape)
sortedprob = np.argsort(prob)[::-1]
prob[sortedprob[0]]

synsetfile = open('synset.txt', 'r')
categorylist = []
for line in synsetfile:
  categorylist.append(line.rstrip())
print(categorylist[546])

net = mx.sym.Variable('data')
net = mx.sym.FullyConnected(net, name='fc1', num_hidden=64)
net = mx.sym.Activation(net, name='relu1', act_type="relu")
net = mx.sym.FullyConnected(net, name='fc2', num_hidden=26)
net = mx.sym.SoftmaxOutput(net, name='softmax')
mx.viz.plot_network(net).view()
print('end')
