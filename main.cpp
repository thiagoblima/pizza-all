/**
 * @author: <thitheguy@gmail.com> Thiago Lima
 * @description: main entry for the application.
 * @version: 0.1.0
 */

#include <stdexcept>
#include <iostream>
#include <memory>
#include "pizza.h"
using namespace std;


/*
* Create all available pizzas and print their prices
*/

void pizza_information(PizzaFactory::PizzaType pizzatype)
{
    unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzatype);
    cout << "Price of " << pizzatype << " is " << pizza->getPrice() << std::endl;
}

int main()
{
    pizza_information(PizzaFactory::HamMushroom);
    pizza_information(PizzaFactory::Deluxe);
    pizza_information(PizzaFactory::Hawaiian);
}