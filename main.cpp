//Vending MachineUm  empresa  construiu  uma  m ́aquina  capaz  de  automatizar  a  venda  de  itens  aliment ́ıciosb ́asicos,  ou  seja,  o  consumidor  seleciona  o  produto  desejado,  insere  o  dinheiro  na  m ́aquina  erecebe o produto e o troco se houver.  Uma imagem da m ́aquina pode ser vista a seguir.1
//A empresa precisa de um programa de computador para automatizar o funcionameto dessam ́aquina, sendo assim, ela contactou os alunos 1o.  semestre do curso de An ́alise e Desenvolvimentode Sistemas da Fatec Ribeir ̃ao Preto que s ̃ao conhecidos pela sua excelˆencia, capacidade e talento.Portanto, o programa de computador deve simular o funcionamento da m ́aquina em dois modos,a saber:(a)  ModoUsu ́ario: onde os produtos armazenados na m ́aquina s ̃ao listados com seus respectivosvalores sendo que o usu ́ario pode escolher qual produto quer comprar, e em seguida informao  valor  inserido  na  m ́aquina.   Ap ́os  o  processamento,  caso  o  produto  esteja  dispon ́ıvel,  ousu ́ario “retira” o produto, bem como seu troco que  ́e informado ao usu ́ario.(b)  ModoAdministrador: onde  ́e poss ́ıvel gerenciar a m ́aquina repondo produtos faltantes, listarum  invent ́ario  de  produtos  e  suas  respectivas  quantidades  e  listar  o  quanto  a  m ́aquina  j ́afaturou e ainda pode faturar.Este s ̃ao os requisitos b ́asicos para que a empresa aceite avaliar seu projeto, mas vocˆe  ́e livrepara implementar novas funcionalidades e outras formas de visualizar as informa ̧c ̃oes a medidaque for completando seu projeto.

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
    cout << "==== Modo Usuário ====" << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Listar produtos disponíveis" << endl;
    cout << "2. Comprar um produto" << endl;
    cout << "3. Modo Administrador (Admin only)" << endl;
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
    cout << "Digite o preço do produto: ";
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
            cout << "Selecione uma opção:" << endl;
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
        { "Guaraná", 3.5f, 5 },
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
