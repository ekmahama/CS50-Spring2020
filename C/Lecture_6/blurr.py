from PIL import Image, ImageFilter
before = Image.open("lena.jpg")
after = before.filter(ImageFilter.BLUR)
after.save("out.jpg")
