#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
//储蓄账户类
class SavingAccount{
    private:
        int id;//账号
        double balance;//余额
        double rate;//存款的年利率
        int lastDate;//上次变更余额的日期
        double accumulation;//余额按日累加之和
        static double total;//所有账户的总金额

        //记录一笔帐，date为日期，amount为金额，desc为说明
        void record(int date,double amount);
        //获得到指定日期为止的存款金额按日累积值
        double accumulate(int date) const {
            return accumulation + balance * (date-lastDate);
        }
    public:
        //构造函数
        SavingAccount(int date,int id,double rate);
        int getId(){return id;}
        double getBalance(){return balance;}
        double getRate(){return rate;}

        //存入现金
        void deposit(int date,double amount);
        //取出现金
        void withdraw(int date,double amount);
        //结算利息，每年1月1日调用一次该函数
        void settle(int date);
        //显示账户信息
        void show();

        static double getTotal(){
            return total;
        }
};
#endif//_ACCOUNT_H_