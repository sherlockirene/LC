// 参赛者会看见三扇关闭了的门，其中一扇的后面有一辆汽车，
// 选中后面有车的那扇门可赢得该汽车，另外两扇门后面则各藏有一只山羊。
// 当参赛者选定了一扇门，但未去开启它的时候，
// 节目主持人开启剩下两扇门的其中一扇，露出其中一只山羊。
// 主持人其后会问参赛者要不要换另一扇仍然关上的门。
// 问题是：换另一扇门会否增加参赛者赢得汽车的机率？

#include <iostream>
#include <random>
using namespace std;
#define MAX_TIMES 10
class Game
{
public:
    Game(const int sums = MAX_TIMES) : sums(sums), mySelect(0), bingoCounts(0) {}
    ~Game() {}
    bool isBingo(const bool &isChange);
    void Start(const bool &isChange);
    double GetResult() { return bingoCounts * 1.0 / sums; }

private:
    int sums;
    int bingoCounts;
    int bingo;
    int mySelect;
    default_random_engine r;
};

void Game::Start(const bool &isChange)
{
    for (int i = 0; i < sums; i++)
    {
        bingo = r() % 3;
        if (isBingo(isChange))
            ++bingoCounts;
    }
}

bool Game::isBingo(const bool &isChange)
{
    mySelect = 0;
    mySelect = isChange ? mySelect = bingo == 1 ? 1 : 2 : mySelect;
    return mySelect == bingo;
}

int main()
{
    const int TIMES = 10000;
    Game gameNotChange(TIMES);
    Game gameChange(TIMES);

    gameNotChange.Start(false);
    gameChange.Start(true);

    cout << "Legend nerver die! " << gameNotChange.GetResult() << endl;//0.3346
    cout << "Life is always change! " << gameChange.GetResult() << endl;//0.6654
    return 0;
}