from random import *


def get_random_string():
    return ''.join(choice('abcd') for _ in range(randint(1, 3)))


if __name__ == '__main__':

    for i in range(5):
        words = 0
        n = 10
        name = str(i)
        file = open('tests/' + name + '.t', 'w')
        file.write(f"{n}\n")
        for i in range(0, n):
            op = choice(['string', 'number'])
            if op == 'string' or words == 0:
                string = get_random_string()
                words += 1
                file.write(f"{string}\n")
            else:
                number = randint(1, words)
                file.write(f"{number}\n")

        file.close()
