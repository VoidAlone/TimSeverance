class Person:
    def __init__(self, age):
        self.age = age

class Tim(Person):
    def __init__(self):
        Person.__init__(self,33)
        self.__information = "objects are about information hiding"

    def teach(self) -> str:
        return self.__information

class Student(Person):
    def __init__(self):
        Person.__init__(self, 25)
        self.__information = ""

    def learn(self, info: str) -> None:
        self.__information = info

def main():
    tim = Tim()
    student = Student()
    student.learn(tim.teach())

if __name__ == "__main__":
    main()

