/*!
 * \file    Functor.hpp
 * \brief   Implementation of Functor class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 6, 2010 12:43 PM
 */

#ifndef _FUNCTOR_HPP
#define	_FUNCTOR_HPP

template<typename Class, typename RetType, typename Param1 = void, typename Param2 = void>
class Functor {
public:
    typedef RetType (Class::*Method)(Param1, Param2);

    Functor(Class& instance, Method meth);
    virtual ~Functor();
    RetType operator()(Param1 arg1, Param2 arg2);
    RetType call(Param1 arg1, Param2 arg2);

private:
    Class& instance_;
    Method method_;
};


template<typename Class, typename RetType, typename Param1>
class Functor<Class, RetType, Param1> {
public:
    typedef RetType (Class::*Method)(Param1);
    
    Functor(Class& instance, Method meth);
    virtual ~Functor();
    RetType operator()(Param1 arg);
    RetType call(Param1 arg);

private:
    Class& instance_;
    Method method_;
};

template<typename Class, typename RetType>
class Functor<Class, RetType> {
public:
    typedef RetType (Class::*Method)(void);

    Functor(Class& instance, Method meth);
    virtual ~Functor();
    RetType operator()(void);
    RetType call(void);

private:
    Class& instance_;
    Method method_;
};


template<typename Class, typename RetType, typename Param1, typename Param2>
Functor<Class, RetType, Param1, Param2>::Functor(Class& instance, Method meth)
: instance_(instance), method_(meth) {
}

template<typename Class, typename RetType, typename Param1, typename Param2>
Functor<Class, RetType, Param1, Param2>::~Functor() {
}

template<typename Class, typename RetType, typename Param1, typename Param2>
RetType Functor<Class, RetType, Param1, Param2>::operator ()(Param1 arg1, Param2 arg2)
{
    return (instance_.*method_)(arg1, arg2);
}

template<typename Class, typename RetType, typename Param1, typename Param2>
RetType Functor<Class, RetType, Param1, Param2>::call(Param1 arg1, Param2 arg2)
{
    return (instance_.*method_)(arg1, arg2);
}


template<typename Class, typename RetType, typename Param1>
Functor<Class, RetType, Param1>::Functor(Class& instance, Method meth)
: instance_(instance), method_(meth) {
}

template<typename Class, typename RetType, typename Param1>
Functor<Class, RetType, Param1>::~Functor() {
}

template<typename Class, typename RetType, typename Param1>
RetType Functor<Class, RetType, Param1>::operator ()(Param1 arg)
{
    return (instance_.*method_)(arg);
}

template<typename Class, typename RetType, typename Param1>
RetType Functor<Class, RetType, Param1>::call(Param1 arg)
{
    return (instance_.*method_)(arg);
}

template<typename Class, typename RetType>
Functor<Class, RetType>::Functor(Class& instance, Method meth)
: instance_(instance), method_(meth) {
}

template<typename Class, typename RetType>
Functor<Class, RetType>::~Functor() {
}

template<typename Class, typename RetType>
RetType Functor<Class, RetType>::operator ()()
{
    return (instance_.*method_)();
}

template<typename Class, typename RetType>
RetType Functor<Class, RetType>::call()
{
    return (instance_.*method_)();
}

#endif	/* _FUNCTOR_HPP */
