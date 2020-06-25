import qrcode

image = qrcode.make('https://youtu.be/fL308_-Kbt0')
image.save("qr.png", "PNG")
