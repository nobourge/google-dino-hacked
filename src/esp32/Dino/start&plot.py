"""
Auto-updating plot of photosensors signals via esp32
"""
import datetime as dt
from random import randint

import requests
import matplotlib

matplotlib.use("TkAgg")

import matplotlib.pyplot as plt
import matplotlib.animation as animation

# starts program
#exec(open("dino.ino").read())

# # make sure the 'COM#' is set according the Windows Device Manager
# import serial
# ser = serial.Serial('COM4', 9800, timeout=1)
# time.sleep(2)

# function to pull out a float from the requests response object
def pull_float(response):
    jsonr = response.json()
    strr = jsonr["data"][0]
    if strr:
        fltr = round(float(strr), 2)
        return fltr
    else:
        return None


# Create figure for plotting
fig, ax = plt.subplots()
xs = [0 for i in range(999)]
ys = [0 for i in range(999)]

def animate(i, xs:list, ys:list):
    response = randint(0, 100)
    #            # from esp32
    # line = ser.readline()   # read a byte
    # if line:
    #     string = line.decode()  # convert the byte string to a unicode string
    #     num = int(string) # convert the unicode string to an int
    #     print(num)
    # # pull out the float from the json object
    # float = pull_float(num)

    ## Add x and y to lists
    xs.append(dt.datetime.now().strftime('%H:%M:%S'))
    ys.append(response)
    # Limit x and y lists to 10 items
    xs = xs[-9:]
    ys = ys[-9:]
    # Draw x and y lists
    ax.clear()
    ax.plot(xs, ys)
    # Format plot
    ax.set_ylim([0,255])
    plt.xticks(rotation=45, ha='right')
    plt.subplots_adjust(bottom=0.20)

    fig = plt.figure()

    ax.set_title('Plot of random numbers from https://qrng.anu.edu.au')
    ax.set_xlabel('Date Time (hour:minute:second)')
    ax.set_ylabel('Candela')
    plt.axis('off')

# Set up plot to call animate() function every 1000 milliseconds
ani = animation.FuncAnimation(fig, animate, fargs=(xs,ys), interval=0.1)

fig.tight_layout()
win = plt.gcf().canvas.manager.window
win.lift()
win.attributes("-topmost", True)
win.attributes("-transparentcolor", "white")

plt.show()
#plt.show(transparent=True)
