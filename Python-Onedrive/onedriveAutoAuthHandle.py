import os
import onedrivesdk
from onedrivesdk.helpers import GetAuthCodeServer

redirect_uri = 'http://localhost:8080/'
client_secret = 'J1toxbxTRhNLKDAposAZUEr'
client_id='00000000401CDF7B'
api_base_url='https://api.onedrive.com/v2.0/'
scopes=['wl.signin', 'wl.offline_access', 'onedrive.readwrite']

client = onedrivesdk.get_default_client(
    client_id=client_id, scopes=scopes)

auth_url = client.auth_provider.get_auth_url(redirect_uri)

#this will block until we have the code
code = GetAuthCodeServer.get_auth_code(auth_url, redirect_uri)

client.auth_provider.authenticate(code, redirect_uri, client_secret)

# Add a folder
f = onedrivesdk.Folder()
i = onedrivesdk.Item()
i.name = 'New Folder'
i.folder = f

returned_item = client.item(drive='me', id='root').children.add(i)

# Download an Item
# 说明@hiyangdong， 2017-03-04 13:56:41
## client.item(drive='me', id=id_of_file).download('./path_to.txt')其中download后面的路径式下载后的文件路径和名字,./为当前目录下的名字,也可以选择绝对路径
## id_of_file是一个文件的路径，而不是文件夹
## 
root_folder = client.item(drive='me', id='root').children.get()
id_of_file = root_folder[10].id
print(root_folder[10])
print(id_of_file)
instant_of_file = root_folder[10]
print(instant_of_file)
print(instant_of_file)
print('--------------')
downlink_of_file = root_folder[10]._prop_dict['@content.downloadUrl']
print(downlink_of_file)
client.item(drive='me', id=id_of_file).download('./path_to.txt')
client.item(drive='me', id=id_of_file).download('E:/Downloads/path_to.txt')

## Upload an Item
#returned_item = client.item(drive='me', id='root').children['newfile.txt'].upload('./newfile.txt')

## 以下并不能成功
#returned_item = client.item(drive='me', id='root').children['newfile.txt'].upload('./Databases/newfile.txt')

if __name__=='__main__':
    print(__file__)
    dir = os.getcwd()
    print(dir)
    filelist = os.listdir(dir)
    print(filelist)
    exit(0)