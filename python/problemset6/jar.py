import sys


class Jar:
    def __init__(self, capacity=12, size=0):
        self.capacity = capacity
        self.size = size

    def __str__(self):
        return self.size*"🍪"

    def deposit(self, n):
        if (self.size+n > self.capacity):
            raise ValueError("Too many cookies in jar!")
        else:
            self.size += n

    def withdraw(self, n):
        if (self.size-n < 0):
            raise ValueError("Not enough cookies in jar!")
        else:
            self.size -= n

    @property
    def _capacity(self):
        return self.capacity

    def _size(self):
        return self.size


jar = Jar()
jar2 = Jar(20, 10)
print(str(jar.capacity))
print(str(jar2.capacity))
print(str(jar.size))
print(str(jar2.size))
print(str(jar))
print(str(jar2))
jar.deposit(3)
jar2.withdraw(3)
print(str(jar.size))
print(str(jar2.size))
print(str(jar))
print(str(jar2))
