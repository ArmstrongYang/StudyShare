import os
import onedrivesdk
from onedrivesdk.helpers import GetAuthCodeServer

redirect_uri = 'http://localhost:8080/'
client_secret = 'J1toxbxTRhNLKDAposAZUEr'
client_id='00000000401CDF7B'
api_base_url='https://api.onedrive.com/v1.0/'
scopes=['wl.signin', 'wl.offline_access', 'onedrive.readwrite']

client = onedrivesdk.get_default_client(
    client_id=client_id, scopes=scopes)

auth_url = client.auth_provider.get_auth_url(redirect_uri)

#this will block until we have the code
code = GetAuthCodeServer.get_auth_code(auth_url, redirect_uri)
client.auth_provider.authenticate(code, redirect_uri, client_secret)

def view_thumbnail(client, item_id):
    if len(client.item(id=item_id).thumbnails.get()) == 0:
        print("File does not have any thumbnails!\n")
    else:
        action = int(input("Size? 1:Small 2:Medium 3:Large... "))
        try:
            os.remove("./tmp_thumb.jpg")
        except:
            pass
        if action == 1:
            client.item(id=item_id).thumbnails[0].small.download("./tmp_thumb.jpg")
        elif action == 2:
            client.item(id=item_id).thumbnails[0].medium.download("./tmp_thumb.jpg")
        elif action == 3:
            client.item(id=item_id).thumbnails[0].large.download("./tmp_thumb.jpg")
        image = Image.open("./tmp_thumb.jpg")
        image.show()

item_id = 'root'

view_thumbnail(client,item_id)

items = client.item(id=item_id)
k=0
#for i in items.thumbnails:
#    k=k+1;print(k)
#    if i.small.download("./tmp_thumb.jpg"):
#        j = i.small.download("./tmp_thumb.jpg")
thumb = client.item(id=item_id).thumbnails
img = thumb[8].small.download("./tmp_thumb.jpg")
from PIL import Image
image = Image.open("./tmp_thumb.jpg")
image.show()

root_folder = client.item(drive='me', id='root').children.get()
item_one = root_folder[8]

print('-----------')
if item_one.image:  #判断是否为图片
    print(item_one.url)

if __name__=='__main__':
    print(__file__)
    exit(0)