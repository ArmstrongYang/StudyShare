import os
from github import Github


def git():
    token = '95ee6de3789b5977da569cd49b77ef1196f8f6c0'
    return Github(token)

def repos_list(g):
    for repo in g.get_user().get_repos():
        yield repo

def repo(g, name):
    return g.get_user().get_repo(name)

def file_list(r,path):
    for l in r.get_dir_contents(path):
        print(l)
        #print(l.raw_data['download_url'])
        yield l

'''
get_contents和get_dir_contents接口存在以下问题（图片无法直接获取链接）
 403 {'message': 'This API returns blobs up to 1 MB in size.

经过修改
class GithubObject(object):
    @property
    def raw_data(self):
        """
        :type: dict
        """
        #self._completeIfNeeded()   #注释掉，@hiyangdong 2017-02-24 22:34:57
        return self._rawData

'''
def content(r,path):
    for l in r.get_contents(path):
        print(l)
        print(l.raw_data['download_url'])
        yield l

def read_me(g):
    rm = g.get_user().get_repo('hiShare').get_readme()
    print(rm.raw_data['download_url'])
    return rm

def raw_url(repo):
    url = repo.get_readme().raw_data['download_url']
    return os.path.dirname(url)

def test_list(g):
    for repo in g.get_user().get_repos():
        print(repo.name)
        gr = g.get_user().get_repo(repo.name).get_readme()
        print(gr)
        gr = g.get_user().get_repo('hiShare').get_dir_contents('/')
        for l in gr:
            print(l)
        gr = g.get_user().get_repo('hiShare').get_dir_contents('img/')
        for l in gr:
            print(l)
        gr = g.get_user().get_repo('hiShare').get_contents('CNAME')

        gr = g.get_user().get_repo(repo.name).get_tags()
        for l in gr:
            print(l)
        
        print(gr)
        print(type(repo))
        print(repo.git_contents())
        yield repo

if __name__=='__main__':
    g = git()
    r = repo(g,'hiShare')
    raw = raw_url(r)
    print(raw_url(r))
    for con in content(r,'/'):
        print (con)
    '''
    for x in file_list(r,'/'):
        print (x)
        print (x.path)
        print (raw + '/' + x.path)
    '''
    exit(0)

    