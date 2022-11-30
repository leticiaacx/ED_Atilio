#include <iostream>

// Recebe tempo em 'segundos', converte para horas, minutos e segundos, e 
// retorna o resultado através dos parâmetros 'hor', 'min' e 'seg'.
void converte_tempo(int segundos, int *hor, int *min, int *seg) {
    if(segundos < 1){
        *hor = 0;
        *min = 0;
        *seg = 0;
    } else{
        *min = segundos/60;
        *seg = segundos%60;
        *hor = *min/60;
        *min = *min%60;
    }
}

int main() {
   int tempo, h, m, s;
   std::cin >> tempo;
   // Chame a função 'converte_tempo' para converter o valor de 'tempo' em horas
   // minutos e segundos, gravando o resultado nas variáveis 'h', 'm' e 's'.
   converte_tempo(tempo, &h, &m, &s);
   std::cout << h << ":" << m << ":" << s;
   return 0;
}