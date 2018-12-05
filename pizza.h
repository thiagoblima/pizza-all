/**
 * @author: <thitheguy@gmail.com> Thiago Lima
 * @class: { HamAndMushroomPizza, DeluxePizza, HawaiianPizza, PizzaFactory }
 * @description: pizza header, responsible for classes and instances of object
 * to be used in the application.
 * @version: 0.1.0
 */



#ifndef PIZZAALL_PIZAA_H
#define PIZZAALL_PIZAA_H

class Pizza {
public:
    virtual int getPrice() const = 0;
    virtual ~Pizza() {};  /* without this, no destructor for derived Pizza's will be called. */
};

class HamAndMushroomPizza : public Pizza {
public:
    virtual int getPrice() const { return 850; };
    virtual ~HamAndMushroomPizza() {};
};

class DeluxePizza : public Pizza {
public:
    virtual int getPrice() const { return 1050; };
    virtual ~DeluxePizza() {};
};

class HawaiianPizza : public Pizza {
public:
    virtual int getPrice() const { return 1150; };
    virtual ~HawaiianPizza() {};
};

class PizzaFactory {
public:
    enum PizzaType {
        HamMushroom,
        Deluxe,
        Hawaiian
    };

    static std::unique_ptr<Pizza> createPizza(PizzaType pizzaType) {
        switch (pizzaType) {
            case HamMushroom: return make_unique<HamAndMushroomPizza>();
            case Deluxe:      return make_unique<DeluxePizza>();
            case Hawaiian:    return make_unique<HawaiianPizza>();
        }
        throw "invalid pizza type.";
    }
};

#endif //PIZZAALL_PIZAA_H
