import os

def main():
    for root, dirs, files in os.walk("."):
        for file in files:
            file_path = os.path.join(root, file)

            name, ext = os.path.splitext(file_path)

            if ext == '.c':
                os.rename(file_path, name + '.cpp')

            elif ext == '.h':
                os.rename(file_path, name + '.hpp')

if __name__ == "__main__":
    main()