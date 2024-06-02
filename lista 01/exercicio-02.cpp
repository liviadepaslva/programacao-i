#include <iostream>

class ContaBancaria {
    public:
        ContaBancaria(float _saldo = 0){
            saldo = _saldo;
        }
        ~ContaBancaria(){};
        
        void setSaldo(float saldo) {
            this->saldo = saldo;
        }

        void depositar(float valor) {
            saldo += valor;
        }

        void sacar(float valor) {
            if (valor > saldo) {
                std::cerr << "Saldo insuficiente." << std::endl;
                return;
            }
            saldo -= valor;
        }

        float getSaldo() const {
            return saldo;
        }
        
    private:
        float saldo;
};

int main() {
    ContaBancaria conta;
    float valor;
    int numeroConta;
    std::string nomeTitular;

    std::cout << "Digite o nome do titular da conta: " << std::endl;
    std::cin >> nomeTitular;
    std::cout << "Digite o número da conta: " << std::endl;
    std::cin >> numeroConta;

    int escolha = 1;

    do {
        std::cout << "Digite 1 para depositar, 2 para sacar, 3 para consultar saldo ou outro número para sair." << std::endl;
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                std::cout << "Digite o valor a ser depositado: " << std::endl;
                std::cin >> valor;
                conta.depositar(valor);
                break;
            case 2:
                std::cout << "Digite o valor a ser sacado: " << std::endl;
                std::cin >> valor;
                conta.sacar(valor);
                break;
            case 3:
                std::cout << "O saldo da conta é: " << conta.getSaldo() << std::endl;
                break;
            default:
                escolha = 0;
                std::cerr << "Saindo..." << std::endl;
                break;
        }
    } while (escolha != 0);
    
    return 0;
}