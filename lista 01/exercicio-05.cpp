#include <iostream>

class Funcionario {
    public:
        Funcionario(std::string _nome = "Funcionário", std::string _cargo = "Cargo", float _salarioBruto = 0){
            nome = _nome;
            cargo = _cargo;
            salarioBruto = _salarioBruto;
        }
        ~Funcionario(){};

        void setNome(std::string nome) {
            this->nome = nome;
        }

        void setCargo(std::string cargo) {
            this->cargo = cargo;
        }

        void setSalarioBruto(float salarioBruto) {
            this->salarioBruto = salarioBruto;
        }

        float calcularSalario() const {
            return salarioBruto - (salarioBruto * imposto);
        }

    private:
        std::string nome;
        std::string cargo;
        float salarioBruto;
        const float imposto = 0.02;
};

int main () {
    Funcionario funcionario;
    std::string nome, cargo;
    float salarioBruto;
    int i = 1;
    
    while(i == 1) {
        std::cout << "Deseja calcular o salário de um funcionário? (1 - Sim, Digite outro número caso Não)" << std::endl;
        std::cin >> i;
        if (i == 1) {
            std::cout << "Digite o nome do funcionário: " << std::endl;
            std::cin >> nome;
            std::cout << "Digite o cargo do funcionário: " << std::endl;
            std::cin >> cargo;
            std::cout << "Digite o salário bruto do funcionário: " << std::endl;
            std::cin >> salarioBruto;

            funcionario.setNome(nome);
            funcionario.setCargo(cargo);
            funcionario.setSalarioBruto(salarioBruto);
            
            std::cout << "O salário líquido do funcionário é: " << funcionario.calcularSalario() << std::endl;
        } else {
            std::cout << "Saindo..." << std::endl;
        }
    }
   
    return 0;
}