#include <iostream>
#include <limits>

class Circulo {
    public:
        Circulo(float _raio = 1){
            raio = _raio;
        }
        ~Circulo(){};
        
        void setRaio(float raio) {
            this->raio = raio;
        }

        float area() const {
        return pi * (raio * raio);
        }

        float perimetro() const {
        return 2 * pi * raio;
        }
        
    private:
        float raio;
        const float pi = 3.14;
};

int main() {
    Circulo circulo;
    float raio;

    std::cout << "Digite o raio do circulo: " << std::endl;

    while (!(std::cin >> raio) || raio <= 0) {
        std::cerr << "Entrada inválida. Por favor, insira um valor positivo para o raio." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    circulo.setRaio(raio);
    std::cout << "A área do círculo é: " << circulo.area() << std::endl;
    std::cout << "E o seu perímetro é: " << circulo.perimetro() << std::endl;

    return 0;
}