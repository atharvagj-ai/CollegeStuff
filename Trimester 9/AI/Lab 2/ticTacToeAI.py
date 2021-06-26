#   Name : Vasu Kalariya 
#   Roll : PE29
#   AI lab Assi 2 (MinMax)

def printBoard(board):
    print(board[1] + '|' + board[2] + '|' + board[3])
    print('-+-+-')
    print(board[4] + '|' + board[5] + '|' + board[6])
    print('-+-+-')
    print(board[7] + '|' + board[8] + '|' + board[9])
    print("\n")


def spaceIsFree(position):                  # checking for the space is free or not
    if board[position] == ' ':
        return True
    else:
        return False


def insertSymbol(letter, position):             # insert symbol at given number
    if spaceIsFree(position):                   # check for free space
        board[position] = letter
        printBoard(board)
        if (checkDraw()):                       # check for Draw
            print("Draw!")
            exit()
        if checkForWin():                       # check for WIN
            if letter == 'X':
                print("AI wins!")              
                exit()
            else:
                print("Player wins!")
                exit()

        return


    else:                                       # space is already filled
        print("Can't insert there!")
        position = int(input("Please enter new position:  "))
        insertSymbol(letter, position)
        return


def checkForWin():
    if (board[1] == board[2] and board[1] == board[3] and board[1] != ' '):
        return True
    elif (board[4] == board[5] and board[4] == board[6] and board[4] != ' '):
        return True
    elif (board[7] == board[8] and board[7] == board[9] and board[7] != ' '):
        return True
    elif (board[1] == board[4] and board[1] == board[7] and board[1] != ' '):
        return True
    elif (board[2] == board[5] and board[2] == board[8] and board[2] != ' '):
        return True
    elif (board[3] == board[6] and board[3] == board[9] and board[3] != ' '):
        return True
    elif (board[1] == board[5] and board[1] == board[9] and board[1] != ' '):
        return True
    elif (board[7] == board[5] and board[7] == board[3] and board[7] != ' '):
        return True
    else:
        return False


def checkWhichSymbolWon(symbol):
    if board[1] == board[2] and board[1] == board[3] and board[1] == symbol:
        return True
    elif (board[4] == board[5] and board[4] == board[6] and board[4] == symbol):
        return True
    elif (board[7] == board[8] and board[7] == board[9] and board[7] == symbol):
        return True
    elif (board[1] == board[4] and board[1] == board[7] and board[1] == symbol):
        return True
    elif (board[2] == board[5] and board[2] == board[8] and board[2] == symbol):
        return True
    elif (board[3] == board[6] and board[3] == board[9] and board[3] == symbol):
        return True
    elif (board[1] == board[5] and board[1] == board[9] and board[1] == symbol):
        return True
    elif (board[7] == board[5] and board[7] == board[3] and board[7] == symbol):
        return True
    else:
        return False


def checkDraw():                
    for key in board.keys():
        if (board[key] == ' '):                    # if there is empty space
            return False
    return True                                    # if no empty space left


def playerTurn():
    position = int(input("Enter the position for 'O':  "))
    insertSymbol(player, position)
    return


def compTurn():
    bestScore = -800
    bestMove = 0
    for key in board.keys():
        if (board[key] == ' '):
            board[key] = AI
            score = minimax(board,False)
            board[key] = ' '
            if (score > bestScore):
                bestScore = score
                bestMove = key

    insertSymbol(AI, bestMove)
    return


def minimax(board, isMaximizing):
    if (checkWhichSymbolWon(AI)):
        return 1
    elif (checkWhichSymbolWon(player)):
        return -1
    elif (checkDraw()):
        return 0

    if (isMaximizing):                                  # trying to Maximize score
        bestScore = -1000
        for key in board.keys():
            if (board[key] == ' '):
                board[key] = AI
                score = minimax(board, False)
                board[key] = ' '
                if (score > bestScore):
                    bestScore = score
        return bestScore

    else:                                               # trying to Minimize score at next depth 
        bestScore = 1000
        for key in board.keys():
            if (board[key] == ' '):
                board[key] = player
                score = minimax(board, True)
                board[key] = ' '
                if (score < bestScore):
                    bestScore = score
        return bestScore


board = {1: ' ', 2: ' ', 3: ' ',
         4: ' ', 5: ' ', 6: ' ',
         7: ' ', 8: ' ', 9: ' '}



print("Positions are as follow:")
print("")
print("1, 2, 3 ")
print("4, 5, 6 ")
print("7, 8, 9 ")
print("\n")
player = 'O'
AI = 'X'
printBoard(board)

while not checkForWin():
    playerTurn()
    compTurn()