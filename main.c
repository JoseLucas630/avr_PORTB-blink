#include <avr/io.h>   //inclui funçoes basicas para o gerenciamento de portas e registros
#include <util/delay.h>   //inclui a funçao de delay, dada em milissegundos

#define F_CPU 16000000    //define a frequencia da cpu para 16000000 de hz, equivalente a 16mhz
#define delaytime 20000   /*define o tempo de delay como 20000ms, note que isso é equivalente a 2 minutos
devido a problemas no meu microcontrolador*/

void PORTT2 (void);
void PORTT3 (void);

int main (void)
{
    DDRB = (1 << PB2) | (1 << PB3);   /*seleciona a portb2 e portb3 como entrada usando
                                       data direction register (DDRB)*/
    while(1)
    {
       PORTT2();                 //inclui a funçao PORTT2 que pode ser vista abaixo
       PORTT3();                 //inclui a funçao PORTT3 que pode ser vista abaixo
    }
    return 0;
}

void PORTT2 (void)
{
    PORTB = PORTB | (1 << PB2);      //ja que o DDRB esta selecionada para a porta B, ligamos a portb2 usando operadores logicos
    _delay_ms(delaytime);            //aplica o delaytime ao led
    PORTB = (0 << PB2);              //usa operadores logicos para retirar a seleçao da portb2 e desliga-la
    _delay_ms(delaytime);            //aplica novamente o delay ao led
   
}

void PORTT3 (void)                   //faz o mesmo que a funçao PORTT2, mas com a portb3
{
    PORTB = PORTB | (1 << PB3); 
    _delay_ms(delaytime);
    PORTB = (0 << PB3);
    _delay_ms(delaytime);
}
