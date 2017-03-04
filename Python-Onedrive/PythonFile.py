import os
import onedrivesdk

redirect_uri = 'http://localhost:8080/'
client_secret = 'J1toxbxTRhNLKDAposAZUEr'
client_id='00000000401CDF7B'
api_base_url='https://api.onedrive.com/v2.0/'
scopes=['wl.signin', 'wl.offline_access', 'onedrive.readwrite']

http_provider = onedrivesdk.HttpProvider()
auth_provider = onedrivesdk.AuthProvider(
    http_provider=http_provider,
    client_id=client_id,
    scopes=scopes)

client = onedrivesdk.OneDriveClient(api_base_url, auth_provider, http_provider)
auth_url = client.auth_provider.get_auth_url(redirect_uri)
# Ask for the code
print('Paste this URL into your browser, approve the app\'s access.')
print('Copy everything in the address bar after "code=", and paste it below.')
print(auth_url)
# 每次生成的code都不一样，在浏览器连接中查找
# The above code requires copy-pasting into your browser and back into your console. 
code = input('Paste code here: ')
# code = 'M388fd440-b4b3-ef05-d1e8-6db506860a89'
client.auth_provider.authenticate(code, redirect_uri, client_secret)

if __name__=='__main__':
    print(__file__)
    dir = os.getcwd()
    print(dir)
    filelist = os.listdir(dir)
    print(filelist)
    exit(0)