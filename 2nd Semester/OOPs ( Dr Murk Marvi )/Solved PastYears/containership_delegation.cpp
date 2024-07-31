/* 
    Containership (also known as Composition) is a design principle where a class contains objects of
other classes to achieve its functionalities. This is often represented as a "has-a" relationship.
    Delegation is a design pattern where an object handles a request by delegating it to a second
object (the delegate). This is useful for achieving behavior reuse and making the code more flexible.
Here Delegation is seen in how the ShoppingMart class handles the payment process. 
Specifically, ShoppingMart delegates the responsibility of making the payment to an instance of 
a class that implements the PaymentMethod interface.    */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product(const string& name, double price) : name(name), price(price) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

class PaymentMethod {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }
};

class CreditCard : public PaymentMethod {
private:
    BankAccount& bankAccount; // Composition

public:
    CreditCard(BankAccount& account) : bankAccount(account) {}

    void pay(double amount) override {
        if (bankAccount.withdraw(amount)) 
            cout << "Payment of " << amount << " made using Credit Card.\n";
        else 
            cout << "Insufficient funds for Credit Card payment.\n";
    }
};

class PayPal : public PaymentMethod {
private:
    BankAccount& bankAccount; // Composition

public:
    PayPal(BankAccount& account) : bankAccount(account) {}

    void pay(double amount) override {
        if (bankAccount.withdraw(amount)) 
            cout << "Payment of " << amount << " made using PayPal.\n";
        else 
            cout << "Insufficient funds for PayPal payment.\n";
        
    }
};

class Cart {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    double getTotalAmount() const {
        double total = 0;
        for (const auto& product : products) {
            total += product.getPrice();
        }
        return total;
    }

    void displayCart() const {
        cout << "Cart contents:\n";
        for (const auto& product : products) {
            cout << product.getName() << " - $" << product.getPrice() << "\n";
        }
        cout << "Total: $" << getTotalAmount() << "\n";
    }
};

class ShoppingMart {
private:
    Cart cart;
    PaymentMethod* paymentMethod;

public:
    void selectPaymentMethod(PaymentMethod* method) {
        paymentMethod = method;
    }

    void addProductToCart(const Product& product) {
        cart.addProduct(product);
    }

    void checkout() {
        cart.displayCart();
        if (paymentMethod) 
            paymentMethod->pay(cart.getTotalAmount());
        else 
            cout << "No payment method selected.\n";
    }
};

int main() {
    BankAccount account(50000);

    CreditCard creditCard(account);
    PayPal paypal(account);

    ShoppingMart mart;

    mart.addProductToCart(Product("Laptop", 37000));
    mart.addProductToCart(Product("Headphones", 500));

    mart.selectPaymentMethod(&creditCard);
    mart.checkout();

    mart.addProductToCart(Product("Mouse", 120));
    mart.addProductToCart(Product("Keyboard", 300));

    mart.selectPaymentMethod(&paypal);
    mart.checkout();

    return 0;
}
