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

item_id = "root"

def navigate(client, item_id):
    items = client.item(id=item_id).children.get()
    return items

items = navigate(client, item_id)
print('--------------')
for i in items:
    print(i.name)

if __name__=='__main__':
    print(__file__)
    
    exit(0)