#ifndef TOMBALAP_H
#define TOMBALAP_H

template <class Tipus>
class TombAlap
{
public:
	virtual ~TombAlap();
	virtual int meret() const = 0;
	virtual void beallit(int index, const Tipus &adat) = 0;
	virtual Tipus leker(int index) const = 0;
	virtual Tipus &elem(int index) = 0;
	virtual const Tipus &elem(int index) const = 0;
	Tipus &operator [](int index);
	const Tipus &operator [](int index) const;
};

template<class Tipus>
TombAlap<Tipus>::~TombAlap()
{
}

template<class Tipus>
Tipus &TombAlap<Tipus>::operator [](int index)
{
	return elem(index);
}

template<class Tipus>
const Tipus &TombAlap<Tipus>::operator [](int index) const
{
	return elem(index);
}

#endif // TOMBALAP_H
