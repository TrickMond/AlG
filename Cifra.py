import sys, random, copy
from PIL import Image

IMAGE_PATH = ""
IMAGE_NAME = "Foto_128x128"
IMAGE_TYPE = "jpg"

image = Image.open(IMAGE_PATH + IMAGE_NAME + "." + IMAGE_TYPE)

def filter(pixel):
    x = round(pixel/20)*20
    return x

width = image.size[0]
height = image.size[1]
pixels = image.load()
t = height/2

a = [0]*width

for i in range(width): 
    a[i] = [0]*3 
    a[i][0] = filter(pixels[i, t][0]) 
    a[i][1] = filter(pixels[i, t][1]) 
    a[i][2] = filter(pixels[i, t][2]) 
    print(a[i][0], end = ' ') 
    print(a[i][1], end = ' ') 
    print(a[i][2])
    
