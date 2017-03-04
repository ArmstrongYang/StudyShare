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

## Upload an Item
## 说明，@hiyangdong 2017-03-04 14:13:48
## upload后面的路径是本地上传文件的路径，而children是传上去后的名字
returned_item = client.item(drive='me', id='root').children['newfile.txt'].upload('./newfile.txt')

returned_item = client.item(drive='me', id='root').children['xxx.txt'].upload('./d/newfile.txt')

if __name__=='__main__':
    print(__file__)
    dir = os.getcwd()
    print(dir)
    filelist = os.listdir(dir)
    print(filelist)
    exit(0)