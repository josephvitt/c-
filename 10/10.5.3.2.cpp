/*
细胞分裂模拟
*/
/*
#include <iostream>
using namespace std;
const int SPLIT_TIME_MIN = 500;//细胞分裂最短时间
const int SPLIT_TIME_MAX = 2000;//细胞分裂最长时间

class Cell;
priority_queue<Cell> cellQueue;

class Cell {//细胞类
    static int count;//细胞总数
    int id;//当前细胞编号
    int time;//细胞分裂时间
    public:
        Cell(int birth):id(count++){//id为细胞诞生的时间
            //初始化，确定细胞分裂时间
            time = birth + (rand() %(SPLIT_TIME_MAX-SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
        }
        int getId() const {return id;}//得到细胞编号
        int getSplitTime() const {return time;}//得到细胞分裂时间
        bool operator <(const Cell& s) const //"<"
        {
            return time > s.time;
        }
        void split(){//细胞分裂
            Cell child1(time),child2(time);//建立两个子细胞
            cout << time << "s:Cell #" << id << " splits to #"
                << child1.getId() << " and #" << child2.getId() << endl;
                cellQueue.top()

        }
};
int Cell::count = 0;
*/

// int main(){
//     srand(static_cast<unsigned>(time(0)));
//     int t;//模拟时间长度
//     cout << "Simulation time: ";
//     cin >> t;
//     cellQueue.push(Cell(0));//将第一个细胞艳茹优先级队列
//     while (cellQueue.top().getSplitTime() <= t)
//     {
//         cellQueue.top().split();//模拟下一个细胞的分裂
//         cellQueue.pop();//将刚刚分裂的细胞弹出
//     }
//     return 0;
// };