def ExeFile( shellcode, OS=None):

    from logger import logs
    from Database.exedb import ros
    from raw import RawFile


    db = ros()
    padd = ""
    if OS == "linux_x86":
        padd = db[0]
    elif OS == "linux_x64":
       padd = db[1]
    elif OS == "windows":
       padd = db[2]
    elif OS == "openbsdx86":
        padd = db[3]
    elif OS == "solarisx86":
        padd = db[4]
    elif OS == "linuxpowerpc":
        padd = db[5]
    elif OS == "openbsdpowerpc":
        padd = db[6]
    elif OS == "linuxsparc":
        padd = db[7]
    elif OS == "freebsdsparc":
        padd = db[8]
    elif OS == "opensbdsparc":
        padd = db[9]
    elif OS == "solarissparc":
        padd = db[10]
    elif OS == "linux_arm":
        padd = db[11]
    elif OS == "freebsdarm":
        padd = db[12]
    elif OS == "opensbdarm":
       padd = db[13]
    else:
        print "Not supported os .."
        return

    shellcode = shellcode.replace("\\x", "")
    shellcode = padd.replace("SHELLCODE", shellcode)
    logs( shellcode.decode("hex"), None, OS)

