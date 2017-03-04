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


root_folder = client.item(drive='me', id='root').children.get()
id_of_file = root_folder[10].id

def get_sharing_link(client, item_id):
    action = int(input("Type? 1:View 2:Edit... "))
    permission = client.item(id=item_id).create_link("view" if action == 1 else "edit").post()
    print("\n{}\n".format(permission.link.web_url))

get_sharing_link(client,id_of_file)
# ['webUrl']	'https://1drv.ms/i/s!AKFapaZo-Vpii5h6'	str
# ['@content.downloadUrl']
#'https://public-dm2306.files.1drv.com/y3m0iWGp0ppFxsnlDETu1FshFlUvKgc3eOPFL5no-G8OGXnx4gUCn5wv8gHTz7sltcKjtVueP6LjfduHOU1xZI6nvqGBB5pIDzeUCNplD89KCUK_6hCEckiUkQZ1ELKk0Ite5Ob6V4G8io2YY77BgY_bQs2KuFVAfdih8TylyZjLwOvsBmt4kYpbIn1DqUw9wohd7s37jQOS63cYKZzz-moU3rPm3i15kSttF4UCJmcRnY'
if __name__=='__main__':
    print(__file__)
    exit(0)