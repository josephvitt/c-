/*
委托构造函数,c++11新标准;
当重载构造函数的时候,往往是形参表不同,初始化列表不同,其他都是一样的,如果写多个函数体来重载往往就显得重复了
回顾:
Clock类的两个构造函数
//构造函数
Clock::Clock(int newH,int newM,int newS):
    hour(newH),minute(newM),second(newS){
}

//默认构造函数
Clock::Clock():hour(0),minute(0),second(0){}

1.委托构造函数使用类的其他构造函数执行初始化的过程
有点像java中的this()

*/
