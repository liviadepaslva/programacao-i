#include <iostream>
#include <limits>

class Retangulo {
    public:
        Retangulo(float _altura = 1, float _largura = 1){
            altura = _altura;
            largura = _largura;
        }
        ~Retangulo(){};
        
        void setAltura(float altura) {
            this->altura = altura;
            
        }

        void setLargura(float largura) {
            this->largura = largura;
        }

        float area() const {
            return altura * largura;
        }

        float perimetro() const {
            return 2 * (altura + largura);
        }
        
    private:
        float altura, largura; 
};

int main() {
    Retangulo retangulo;
    float altura, largura;

    std::cout << "Digite a altura do retângulo: " << std::endl;
    std::cin >> altura;
    std::cout << "Digite a largura do retângulo: " << std::endl;
    std::cin >> largura;

    retangulo.setAltura(altura);
    retangulo.setLargura(largura);

    std::cout << "A área do retângulo é: " << retangulo.area() << std::endl;
    std::cout << "E o seu perímetro é: " << retangulo.perimetro() << std::endl;
    
    return 0;
}