#ifndef TOMBALAP_H
#define TOMBALAP_H

template <class Tipus>
class TombAlap
{
public:
    virtual int meret() const =0;
    virtual void beallit(int index, const Tipus &ertek) =0;
    virtual Tipus leker(int index) const =0;
    virtual Tipus &operator[](int index) =0;
    virtual const Tipus &operator[](int index) const =0;
    virtual Tipus &elem(int index) =0;
    virtual const Tipus &elem(int index) const =0;

    virtual ~TombAlap() = default;
};

#endif // TOMBALAP_H
