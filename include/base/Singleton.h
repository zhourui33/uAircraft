#ifndef _SINGLETON_H_20200705_
#define _SINGLETON_H_20200705_

template<typename T>
struct Singleton
{
    static T& getInstance()
    {
        static T instance;
        return instance;
    }
    protected:
    Singleton() {}
};

#define DEF_SINGLETON(object) struct object : Singleton<object>
#define EXTENDS(object) ,object

#endif