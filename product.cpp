#include <iostream>
#include <string>

using namespace std;
class Product {
public:
    int price;
    Product(int price = 1) : price(price) {}
};

class IProductValidator {
public:
    virtual bool IsValid(const Product& product) const = 0;
    virtual ~IProductValidator() = default;
};

class BasicProductValidator : public IProductValidator {
public:
    bool IsValid(const Product& product) const override {
        bool valid = product.price > 0;
        cout << "Basic Product Validation: " << (valid ? "Valid" : "Invalid") << endl;
        return valid;
    }
};

class CustomerServiceProductValidator : public IProductValidator {
public:
    bool IsValid(const Product& product) const override {
        bool valid = product.price > 100000;
        cout << "Customer Service Product Validation: " << (valid ? "Valid" : "Invalid") << endl;
        return valid;
    }
};

int main() {
    Product product(100001);

    BasicProductValidator basicValidator;
    basicValidator.IsValid(product);

    CustomerServiceProductValidator csValidator;
    csValidator.IsValid(product);

    return 0;
}
