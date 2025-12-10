import sys

CENTER_SLOTS = [(1, 1)]
CORNER_SLOTS = [(0, 0), (0, 2), (2, 0), (2, 2)]
EDGE_SLOTS = [(1, 0), (0, 1), (2, 1), (1, 2)]
MOVE_ORDER = CENTER_SLOTS + CORNER_SLOTS + EDGE_SLOTS #при Минимакс е такъв приоритета на ходове

INF = 3

def check_win(board, player):
    # редове
    for row in board:
        if all(cell == player for cell in row):
            return True
    # колони
    for c in range(3):
        if all(board[r][c] == player for r in range(3)):
            return True
    # диагонали
    if all(board[i][i] == player for i in range(3)):
        return True
    if all(board[i][2 - i] == player for i in range(3)):
        return True
    return False


def board_full(board):
    return all(cell != '_' for row in board for cell in row)


def score_position(board, depth, max_player, min_player):
    if check_win(board, max_player): #предпочита по-бързи победи
        return 1 - 0.01 * depth
    if check_win(board, min_player): #предпочита по бавни загуби
        return -1 + 0.01 * depth
    return 0.0


def minimax_ab(board, depth, alpha, beta, is_max_turn, max_player, min_player):
    current_score = score_position(board, depth, max_player, min_player)
    if current_score != 0:
        return current_score
    if board_full(board):
        return 0.0

    if is_max_turn:
        best_val = -INF
        for r, c in MOVE_ORDER:
            if board[r][c] == '_':
                board[r][c] = max_player
                val = minimax_ab(board, depth + 1, alpha, beta, False, max_player, min_player)
                board[r][c] = '_'
                if val > best_val:
                    best_val = val
                if val > alpha:
                    alpha = val
                if beta <= alpha:
                    break
        return best_val
    else:
        best_val = INF
        for r, c in MOVE_ORDER:
            if board[r][c] == '_':
                board[r][c] = min_player
                val = minimax_ab(board, depth + 1, alpha, beta, True, max_player, min_player)
                board[r][c] = '_'
                if val < best_val:
                    best_val = val
                if val < beta:
                    beta = val
                if beta <= alpha:
                    break
        return best_val


def choose_best_move(board, agent_symbol, enemy_symbol):
    best_score = -INF
    best_move = None
    for r, c in MOVE_ORDER:
        if board[r][c] == '_':
            board[r][c] = agent_symbol
            val = minimax_ab(board, 0, -INF, INF, False, agent_symbol, enemy_symbol)
            board[r][c] = '_'
            if val > best_score:
                best_score = val
                best_move = (r, c)
    return best_move


def load_board(stdin):
    lines = [stdin.readline().rstrip("\n") for _ in range(7)]
    board = []
    for idx in (1, 3, 5):  # редовете с клетките
        parts = lines[idx].split("|")
        row = [parts[1].strip(), parts[2].strip(), parts[3].strip()]
        board.append(row)
    return board


def show_board(board):
    sep = "+---+---+---+"
    print(sep)
    for r in range(3):
        print(f"| {board[r][0]} | {board[r][1]} | {board[r][2]} |")
        print(sep)


def run_judge():
    turn_line = sys.stdin.readline().strip()
    _, to_move = turn_line.split()

    board = load_board(sys.stdin)

    if check_win(board, "X") or check_win(board, "0") or board_full(board):
        print(-1)
        return

    agent = to_move
    opponent = "0" if agent == "X" else "X"

    move = choose_best_move(board, agent, opponent)
    r, c = move[0] + 1, move[1] + 1
    print(r, c)


def run_game():
    first_line = sys.stdin.readline().strip()
    human_line = sys.stdin.readline().strip()

    _, first_player = first_line.split()
    _, human_player = human_line.split()

    if first_player == "O":
        first_player = "0"
    if human_player == "O":
        human_player = "0"

    board = load_board(sys.stdin)

    ai_player = "0" if human_player == "X" else "X"
    current = first_player

    while True:
        show_board(board)

        if check_win(board, "X"):
            print("WINNER: X")
            return
        if check_win(board, "0"):
            print("WINNER: 0")
            return
        if board_full(board):
            print("DRAW")
            return

        if current == human_player:
            try:
                line = input().strip()
            except EOFError:
                return
            if not line:
                continue
            try:
                r, c = map(int, line.split())
            except ValueError:
                continue
            r -= 1
            c -= 1
            if 0 <= r < 3 and 0 <= c < 3 and board[r][c] == "_":
                board[r][c] = human_player
            else:
                continue
        else:
            move = choose_best_move(board, ai_player, human_player)
            if move is not None:
                board[move[0]][move[1]] = ai_player

        current = "0" if current == "X" else "X"


def main():
    mode = sys.stdin.readline().strip()
    if mode == "JUDGE":
        run_judge()
    elif mode == "GAME":
        run_game()
    else:
        return


if __name__ == "__main__":
    main()
