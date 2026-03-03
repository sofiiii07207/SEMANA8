def solve_n_queens(n):
    cols = set()
    diag1 = set()  # (row - col)
    diag2 = set()  # (row + col)
    board = [-1] * n  # board[row] = col

    def backtrack(row):
        if row == n:
            return True  # encontramos solución

        for col in range(n):
            if col in cols or (row - col) in diag1 or (row + col) in diag2:
                continue

            # elegir
            board[row] = col
            cols.add(col)
            diag1.add(row - col)
            diag2.add(row + col)

            # explorar
            if backtrack(row + 1):
                return True

            # deshacer (vuelta atrás)
            board[row] = -1
            cols.remove(col)
            diag1.remove(row - col)
            diag2.remove(row + col)

        return False

    backtrack(0)
    return board

def print_board(board):
    n = len(board)
    for r in range(n):
        row = ["." for _ in range(n)]
        row[board[r]] = "Q"
        print(" ".join(row))

n = 8
solution = solve_n_queens(n)
print("Solucion (fila -> columna):", solution)
print_board(solution)
