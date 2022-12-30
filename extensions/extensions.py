file = input("File name: ").lower().strip()

jaypeg = ("jpg", "jpeg")

if file.endswith("gif"):
    print("image/gif")
elif file.endswith(jaypeg):
    print("image/jpg")
elif file.endswith("png"):
    print("image/png")
elif file.endswith("pdf"):
    print("image/pdf")
elif file.endswith("txt"):
    print("image/txt")
elif file.endswith("zip"):
    print("image/zip")
else:
    print("application/octet-stream")

