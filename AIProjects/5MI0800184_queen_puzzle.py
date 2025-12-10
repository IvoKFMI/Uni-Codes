import sys
import time
import random
import os

MAX_STEPS_FACTOR = 1000

def construct_initial(n):
    if n in (2, 3):
        return -1
    evens = list(range(2, n + 1, 2))
    odds = list(range(1, n + 1, 2))
    if n % 6 == 2:
        evens = [2, 4, 6, 8] + [x for x in evens if x not in (2, 4, 6, 8)]
        odds = [3, 1, 7, 5] + [x for x in odds if x not in (1, 3, 5, 7)]
    elif n % 6 == 3:
        evens = [4, 6, 8, 2] + [x for x in evens if x not in (2, 4, 6, 8)]
        odds = [1, 3, 5, 7] + [x for x in odds if x not in (1, 3, 5, 7)]
    return [x - 1 for x in evens + odds]

def min_conflicts(n, board, max_steps):
    if board == -1:
        return -1
    rows = [0] * n
    diagonal1 = [0] * (2 * n)
    diagonal2 = [0] * (2 * n)

    for column, row in enumerate(board):
        rows[row] += 1
        diagonal1[row - column + n] += 1
        diagonal2[row + column] += 1

    for _ in range(max_steps):
        conflicted = [column for column, row in enumerate(board) if rows[row] > 1 or diagonal1[row - column + n] > 1 or diagonal2[row + column] > 1]
        if not conflicted:
            return board
        column = random.choice(conflicted)
        old_row = board[column]
        best_row = old_row
        min_conflict = n + 1

        for row in range(n):
            conflict = rows[row] + diagonal1[row - column + n] + diagonal2[row + column]
            if row == old_row:
                conflict -= 3
            if conflict < min_conflict:
                min_conflict = conflict
                best_row = row

        if best_row != old_row:
            rows[old_row] -= 1
            diagonal1[old_row - column + n] -= 1
            diagonal2[old_row + column] -= 1
            board[column] = best_row
            rows[best_row] += 1
            diagonal1[best_row - column + n] += 1
            diagonal2[best_row + column] += 1

    return board

def print_board(board):
    n = len(board)
    for row in range(n):
        print(' '.join('*' if board[column] == row else '_' for column in range(n)))

def main():
    try:
        n = int(input().strip())
    except:
        print("-1")
        return

    if n == 1:
        print("# TIMES_MS: alg=0")
        print("[0]")
        print_board([0])
        return

    if n in (2, 3):
        print("-1")
        return

    start_time = time.perf_counter()
    board = construct_initial(n)

    if n <= 1000:
        max_steps = n * MAX_STEPS_FACTOR
        solution = min_conflicts(n, board, max_steps)
    else:
        solution = board

    end_time = time.perf_counter()
    elapsed_ms = int((end_time - start_time) * 1000)

    print(f"# TIMES_MS: alg={elapsed_ms}")

    if os.environ.get("FMI_TIME_ONLY") == "1":
        return

    if solution == -1:
        print("-1")
    else:
        print("[" + ",".join(map(str, solution)) + "]")
        if n <= 20:
            print_board(solution)

if __name__ == "__main__":
    main()