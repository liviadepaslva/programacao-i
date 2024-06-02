#include <iostream>
#include <string>

class Funcionario {
protected:
    std::string nome;
    double salario;

public:
    Funcionario(const std::string& nome, double salario)
        : nome(nome), salario(salario) {}

    void addAumento(double valor) {
        salario += valor;
    }

    double ganhoAnual() {
        return salario * 12;
    }

    void exibeDados() {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Salario: " << salario << std::endl;
    }
};

class Assistente : public Funcionario {
private:
    int matricula;

public:
    Assistente(const std::string& nome, double salario, int matricula)
        : Funcionario(nome, salario), matricula(matricula) {}

    void exibeDados() {
        Funcionario::exibeDados();
        std::cout << "Matricula: " << matricula << std::endl;
    }
};

class Tecnico : public Assistente {
private:
    double bonusSalarial;

public:
    Tecnico(const std::string& nome, double salario, int matricula, double bonusSalarial)
        : Assistente(nome, salario, matricula), bonusSalarial(bonusSalarial) {}

    double ganhoAnual() {
        return (salario + bonusSalarial) * 12;
    }
};

class Administrativo : public Assistente {
private:
    std::string turno;
    double adicionalNoturno;

public:
    Administrativo(const std::string& nome, double salario, int matricula, const std::string& turno, double adicionalNoturno)
        : Assistente(nome, salario, matricula), turno(turno), adicionalNoturno(adicionalNoturno) {}

    double ganhoAnual() {
        return (salario + adicionalNoturno) * 12;
    }
};

int main() {
    // Example usage
    Funcionario funcionario("Joao", 2000.0);
    funcionario.addAumento(500.0);
    funcionario.exibeDados();
    std::cout << "Ganho Anual: " << funcionario.ganhoAnual() << std::endl;

    Assistente assistente("Maria", 2500.0, 12345);
    assistente.addAumento(700.0);
    assistente.exibeDados();
    std::cout << "Ganho Anual: " << assistente.ganhoAnual() << std::endl;

    Tecnico tecnico("Pedro", 3000.0, 54321, 1000.0);
    tecnico.addAumento(800.0);
    tecnico.exibeDados();
    std::cout << "Ganho Anual: " << tecnico.ganhoAnual() << std::endl;

    Administrativo administrativo("Ana", 2800.0, 98765, "dia", 500.0);
    administrativo.addAumento(600.0);
    administrativo.exibeDados();
    std::cout << "Ganho Anual: " << administrativo.ganhoAnual() << std::endl;

    return 0;
}
