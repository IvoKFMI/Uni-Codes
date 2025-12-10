import sys
import os
import time


def dfs(board, end, path, solutions, visited):
    if solutions:
        return
    if board == end:
        solutions.append(path + ["".join(board)])
        return

    visited.add("".join(board))

    empty_index = board.index('_')

    if empty_index > 0 and board[empty_index - 1] == '>':
        new_board = board[:]
        new_board[empty_index], new_board[empty_index - 1] = new_board[empty_index - 1], new_board[empty_index]
        if "".join(new_board) not in visited:
            dfs(new_board, end, path + ["".join(board)], solutions, visited)

    if empty_index > 1 and board[empty_index - 2] == '>':
        new_board = board[:]
        new_board[empty_index], new_board[empty_index - 2] = new_board[empty_index - 2], new_board[empty_index]
        if "".join(new_board) not in visited:
            dfs(new_board, end, path + ["".join(board)], solutions, visited)

    if empty_index < len(board) - 1 and board[empty_index + 1] == '<':
        new_board = board[:]
        new_board[empty_index], new_board[empty_index + 1] = new_board[empty_index + 1], new_board[empty_index]
        if "".join(new_board) not in visited:
            dfs(new_board, end, path + ["".join(board)], solutions, visited)

    if empty_index < len(board) - 2 and board[empty_index + 2] == '<':
        new_board = board[:]
        new_board[empty_index], new_board[empty_index + 2] = new_board[empty_index + 2], new_board[empty_index]
        if "".join(new_board) not in visited:
            dfs(new_board, end, path + ["".join(board)], solutions, visited)


def frog_puzzle(N):
    start = ['>'] * N + ['_'] + ['<'] * N
    end = ['<'] * N + ['_'] + ['>'] * N

    solutions = []
    visited = set()

    dfs(start, end, [], solutions, visited)
    return solutions


def main():
    N = int(sys.stdin.readline().strip())
    # Измерва времето за изпълнение а програмата
    t0 = time.time()

    result = frog_puzzle(N)

    # Ако тестът е само за време — не печатай жабите
    if os.getenv("FMI_TIME_ONLY") == "1":
        print(f"# TIMES_MS: alg={int((time.time() - t0) * 1000)}")
        return

    # иначе печатай пълното решение
    for step in result[0]:
        print(step)

    #print(f"Време за изпълнение: {int((time.time() - t0) * 1000)} ms")


if __name__ == "__main__":
    main()