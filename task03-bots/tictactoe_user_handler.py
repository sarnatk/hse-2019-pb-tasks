from typing import Callable, Optional
from bot import UserHandler
from tictactoe import Player, TicTacToe


class TicTacToeUserHandler(UserHandler):
    def __init__(self, send_message: Callable[[str], None]) -> None:
        super(TicTacToeUserHandler, self).__init__(send_message)
        self.game: Optional[TicTacToe] = None

    def handle_message(self, message: str) -> None:
        # Обрабатывает очередное сообщение от пользователя
        if message == 'start':
            self.start_game()
            return
        if self.game is None:
            self.send_message('Game is not started')
            return
        player, col, row = message.split(maxsplit=2)
        if player not in ['X', 'O']:
            self.send_message('Invalid turn')
            return
        self.make_turn(Player[player], row=int(row), col=int(col))

    def start_game(self) -> None:
        # Начинает новую игру в крестики-нолики и сообщает об этом пользователю
        self.game = TicTacToe()
        self.send_field()

    def make_turn(self, player: Player, *, row: int, col: int) -> None:
        # Обрабатывает ход игрока player в клетку (row, col)
        assert self.game
        if not self.game.can_make_turn(player, row=row, col=col):
            self.send_message('Invalid turn')
            return
        self.game.make_turn(player, row=row, col=col)
        self.send_field()
        if self.game.is_finished():
            winner = self.game.winner()
            if winner is None:
                self.send_message('Game is finished, draw')
            else:
                self.send_message(f'Game is finished, {winner.name} wins')
            self.game = None

    def send_field(self) -> None:
        # Отправляет пользователю сообщение с текущим состоянием игры
        assert self.game
        field = ''
        for row in self.game.field:
            for cell in row:
                field += cell.name if cell else '.'
            field += '\n'
        self.send_message(field.rstrip('\n'))
