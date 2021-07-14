//
// Created by liuwangbo on 2021/7/13.
//

#ifndef CPPPATTERNS_OBSERVER_H
#define CPPPATTERNS_OBSERVER_H
#include <vector>

class Observer{
public:
    // where observer get infos from subject
    virtual void update() = 0 ;
};

class ConcreteObserver: public Observer{
public:
    void update() override;

};

class Subject{
public:
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObserver() = 0;

protected:
    std::vector<Observer*> observerList;
};

class ConcreteSubject: public Subject{
    void registerObserver(Observer *observer) override;
    void removeObserver() override;
    void notifyObserver() override;
};

#endif //CPPPATTERNS_OBSERVER_H
