import os
import onedrivesdk
from onedrivesdk.helpers import GetAuthCodeServer

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

if __name__=='__main__':
    print(__file__)
    exit(0)