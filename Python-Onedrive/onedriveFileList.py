import os
import onedrivesdk
from onedrivesdk.helpers import GetAuthCodeServer
from onedrivesdk.extensions import one_drive_client_helper

## 以下三个参数都需要到dev.onedrive.com进行设置
redirect_uri = 'http://localhost:8080/'
client_secret = 'J1toxbxTRhNLKDAposAZUEr'
client_id='00000000401CDF7B'

scopes=['wl.signin', 'wl.offline_access', 'onedrive.readwrite']
client = onedrivesdk.get_default_client(client_id, scopes)
auth_url = client.auth_provider.get_auth_url(redirect_uri)

#this will block until we have the code
code = GetAuthCodeServer.get_auth_code(auth_url, redirect_uri)
client.auth_provider.authenticate(code, redirect_uri, client_secret)

## file handle

item_id = "root"
folder_name = 'Pictures/LinkShares'

def files_by_id(client, folder):
    items = client.item(id='root').children.get()
    for i in items:
        if i.folder and i.name == folder:
            lst = client.item(id=i.id).children.get()
            for j in lst:
                print(j.name)
    return lst

def images_by_path(client, path):
    items = client.item(path=path).children.get()
    newitems = filter(lambda item: item.image, items)
    for i in newitems:
        print('-----------')
        print(i.name)
        print(i.url)
    return newitems

images_by_path(client, folder_name)

if __name__=='__main__':
    print(__file__)
    
    exit(0)