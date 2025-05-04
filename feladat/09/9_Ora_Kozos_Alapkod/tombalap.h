template<typename T>
class TombAlap {
public:
    virtual ~TombAlap() {}

    virtual int meret() const = 0;
    virtual void beallit(int index, const T& ertek) = 0;
    virtual T leker(int index) const = 0;
    virtual T& elem(int index) = 0;
    virtual const T& elem(int index) const = 0;


    T& operator[](int index) {
        return elem(index);
    }

    const T& operator[](int index) const {
        return elem(index);
    }

};
