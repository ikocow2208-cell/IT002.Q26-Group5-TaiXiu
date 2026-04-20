#include "../include/Player.h"

/* *
 * @brief Khởi tạo đối tượng Player với số dư ban đầu.
 * @param initial_balance Số tiền ban đầu trong tài khoản của người chơi.
 * @return None Không có.
 * */
Player::Player(double initial_balance) : current_bet(BetType::Xiu, 0.0)
{
    setBalance(initial_balance);
    strategy = nullptr;
}

/* *
 * @brief Thiết lập chiến thuật đặt cược mới cho người chơi.
 * @param newStrategy Con trỏ thông minh (unique_ptr) quản lý chiến thuật mới.
 * @return void Không trả về giá trị.
 * */
void Player::setStrategy(unique_ptr<ABettingStrategy> newStrategy)
{
    strategy = std::move(newStrategy);
}

/* *
 * @brief Thực hiện đặt cược cho lượt tiếp theo dựa trên kết quả trước đó.
 * @param prev_result Kết quả của lượt cược vừa diễn ra.
 * @return void Không trả về giá trị.
 * */
void Player::placeBet(BetResult const &prev_result)
{
    if (strategy != nullptr)
    {
        current_bet = strategy->calNextBet(prev_result);
    }
}

/* *
 * @brief Lấy thông tin về lượt cược hiện tại của người chơi.
 * @param Không có tham số.
 * @return Bet Đối tượng Bet chứa cửa đặt và số tiền cược hiện tại.
 * */
Bet Player::getCurrentBet() const { return current_bet; }
