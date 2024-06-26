#include <iostream>

class Funcionario {
public:
    Funcionario(std::string _nome = "", std::string _cargo = "", double _salario = 0) {
        nome = _nome;
        cargo = _cargo;
        salario = _salario;
    }
    virtual ~Funcionario(){};

    void addAumento(double valor) {
        salario += valor;
    }

    virtual double ganhoAnual() {
        return salario * 12;
    }

    void exibirDados () {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Cargo: " << cargo << std::endl;
        std::cout << "Salário: " << salario << std::endl;
        std::cout << "Ganho Anual: " << ganhoAnual() << std::endl;
    }

protected:
    std::string nome;
    std::string cargo;
    double salario;
};

class Assistente : public Funcionario {
public:
    Assistente(std::string _nome = "", std::string _cargo = "", double _salario = 0, int _matricula = 0) : Funcionario(_nome, _cargo, _salario) {
        matricula = _matricula;
    }

    void setMatricula(int matricula) {
        this->matricula = matricula;
    }

    int getMatricula() {
        return matricula;
    }

    void exibirDados() {
        Funcionario::exibirDados();
        std::cout << "Matrícula: " << matricula << std::endl;
    }

protected:
    int matricula;
};

class Tecnico : public Assistente {
public:
    Tecnico(std::string _nome = "", std::string _cargo = "", double _salario = 0, int _matricula = 0, double _bonusSal = 0) : Assistente(_nome, _cargo, _salario, _matricula) {
        bonusSal = _bonusSal;
    }

    double ganhoAnual() override {
        salario = salario + bonusSal;
        return salario * 12;
    }

private:
    double bonusSal;
};

class Administrativo : public Assistente {
public:
    Administrativo(std::string _nome = "", std::string _cargo = "", double _salario = 0, int _matricula = 0, std::string _turno = "", double _adicionalNot = 0) : Assistente(_nome, _cargo, _salario, _matricula) {
        turno = _turno;
        adicionalNoturno = _adicionalNot;
    }

    double ganhoAnual() override {
        if (turno == "Noturno") {
            return (salario + adicionalNoturno) * 12;
        }
        return salario * 12;
    }

    void exibirDados() {
        Assistente::exibirDados();
        std::cout << "Turno: " << turno << std::endl;
        if(turno == "Noturno") {
            std::cout << "Adicional Noturno: " << adicionalNoturno << std::endl;
        }
    }

private:
    std::string turno;
    double adicionalNoturno;
};


int main() {
    int escolha = 1;

    while (escolha == 1) {
        std::cout << "Você deseja cadastrar um novo funcionário? (1 - Sim, Digite outro número para Não)" << std::endl;
        std::cin >> escolha;
        if (escolha == 1) {
            std::string nome, cargo;
            double salario;
            int matricula;

            std::cout << "Digite o nome do funcionário: ";
            std::cin >> nome;
            std::cout << "Digite o salário do funcionário: ";
            std::cin >> salario;
            std::cout << "O funcionário é um assistente? (Digite 1 caso sim, outro valor caso não)" << std::endl;
            std::cin >> cargo;
            
            if (cargo == "1") {
                cargo = "Assistente";
                std::cout << "Digite a matrícula do assistente: ";
                std::cin >> matricula;
                int tipo;
                std::cout << "Digite o tipo de assistente (1 - Técnico, 2 - Administrativo, Digite outro número se não for nenhum.): " << std::endl;
                std::cin >> tipo;

                if(tipo == 1) {
                    double bonusSal;

                    std::cout << "Digite o bônus salarial do assistente técnico: ";
                    std::cin >> bonusSal;

                    Tecnico tecnico(nome, cargo, salario, matricula, bonusSal);
                    tecnico.exibirDados();
                } else if (tipo == 2) {
                    double adicionalNoturno;
                    std::string turno;

                    std::cout << "Digite o turno do assistente administrativo (\"D\" Diurno ou \"N\" Noturno): " << std::endl;
                    std::cin >> turno;
                    if (turno == "N" || turno == "n") {
                        turno = "Noturno";
                        std::cout << "Digite o adicional noturno do assistente administrativo: ";
                        std::cin >> adicionalNoturno;
                    }
                    else if (turno == "D" || turno == "d") {
                        turno = "Diurno";
                        adicionalNoturno = 0;
                    }
                    Administrativo administrativo(nome, cargo, salario, matricula, turno, adicionalNoturno);
                    administrativo.exibirDados();
                } else {
                    Assistente assistente(nome, cargo, salario);
                    assistente.exibirDados();
                }
            } else  {
                std::cout << "Qual o cargo do funcionário?";
                std::cin >> cargo;
                Funcionario funcionario(nome, cargo, salario);
                funcionario.exibirDados();
            }
        }
        else {
            std::cout << "Saindo...";
        }
    }

    return 0;
}