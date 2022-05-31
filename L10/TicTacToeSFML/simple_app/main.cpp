#include "common_defs.h"
#include "tictactoe.h"
#include "tictactoebot.h"
#include <iostream>
using namespace std;
class TTTPlayer : public TicTacToeAbstractPlayer
{
    char convert(Player p)
    {
        if (p == Player::cross)
            return 'x';
        if (p == Player::circle)
            return 'o';

        return '.';
    }

public:
    TTTPlayer(size_t size, Player player) : TicTacToeAbstractPlayer(size, player) {}
    Position move()
    {
        int row, col;
        std::cin >> row >> col;
        return {row, col};
    }

    void display()
    {
        for (const auto &row : board_) {
            for (const auto &el : row) {
                std::cout << convert(el);
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    TicTacToe game(3);
    vector<TicTacToeAbstractPlayer *> players;
    players.emplace_back(new TTTPlayer(3, Player::cross));
    players.emplace_back(new TicTacToeBot(3, Player::circle));

    Status res;

    do {
        for (auto &player : players) {
            //            int row, col;
            //            std::cin >> row >> col;
            auto [player_symbol, status] = game.move(player->move(), player->player());
            player->update(game.state());
            res = status;
            player->display();
            if (status != Status::move)
                break;
        }

        //game.debug();

    } while (res == Status::move);

    return 0;
}
