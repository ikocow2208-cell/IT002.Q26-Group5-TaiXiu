#include "../include/Player.h"
#include <cstdlib>

Player::Player(double initial_balance) : current_bet(BetType::Xiu, 0.0) {
    setBalance(initial_balance);
    strategy = nullptr;
}

/*
 * @brief Gán chiến thuật mới, reset state và khởi tạo cược đầu tiên = base_bet
 *
 * reset() đưa strategy về trạng thái sạch — tránh Paroli/Fibonacci bị ảnh
 * hưởng bởi state còn sót. Cược đầu set trực tiếp thay vì gọi calNextBet()
 * để không làm tăng cược ngay ở ván 1.
 */
void Player::setStrategy(unique_ptr<ABettingStrategy> new_strategy) {
    strategy = std::move(new_strategy);
    strategy->reset();
    BetType side = (rand() % 2 == 0) ? BetType::Xiu : BetType::Tai;
    current_bet = Bet(side, strategy->getBaseBet());
}

void Player::placeBet(BetResult const &prev_result) {
    if (strategy != nullptr) {
        current_bet = strategy->calNextBet(prev_result);
    }
}

Bet Player::getCurrentBet() const { return current_bet; }
