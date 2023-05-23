#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estrutura para armazenar informações do produto
struct Product {
    string name;
    float price;
    int quantity;
};

// Função para exibir o menu de opções
void displayMenu() {
    cout << "==== Modo Usuário ====" << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Listar produtos disponíveis" << endl;
    cout << "2. Comprar um produto" << endl;
    cout << "0. Sair" << endl;
}

// Função para listar os produtos disponíveis
void listProducts(const vector<Product>& products) {
    cout << "Produtos disponíveis:" << endl;
    for (const auto& product : products) {
        cout << product.name << " - R$" << product.price << " (Quantidade: " << product.quantity << ")" << endl;
    }
    cout << endl;
}

// Função para comprar um produto
void buyProduct(vector<Product>& products) {
    string productName;
    float insertedAmount;

    cout << "Digite o nome do produto que deseja comprar: ";
    cin >> productName;

    // Procurar o produto pelo nome
    auto it = find_if(products.begin(), products.end(), [&](const Product& p) {
        return p.name == productName;
    });

    // Verificar se o produto foi encontrado
    if (it != products.end()) {
        Product& product = *it;
        cout << "Digite o valor inserido na máquina: R$";
        cin >> insertedAmount;

        // Verificar se o valor é suficiente e o produto está disponível
        if (insertedAmount >= product.price && product.quantity > 0) {
            // Atualizar a quantidade do produto e calcular o troco
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
    // Inicializar a lista de produtos
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
