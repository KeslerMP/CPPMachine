#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    string name;
    float price;
    int quantity;
};

void displayMenu() {
    cout << "==== Modo Usuario ====" << endl;
    cout << "Selecione uma opcao:" << endl;
    cout << "1. Listar produtos disponiveis" << endl;
    cout << "2. Comprar um produto" << endl;
    cout << "3. Modo Administrador (Admin only)" << endl;
    cout << "0. Sair" << endl;
}

void listProducts(const vector<Product>& products) {
    cout << "Produtos disponiveis:" << endl;
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
        cout << "Digite o valor inserido na maquina: R$";
        cin >> insertedAmount;

        if (insertedAmount >= product.price && product.quantity > 0) {
            product.quantity--;
            float change = insertedAmount - product.price;

            cout << "Produto " << product.name << " comprado com sucesso!" << endl;
            cout << "Troco: R$" << change << endl;
        } else {
            cout << "Valor insuficiente ou produto indisponivel." << endl;
        }
    } else {
        cout << "Produto nao encontrado." << endl;
    }

    cout << endl;
}

void addProduct(vector<Product>& products) {
    string productName;
    float productPrice;
    int productQuantity;

    cout << "Digite o nome do produto: ";
    cin >> productName;
    cout << "Digite o preco do produto: ";
    cin >> productPrice;
    cout << "Digite a quantidade do produto: ";
    cin >> productQuantity;

    products.push_back({ productName, productPrice, productQuantity });
}

void adminMode (vector<Product>& products) {
    int senha;
    cout << "Digite a senha: ";
    cin >> senha;

    if (senha != 1234) {
        cout << "Senha incorreta." << endl;
        return;
    }else{
        int option;
        do {
            cout << "==== Modo Administrador ====" << endl;
            cout << "Selecione uma opcao:" << endl;
            cout << "1. Listar produtos e quantidades" << endl;
            cout << "2. Adicionar produto" << endl;
            cout << "3. Remover produto" << endl;
            cout << "4. Alterar quantidade de produto" << endl;
            cout << "5. Listar faturamento" << endl;
            cout << "0. Voltar" << endl;
            cin >> option;

            switch (option) {
                case 1:
                    listProducts(products);
                    break;
                case 2:
                    cout << "Adicionar produto" << endl;
                    addProduct(products);
                    break;
                case 3:
                    cout << "Remover produto" << endl;
                    break;
                case 4:
                    cout << "Alterar quantidade de produto" << endl;
                    break;
                case 5:
                    cout << "Listar faturamento" << endl;
                    break;
                case 0:
                    cout << "Voltando..." << endl;
                    break;
                default:
                    cout << "Opcao invalida." << endl;
                    break;
            }
        } while (option != 0);
    }
}

int main() {
    vector<Product> products = {
        { "Coca-Cola", 4.5f, 5 },
        { "Pepsi", 4.0f, 5 },
        { "Guarana", 3.5f, 5 },
        { "Fanta", 3.0f, 5 },
        { "Agua", 2.5f, 5 },
        { "Suco", 2.0f, 5 },
        { "Chocolate", 1.5f, 5 },
        { "Salgadinho", 1.0f, 5 },
    };

    int option;
    do {
        displayMenu();
        cin >> option;

        switch (option) {
            case 1:
                listProducts(products);
                break;
            case 2:
                buyProduct(products);
                break;
            case 3:
                cout << "Modo Administrador" << endl;
                adminMode(products);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
        }
    } while (option != 0);

    return 0;
}
