#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class AbstractEntity {
public:
    virtual ~AbstractEntity() = default;
};

class AccountEntity : public AbstractEntity {
    // Специфические данные аккаунта
};

class RoleEntity : public AbstractEntity {
    // Специфические данные роли
};

class IRepository {
public:
    virtual void Save(const AbstractEntity& entity) = 0;
    virtual ~IRepository() = default;
};

class AccountRepository : public IRepository {
    public:
        void Save(const AbstractEntity& entity) override {
            try {
                const AccountEntity& account = dynamic_cast<const AccountEntity&>(entity);
                cout << "Saving AccountEntity " << endl;
            } catch (const bad_cast& e) {
                cerr << "Error: Attempted to save non-AccountEntity object " << endl;
            }
        }
    };
    
class RoleRepository : public IRepository {
    public:
        void Save(const AbstractEntity& entity) override {
            try {
                const RoleEntity& role = dynamic_cast<const RoleEntity&>(entity);
                cout << "Saving RoleEntity " << endl;
            } catch (const bad_cast& e) {
                cerr << "Error: Attempted to save non-RoleEntity object " << endl;
            }
        }
    };

int main() {
    AccountEntity account;
    RoleEntity role;

    AccountRepository accountRepo;
    RoleRepository roleRepo;

    accountRepo.Save(account);
    roleRepo.Save(role);

    roleRepo.Save(account);
    accountRepo.Save(role);

    return 0;
}
