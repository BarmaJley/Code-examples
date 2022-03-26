import os
import tempfile

class File(object):
    def __new__(cls, *args, **kwargs):

        if not os.path.exists(args[0]):
            os.chdir(tempfile.gettempdir())
            open(args[0], "w").close()

        return super().__new__(cls)

    def __init__(self, file_name):
        self.file_name = file_name

    def __str__(self):
        return os.path.join(os.getcwd(), self.file_name)

    def __add__(self, other):
        with open(self.file_name, 'a') as file_1:
            with open(other.file_name, 'r') as file_2:
                file_1.write(file_2.read())
                return self

    def __getitem__(self, index):
        with open(self.file_name, 'r') as file:
            return file.readlines()[index]

    def read(self):
        with open(self.file_name, 'r+') as file:
            return file.read()

    def write(self, text):
        with open(self.file_name, 'w') as file:
            return file.write(text)


