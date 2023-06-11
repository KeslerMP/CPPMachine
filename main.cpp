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

float profit = 0;

//Função onde mostra o lucro que a maquina deu e ainda pode dar com os produtos disponiveis no vetor
void showProfit(vector<Product>& products) {

    float capacity = 0;
    for (const auto& product : products) {
        capacity += product.price * product.quantity;
    }

    cout << "Capacidade de rendimento: R$" << capacity << endl;
    cout << "Seu rendimento foi de R$" << profit << endl;
    cout << endl;
}

//Função onde da display ao menu para o usuario
void displayMenu() {
    cout << "==== Modo Usuario ====" << endl;
    cout << "Selecione uma opcao:" << endl;
    cout << "1. Listar produtos disponiveis" << endl;
    cout << "2. Comprar um produto" << endl;
    cout << "3. Modo Administrador (Admin only)" << endl;
    cout << "0. Sair" << endl;
}

//Função para a listagem de produtos contidos no vetor
void listProducts(const vector<Product>& products) {
    cout << "Produtos disponiveis:" << endl;
    for (const auto& product : products) {
        cout << product.name << " - R$" << product.price << " (Quantidade: " << product.quantity << ")" << endl;
    }
    cout << endl;
}

//Função feita para o usuario comprar os produtos disponiveis na maquina
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
            profit = product.price++;

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

//Função para o admin modificar a quantidade de produtos disponiveis na maquina
void changeQuantity(vector<Product>& products){
    string productName;
    int productQuantity;

    cout << "Digite o nome do produto: ";
    cin >> productName;
    cout << "Digite a nova quantidade do produto: ";
    cin >> productQuantity;

    auto it = find_if(products.begin(), products.end(), [&](const Product& p) {
        return p.name == productName;
    });

    if (it != products.end()) {
        Product& product = *it;
        product.quantity = productQuantity;
        cout << "Quantidade alterada com sucesso!" << endl;
    } else {
        cout << "Produto nao encontrado." << endl;
    }

    cout << endl;
}

//função para o admin remover os produtos contidos na maquina
void removeProduct(vector<Product>& products) {
    string productName;

    cout << "Digite o nome do produto: ";
    cin >> productName;

    auto it = find_if(products.begin(), products.end(), [&](const Product& p) {
        return p.name == productName;
    });

    if (it != products.end()) {
        Product& product = *it;
        products.erase(it);
        cout << "Produto " << product.name << " removido com sucesso!" << endl;
    } else {
        cout << "Produto nao encontrado." << endl;
    }

    cout << endl;
}

//Função para o admin adcionar produtos novos ao vetor de produtos
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

//Função para mostrar o menu admistrativo da maquina
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
                    removeProduct(products);
                    break;
                case 4:
                    cout << "Alterar quantidade de produto" << endl;
                    changeQuantity(products);
                    break;
                case 5:
                    cout << "Listar faturamento" << endl;
                    showProfit(products);
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


//Função main do projeto onde é o menu do usuário
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
