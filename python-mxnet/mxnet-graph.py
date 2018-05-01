import logging

import numpy as np
import mxnet as mx

logging.basicConfig(level=logging.INFO)

sample_count = 1000
train_count = 900
valid_count = sample_count - train_count
feature_count = 100
category_count = 10
batch = 10

X = mx.nd.uniform(low=0, high=1, shape=(sample_count, feature_count))

print('X.shape: ', X.shape, 'X.size: ', X.size)

Y = mx.nd.empty((sample_count, ))
for i in range(sample_count):
    Y[i] = np.random.randint(0, category_count)

print('Y.shape: ', Y.shape, 'Y.size: ', Y.size)
print('Y.asnumpy: ', Y[0:10].asnumpy())

X_train = mx.nd.crop(X, begin=(0, 0), end=(train_count, feature_count-1))
X_valid = mx.nd.crop(X, begin=(train_count, 0),
                     end=(sample_count, feature_count-1))
Y_train = Y[0:train_count]
Y_valid = Y[train_count:sample_count]

# 构建网络

data = mx.sym.Variable('data')
fc1 = mx.sym.FullyConnected(data, name='fc1', num_hidden=64)

relu1 = mx.sym.Activation(fc1, name='relu1', act_type="relu")
fc2 = mx.sym.FullyConnected(relu1, name='fc2', num_hidden=category_count)
out = mx.sym.SoftmaxOutput(fc2, name='softmax')

mod = mx.mod.Module(out)


# 数据迭代器

train_iter = mx.io.NDArrayIter(data=X_train, label=Y_train, batch_size=batch)
# for batch in train_iter:
#     print(batch.data)
#     print(batch.label)
#     raise EOFError("Eorror")

mod.bind(data_shapes=train_iter.provide_data,
         label_shapes=train_iter.provide_label)

# Allowed, but not efficient
# mod.init_params()
# Much better
mod.init_params(initializer=mx.init.Xavier(magnitude=2.))

mod.init_optimizer(optimizer='sgd', optimizer_params=(
    ('learning_rate', 0.1), ))

mod.fit(train_iter, num_epoch=50)


pred_iter = mx.io.NDArrayIter(data=X_valid,label=Y_valid, batch_size=batch)
pred_count = valid_count
correct_preds = total_correct_preds = 0
for preds, i_batch, batch in mod.iter_predict(pred_iter):
    label = batch.label[0].asnumpy().astype(int)
    pred_label = preds[0].asnumpy().argmax(axis=1)
    correct_preds = np.sum(pred_label==label)
    total_correct_preds = total_correct_preds + correct_preds
print('Validation accuracy: %2.2f' % (1.0*total_correct_preds/pred_count))

