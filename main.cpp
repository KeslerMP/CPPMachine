#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    string name;
    float price;
    int quantity;
};

void displayMenu() {
    cout << "==== Modo Usuário ====" << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Listar produtos disponíveis" << endl;
    cout << "2. Comprar um produto" << endl;
    cout << "0. Sair" << endl;
}

void listProducts(const vector<Product>& products) {
    cout << "Produtos disponíveis:" << endl;
    for (const auto& product : products) {
        cout << product.name << " - R$" << product.price << " (Quantidade: " << product.quantity << ")" << endl;
    }
    cout << endl;
}

void buyProduct(vector<Product>& products) {
    string productName;
    float insertedAmount;

    cout << "Digite o nome do produto que deseja comprar: ";
    cin >> productName;

    auto it = find_if(products.begin(), products.end(), [&](const Product& p) {
        return p.name == productName;
    });

    if (it != products.end()) {
        Product& product = *it;
        cout << "Digite o valor inserido na máquina: R$";
        cin >> insertedAmount;

        if (insertedAmount >= product.price && product.quantity > 0) {
            product.quantity--;
            float change = insertedAmount - product.price;

            cout << "Produto " << product.name << " comprado com sucesso!" << endl;
            cout << "Troco: R$" << change << endl;
        } else {
            cout << "Valor insuficiente ou produto indisponível." << endl;
        }
    } else {
        cout << "Produto não encontrado." << endl;
    }

    cout << endl;
}

int main() {
    vector<Product> products = {
        {"Produto A", 2.5, 5},
        {"Produto B", 3.0, 3},
        {"Produto C", 4.75, 2}
    };

    int option;
    while (true) {
        displayMenu();
        cin >> option;

        switch (option) {
            case 1:
                listProducts(products);
                break;
            case 2:
                buyProduct(products);
                break;
            case 0:
                cout << "Saindo..." << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
