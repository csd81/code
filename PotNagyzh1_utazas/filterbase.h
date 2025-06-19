#ifndef FILTERBASE_H
#define FILTERBASE_H

template<class T>
class FilterBase
{
public:


    virtual bool match(const T &value) const =0;
    virtual ~FilterBase() {}
};

#endif // FILTERBASE_H
