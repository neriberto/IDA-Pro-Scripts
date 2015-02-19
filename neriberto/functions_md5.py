import hashlib

for fn_ea in Functions():
    if fn_ea == None:
        continue

    f = idaapi.get_func(fn_ea)
    start = f.startEA
    size = f.endEA - start
    bytes = GetManyBytes(start, size)

    if bytes != None and len(bytes) > 19:
        fn_hash = hashlib.md5(bytes).hexdigest().upper()
        print "{0} - {1}".format(Name(fn_ea), fn_hash)
    else:
        print Name(fn_ea)
