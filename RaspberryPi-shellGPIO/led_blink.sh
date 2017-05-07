# 获得超级权限  
sudo su  
# 进入GPIO目录  
cd /sys/class/gpio  
# 使用ls查看gpio目录中的内容，可以查看到  
# export gpiochip0 unexport   
ls  
# GPIO操作接口从内核空间暴露到用户空间  
# 执行该操作之后，该目录下会增加一个gpio4文件  
echo 4 > export  
# 进入GPIO4目录，该目录由上一步操作产生  
cd gpio4  
#   查看gpio4目录中的内容，可查看到  
#   active_low direction edge power subsystem uevent value  
ls   
# 设置GPIO4为输出方向  
echo out > direction  
# BCM_GPIO4输出逻辑高电平，LED点亮  
echo 1 > value  
#  BCM_GPIO4输出逻辑低电平，LED熄灭  
echo 0 > value  
# 返回上一级目录  
cd ../  
# 注销GPIO4接口  
echo 4 > unexport  
# 退出超级用户  
exit  