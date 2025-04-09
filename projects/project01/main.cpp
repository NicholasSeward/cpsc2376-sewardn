

#include <iostream>
#include <vector>
#include <stdexcept>





enum class Cell{BLANK, X, O};
enum class GameStatus{ONGOING, X_WON, O_WON, DRAW};

bool isFull(const std::vector<std::vector<Cell>>& board)
{
    for (auto& row : board)
        for (auto& cell : row)
            if (cell == Cell::BLANK)
                return false;
    return true;
}

GameStatus getGameStatus(const std::vector<std::vector<Cell>>& board)
{
    int size = board.size();
    for (int row{ 0 };row<size;row++)
        for (int col{ 0 }; col < size; col++)
        {
            //horizontal win
            if (board.at(row).at(col) != Cell::BLANK && col < size - 4)
            {
                auto token{ board.at(row).at(col) };
                bool isWinner = true;
                for (int i{ 1 }; i < 5; i++)
                {
                    if (board.at(row).at(col + i) != token)
                    {
                        isWinner = false;
                        break;

                    }
                }
                if (isWinner)return static_cast<GameStatus>(token);
            }
            //vertical win
            if (board.at(row).at(col) != Cell::BLANK && row < size - 4)
            {
                auto token{ board.at(row).at(col) };
                bool isWinner = true;
                for (int i{ 1 }; i < 5; i++)
                {
                    if (board.at(row + i).at(col) != token)
                    {
                        isWinner = false;
                        break;

                    }
                }
                if (isWinner)return static_cast<GameStatus>(token);
            }
        //    //diagonal \ win
        //    if (board.at(row).at(col) != Cell::BLANK && row < size - 4 && col<size-4)
        //    {
        //        auto token{ board.at(row).at(col) };
        //        bool isWinner = true;
        //        for (int i{ 1 }; i < 5; i++)
        //        {
        //            if (board.at(row + i).at(col+i) != token)
        //            {
        //                isWinner = false;
        //                break;

        //            }
        //        }
        //        if (isWinner)return static_cast<GameStatus>(token);
        //    }
        //    //diagonal / win
        //    if (board.at(row+4).at(col) != Cell::BLANK && row < size - 4 && col < size - 4)
        //    {
        //        auto token{ board.at(row+4).at(col) };
        //        bool isWinner = true;
        //        for (int i{ 1 }; i < 5; i++)
        //        {
        //            if (board.at(row +4- i).at(col + i) != token)
        //            {
        //                isWinner = false;
        //                break;

        //            }
        //        }
        //        if (isWinner)return static_cast<GameStatus>(token);
        //    }
        }

    if(isFull(board))return GameStatus::DRAW;
    return GameStatus::ONGOING;
}

std::vector<std::vector<Cell>> makeBoard(int size=7)
{
    std::vector<std::vector<Cell>> board(size, std::vector<Cell>(size, Cell::BLANK));
    return board;
}

void printBoard(const std::vector<std::vector<Cell>>& board)
{
    int size = board.size();

    // ANSI color codes
    const std::string RED = "\033[31m";    // Red for X
    const std::string GREEN = "\033[32m";  // Green for O
    const std::string WHITE = "\033[37m";  // White for board
    const std::string RESET = "\033[0m";   // Reset to default

    // Print column numbers
    std::cout << WHITE << "   ";
    for (int col = 1; col <= size; ++col)
        std::cout << " " << col << "  ";
    std::cout << RESET << "\n";

    // Build the divider string dynamically
    std::string divider = WHITE + "  +";
    for (int i = 0; i < size; ++i)
        divider += "---+";

    // Print top border
    std::cout << divider << RESET << "\n";

    for (int row = 0; row < size; ++row)
    {
        // Print row number
        std::cout << WHITE << row + 1 << " |" << RESET;

        for (int col = 0; col < size; ++col)
        {
            if (board[row][col] == Cell::X)
                std::cout << RED << " X " << WHITE;
            else if (board[row][col] == Cell::O)
                std::cout << GREEN << " O " << WHITE;
            else
                std::cout << "   ";

            std::cout << "|";
        }
        std::cout << RESET << "\n";

        // Print row separator
        std::cout << divider << RESET << "\n";
    }
}

Cell getCurrentPlayer(std::vector<std::vector<Cell>>& board)
{
    int count{ 0 };
    for (auto& row : board)
        for (auto elem : row)
            if (elem != Cell::BLANK)count++;
    if (count % 2 == 0)return Cell::X;
    return Cell::O;
}


bool play(std::vector<std::vector<Cell>>& board, int row, int col)
{
    Cell token = getCurrentPlayer(board);
    int height= board.size() ;
    if (height == 0)throw std::invalid_argument("height of board must be positive");

    int width=board.at(0).size();


    if (row < 0 || row >= height || col < 0 || col >= width) return false;
    Cell& cell{ board.at(row).at(col) };
    
    if (cell != Cell::BLANK) return false;

    cell = token;
}

int main()
{
    auto board = makeBoard();
    
    while (getGameStatus(board)==GameStatus::ONGOING)
    {
        printBoard(board);
        if(getCurrentPlayer(board)==Cell::X)
            std::cout << "Player X's turn\n";
        else
            std::cout << "Player O's turn\n";
        std::cout << "row: ";
        int row;
        std::cin >> row;
        std::cout << "col: ";
        int col;
        std::cin >> col;
        bool isGood{ play(board,row-1,col-1) };
        if (!isGood) std::cout << "baddddd input";
    }
    printBoard(board);
    switch (getGameStatus(board))
    {
    case GameStatus::X_WON:
        std::cout << "X WON\n";
        break;
    case GameStatus::O_WON:
        std::cout << "O WON\n";
        break;
    }

    
}
