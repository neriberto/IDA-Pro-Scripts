import base64

for ss in Strings():
	s = str(ss)
	if s.endswith("=="):
		print base64.b64decode(s)