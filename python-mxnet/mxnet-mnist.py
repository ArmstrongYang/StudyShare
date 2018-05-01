
import mxnet as mx


# data

mnist = mx.test_utils.get_mnist()

mx.random.seed(42)
ctx = mx.cpu()
batch_size = 100
train_iter = mx.io.NDArrayIter(
    mnist['train_data'], mnist['train_label'], batch_size, shuffle=True)
val_iter = mx.io.NDArrayIter(
    mnist['test_data'], mnist['test_label'], batch_size)


# network
data = mx.sym.var('data')

conv1 = mx.sym.Convolution(data, kernel=(5, 5), num_filter=20)
tanh1 = mx.sym.Activation(conv1, act_type="tanh")
pool1 = mx.sym.Pooling(tanh1, pool_type="max", kernel=(2, 2), stride=(2, 2))

conv2 = mx.sym.Convolution(pool1, kernel=(5, 5), num_filter=50)
tanh2 = mx.sym.Activation(conv2, act_type="tanh")
pool2 = mx.sym.Pooling(tanh2, pool_type="max", kernel=(2, 2), stride=(2, 2))

flatten = mx.sym.flatten(pool2)
fc1 = mx.sym.FullyConnected(flatten, num_hidden=500)
tanh3 = mx.sym.Activation(fc1, act_type="tanh")

fc2 = mx.sym.FullyConnected(tanh3, num_hidden=10)

lenet = mx.sym.SoftmaxOutput(fc2, name="softmax")

mx.viz.plot_network(lenet).view()


# train

lenet_model = mx.mod.Module(lenet, context=ctx)


# train with the same
lenet_model.fit(train_iter,
                eval_data=val_iter,
                optimizer='sgd',
                optimizer_params={'learning_rate': 0.1},
                eval_metric='acc',
                batch_end_callback=mx.callback.Speedometer(batch_size, 100),
                num_epoch=10)
test_iter = mx.io.NDArrayIter(mnist['test_data'], None, batch_size)
prob = lenet_model.predict(test_iter)
test_iter = mx.io.NDArrayIter(
    mnist['test_data'], mnist['test_label'], batch_size)
# predict accuracy for lenet
acc = mx.metric.Accuracy()
lenet_model.score(test_iter, acc)
print(acc)
