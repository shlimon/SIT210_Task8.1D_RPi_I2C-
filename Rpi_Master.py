from smbus import SMBus
import time

addr = 0x8
bus = SMBus(1)

send = 1


while True:
    data = ""
    for i in range(0,7):
        data += chr(bus.read_byte(addr));
    print(data)
    time.sleep(1);