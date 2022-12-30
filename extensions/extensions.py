file = input("File name: ").lower().strip()

if file.endswith("gif"):
    print("image/gif")
elif file.endswith("jpg"):
    print("image/jpg")
elif file.endswith("jpeg"):
    print("image/jpeg")
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

