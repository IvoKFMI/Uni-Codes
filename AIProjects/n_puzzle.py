from math import isqrt
import sys

MOVE_NAMES = ("left", "right", "up", "down")
# left означава: плочката вляво влиза в празното
DIRS = ((0, +1), (0, -1), (+1, 0), (-1, 0))
OPPOSITE = {0: 1, 1: 0, 2: 3, 3: 2}
INF = 10 ** 9


def parse_input():
    N = int(input().strip())
    I = int(input().strip())
    total = N + 1
    M = int(round((total) ** 0.5))

    board = []
    for _ in range(M):
        board.extend(map(int, input().split()))
    return N, I, M, board


def build_goal(total, zero_idx):
    goal, nxt = [0] * total, 1
    for i in range(total):
        if i != zero_idx:
            goal[i] = nxt
            nxt += 1
    return goal


def goal_maps(goal, M):
    gr = [0] * len(goal)
    gc = [0] * len(goal)
    for idx, v in enumerate(goal):
        r, c = divmod(idx, M)
        gr[v], gc[v] = r, c
    return gr, gc


def neighbors_of_all(M):
    total = M * M
    res = [[] for _ in range(total)]
    for i in range(total):
        r, c = divmod(i, M)
        for m, (dr, dc) in enumerate(DIRS):
            nr, nc = r + dr, c + dc
            if 0 <= nr < M and 0 <= nc < M:
                res[i].append((m, nr * M + nc))
    return res


#  евристика
def manhattan(board, gr, gc, M):
    s = 0
    for i, v in enumerate(board):
        if v:
            r, c = divmod(i, M)
            s += abs(r - gr[v]) + abs(c - gc[v])
    return s


def inv_parity(arr):
    a = [x for x in arr if x != 0]
    inv = 0
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if a[i] > a[j]:
                inv ^= 1
    return inv




def row_from_bottom(idx, M):
    return M - (idx // M)


def solvable(start, start_blank, goal, goal_blank, M):
    inv_s = inv_parity(start)
    inv_g = inv_parity(goal)
    if M % 2 == 1:
        return inv_s == inv_g
    ps = (inv_s + row_from_bottom(start_blank, M)) % 2
    pg = (inv_g + row_from_bottom(goal_blank, M)) % 2
    return ps == pg


# IDA*
def ida_star(start, goal, gr, gc, M, neigh):
    start = list(start)
    blank = start.index(0)
    goal_t = tuple(goal)

    if not solvable(start, blank, goal, goal.index(0), M):
        return None

    def search(g, bound, prev_move, blank_idx, path):
        h = manhattan(start, gr, gc, M)
        f = g + h
        if f > bound:
            return f, None
        if tuple(start) == goal_t:
            return -1, list(path)

        min_excess = INF
        for move, nb in neigh[blank_idx]:
            if prev_move is not None and OPPOSITE[move] == prev_move:
                continue

            # apply
            start[blank_idx], start[nb] = start[nb], start[blank_idx]
            path.append(move)

            t, sol = search(g + 1, bound, move, nb, path)
            if t == -1:
                return -1, sol
            if t < min_excess:
                min_excess = t

            # undo
            path.pop()
            start[blank_idx], start[nb] = start[nb], start[blank_idx]

        return min_excess, None

    bound = manhattan(start, gr, gc, M)
    while True:
        t, sol = search(0, bound, None, blank, [])
        if t == -1:
            return [MOVE_NAMES[m] for m in sol]
        if t == INF:
            return None
        bound = t


def main():
    N, I, M, start = parse_input()
    total = N + 1
    goal_zero = total - 1 if I == -1 else I
    goal = build_goal(total, goal_zero)
    gr, gc = goal_maps(goal, M)
    neigh = neighbors_of_all(M)

    moves = ida_star(start, goal, gr, gc, M, neigh)
    if moves is None:
        print(-1)
    else:
        print(len(moves))
        for m in moves:
            print(m)


if __name__ == "__main__":
    main()
