#include <iostream>

class Aluno {
    public:
        Aluno(std::string _nome = "Aluno", int _matricula = 0){
            nomeAluno = _nome;
            matricula = _matricula;
        }
        ~Aluno(){};
        
        void setNomeAluno(std::string nomeAluno) {
            this->nomeAluno = nomeAluno;
        }

        void setMatricula(int matricula) {
            this->matricula = matricula;
        }

        void setNotas() {
            float nota;
            for (int i = 0; i < 3; i++) {
                std::cout << "Digite a nota " << i + 1 << ": " << std::endl;
                std::cin >> nota;
                notas[i] = nota;
            }
        }

        float media() const {
            float soma = 0;
            for (int i = 0; i < 3; i++) {
                soma += notas[i];
            }
            return soma / 3;
        }

        void verificarAprovacao (float media) const {
            if (media >= 7) {
                std::cout << "Aprovado." << std::endl;
            } else {
                std::cout << "Reprovado." << std::endl;
            }
        }

    private:
        std::string nomeAluno;
        int matricula;
        float notas[3];
};

int main () {
    Aluno aluno;
    std::string nomeAluno;
    int matricula;    
    
    std::cout << "Digite o nome do aluno: " << std::endl;
    std::cin >> nomeAluno;
    std::cout << "Digite a matrícula do aluno: " << std::endl;
    std::cin >> matricula;

    aluno.setNomeAluno(nomeAluno);
    aluno.setMatricula(matricula);
    aluno.setNotas();

    std::cout << "A média do aluno " << nomeAluno << " é: " << aluno.media() << std::endl;
    aluno.verificarAprovacao(aluno.media());
    return 0;
}