import complexmodule as cm

x2 = cm.Complex(25,3)

print("wookoo")

def ret():
    return 20.0

def get_complex():
    print("Getting complex")
    return x2

def get_addr():
    print("Getting addr")
    return id(x2)

def do_print():
    print(x2)

