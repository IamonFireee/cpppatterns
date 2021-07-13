//
// Created by liuwangbo on 2021/7/12.
//

#ifndef CPPPATTERNS_DUNK_H
#define CPPPATTERNS_DUNK_H

#endif //CPPPATTERNS_DUNK_H

/*
 * 接口
 */
class FlyBehavior{
public:
    virtual void fly() = 0;
};

/*
 * 被包装好的"算法"
 */
class FlyWithWings: public FlyBehavior{
public:
    void fly();
};

class FlyNoWay: public FlyBehavior{
public:
    void fly();
};


/*
 * 接口
 */
class QuackBehavior{
public:
    virtual void quack() = 0;
};

/*
 * 被包装好的"算法"
 */
class Quack: public QuackBehavior{
public:
    void quack();
};

class Squeak: public QuackBehavior{
public:
    void quack();
};

class MuteQuack: public QuackBehavior{
public:
    void quack();
};

/*
 * main class
 */
class Dunk{
public:
    virtual void swim();
    virtual void display();

    // 策略模式相关方法
    // 使用"算法"
    virtual void performQuack();
    virtual void performFly();
    // 动态配置"算法"
    virtual void setFlyBehavior(FlyBehavior *flyBehavior);
    virtual void setQuackBehavior(QuackBehavior *quackBehavior);

private:
    FlyBehavior *flyBehavior;
    QuackBehavior *quackBehavior;
};

class MallardDuck: public Dunk{
public:
    void swim();
    void display();
};

class RedHeadDuck: public Dunk{
public:
    void swim();
    void display();
};

class RubberDuck: public Dunk{
public:
    void swim();
    void display();
};

class DecoyDuck: public Dunk{
public:
    void swim();
    void display();
};