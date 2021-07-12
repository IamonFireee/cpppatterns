//
// Created by liuwangbo on 2021/7/12.
//

#ifndef CPPPATTERNS_DUNK_H
#define CPPPATTERNS_DUNK_H

#endif //CPPPATTERNS_DUNK_H

/*
 * interface
 */
class FlyBehavior{
public:
    virtual void fly() = 0;
};

class FlyWithWings: public FlyBehavior{

};

class FlyNoWay: public FlyBehavior{

};


/*
 * interface
 */
class QuackBehavior{
public:
    virtual void quack() = 0;
};

class Quack: public QuackBehavior{

};

class Squeak: public QuackBehavior{

};

class MuteQuack: public QuackBehavior{

};

/*
 * main class
 */
class Dunk{
public:
    virtual void swim();
    virtual void display();
    virtual void performQuack();
    virtual void performFly();
    virtual void setFlyBehavior();
    virtual void setQuackBehavior();
};

class MallardDuck: public Dunk{

};

class RedHeadDuck: public Dunk{

};

class RubberDuck: public Dunk{

};

class DecoyDuck: public Dunk{

};