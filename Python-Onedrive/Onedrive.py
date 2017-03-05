import os
import sys
import onedrivesdk


REDIRECT_URL  = 'http://localhost:8080/'
CLIENT_ID     = '00000000401CDF7B'
CLIENT_SECRET = 'J1toxbxTRhNLKDAposAZUEr'

SCOPES=['wl.signin', 'wl.offline_access', 'onedrive.readwrite']

def get_client():
    client = onedrivesdk.get_default_client(CLIENT_ID, SCOPES)
    auth_url = client.auth_provider.get_auth_url(REDIRECT_URL)
    from onedrivesdk.helpers import GetAuthCodeServer
    code = GetAuthCodeServer.get_auth_code(auth_url, REDIRECT_URL)
    client.auth_provider.authenticate(code, REDIRECT_URL, CLIENT_SECRET)
    return client

def folders_by_path(client, path, debug = False):
    try:
        items = client.item(path=path).children.get()
    except AttributeError:
        print("Oops! Onedrive Client is wrong!")
        return None
    except onedrivesdk.error.OneDriveError:
        print("Oops! Path is not in onedrive:", path)
        return None
    except:
        print("Unexpected error:", sys.exc_info()[0])
        return None
    newitems = filter(lambda item: item.folder, items)
    if debug:    
        for i in newitems:
                print('--------------------')
                print('folder name: %s'%i.name)
                print('folder url : %s'%i.url)
    return newitems

def files_by_path(client, path, debug = False):
    try:
        items = client.item(path=path).children.get()
    except AttributeError:
        print("Oops! Onedrive Client is wrong!")
        return None
    except onedrivesdk.error.OneDriveError:
        print("Oops! Path is not in onedrive:", path)
        return None
    except:
        print("Unexpected error:", sys.exc_info()[0])
        return None
    newitems = filter(lambda item: not item.folder, items)
    if debug:    
        for i in newitems:
                print('--------------------')
                print('file name: %s'%i.name)
                print('file url : %s'%i.url)
    return newitems

def images_by_path(client, path, debug = False):
    try:
        items = client.item(path=path).children.get()
    except AttributeError:
        print("Oops! Onedrive Client is wrong!")
        return None
    except onedrivesdk.error.OneDriveError:
        print("Oops! Path is not in onedrive:", path)
        return None
    except:
        print("Unexpected error:", sys.exc_info()[0])
        return None
    newitems = filter(lambda item: item.image, items)
    if debug:    
        for i in newitems:
                print('--------------------')
                print('image name: %s'%i.name)
                print('image url : %s'%i.url)
    return newitems

def imgurl_by_path(client, path, debug = False):
    try:
        items = client.item(path=path).children.get()
    except AttributeError:
        print("Oops! Onedrive Client is wrong!")
        return None
    except onedrivesdk.error.OneDriveError:
        print("Oops! Path is not in onedrive:", path)
        return None
    except:
        print("Unexpected error:", sys.exc_info()[0])
        return None
    newitems = filter(lambda item: item.image, items)
    if debug:    
        for i in newitems:
                print('--------------------')
                print('imgurl name: %s'%i.name)
                print('imgurl url : %s'%i.url)
    for i in newitems:
        yield i.url

def imgurls_by_path(client, path, debug = False):
    try:
        items = client.item(path=path).children.get()
    except AttributeError:
        print("Oops! Onedrive Client is wrong!")
        return None
    except onedrivesdk.error.OneDriveError:
        print("Oops! Path is not in onedrive:", path)
        return None
    except:
        print("Unexpected error:", sys.exc_info()[0])
        return None
    newitems = filter(lambda item: item.image, items)
    urls = map(lambda item: item.url, newitems)
    if debug:    
        for url in urls:
                print('--------------------')
                print('imgurls url : %s'% url)
    return urls

if __name__=='__main__':
    print(__file__)
    item_id = "root"
    folder_name = '/Pictures/family-shares'
    c = get_client()
    folders_by_path(c, folder_name,True)
    files_by_path(c, folder_name,True)
    images_by_path(c, folder_name,True)
    for i in imgurl_by_path(c, folder_name,True):
        pass
    imgurls_by_path(c, folder_name,True)
    exit(0)