words = set()


def check(word):
    if word.lower() in words:
        return True
    return False


def load(dictionary):
    file = open(dictionary)
    for line in file:
        words.add(line.rstrip())
    file.close()
    return True


def size():
    return len(words)


def unload():
    pass
    return True
