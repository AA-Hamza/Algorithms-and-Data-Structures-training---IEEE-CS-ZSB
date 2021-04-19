_ROW_MODE = 0
_COLUMN_MODE = 1

class Crossword:
    def __init__(self, x, y, length, mode):
        self.x = x
        self.y = y
        self.length = length
        self.mode = mode
        self.relations = []

    def test_word_length(self, word):
        if (len(word) != length):
            return False;
        return True;
    
    def add_relation(self, relation):
        self.relations.append(relation)


def get_row_words(grid):
    row_words = []
    for line in range(0, len(grid)):
        flag = 0
        for char in range(1, len(grid[line])):
            if (grid[line][char] == '-' and grid[line][char] == grid[line][char-1]):
                if (flag == 0):
                    row_words.append(Crossword(line, char, 2, _ROW_MODE))
                    flag = 1
                else:
                    row_words[-1].length += 1
            else:
                flag = 0
    return row_words

def get_column_words(grid):
    column_words = []
    for column in range(0, 10):
        flag = 0
        for row in range(1, 10):
            if (grid[row][column] == '-' and grid[row][column] == grid[row-1][column]):
                if (flag == 0):
                    column_words.append(Crossword(row, column, length, _COLUMN_MODE))
                    flag = 1
                else:
                    column_words[-1].length += 1
                check_near(grid, x, y)
            else:
                flag = 0

    return column_words

grid = []
for _ in range(10):
    grid.append(input())

words = input().split(";")
print(grid)

row_words = get_row_words(grid)
column_words = get_column_words(grid)

#crossword_list = row_words+column_words

#def solve():

