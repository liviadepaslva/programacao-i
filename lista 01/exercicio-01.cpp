#include <iostream>

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
    std::cin >> raio;

    circulo.setRaio(raio);
    std::cout << "A área do círculo é: " << circulo.area() << std::endl;
    std::cout << "E o seu perímetro é: " << circulo.perimetro() << std::endl;

    return 0;
}