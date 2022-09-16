from http.server import BaseHTTPRequestHandler, HTTPServer
import json
class MyHandler(BaseHTTPRequestHandler):

	def echo(self):
		if len(self.path.split('?')) > 1:
			param_strings = self.path.split('?')[1].split('&')
			params = [{x.split('=')[0]:x.split('=')[1]} for x in param_strings]
			print(params)
			message = json.dumps(params,indent=2)
		else:
			message = 'nothing'
		self.send_response (200)
		self.send_header ('Content-Type','text/html')
		self.end_headers ()
		self.wfile.write (bytes(message, "utf8"))

	def do_GET (self):
		# print(dir(self))
		# self.parse_request
		print(self.client_address)
		print(self.path)
		if self.path.split('?')[0].lstrip('/') == 'echo': #/echo
			return self.echo()
		self.send_response (200)
		self.send_header ('Content-Type','text/html')
		self.end_headers ()
		message = "Hello world!"
		self.wfile.write (bytes(message, "utf8"))

with HTTPServer (('', 7000), MyHandler) as server:
	server.serve_forever()