from urllib.request import urlopen, Request

req = Request('https://1.1.1.1', headers={"User-Agent":"Mozilla/5.0"})
# use req as url to open
r = urlopen(req)
print(r.status)
print(dict(r.headers))