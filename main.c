#include <stdio.h>
#include "andre.h"
// Fonte: Sindifisco/RS
// Bandeira verde: A tarifa não sofre nenhum acréscimo.
// Bandeira amarela: Acréscimo de R$ 1,34 por 100 kWh consumidos.
// Bandeira vermelha - Patamar 1: Acréscimo de R$ 4,16 por 100 kWh consumidos.
// Bandeira vermelha - Patamar 2: Acréscimo de R$ 6,24 para cada 100 kWh.

int main() {
	
    int qtd_kWh=188;
    float valor_TUSD_kWh=0.48489362;
    float valor_TE_kWh=0.42276596;
    float outros=9.2; 
    float total_a_pagar = 0.0;
    char bandeira='A';
    float icms = 30.0, pis = 0.9, cofins = 4.15;

    float porc_tributos = calcula_porcentagem_recuperar_valor(qtd_kWh * valor_TUSD_kWh, icms+pis+cofins);
 	
    float res = tarifa_base(qtd_kWh, valor_TUSD_kWh, valor_TE_kWh);

    total_a_pagar += res;

    float add = adicional_bandeira('A', porc_tributos, qtd_kWh, 18, 18+13 );
    add += adicional_bandeira('R', porc_tributos, qtd_kWh, 13, 18+13 );

    total_a_pagar += add;
    total_a_pagar += outros;

    printContaDiscriminada(qtd_kWh, valor_TUSD_kWh, valor_TE_kWh, outros, add);

    printContaImpostos(pis, cofins, outros, total_a_pagar);

    // res = porcentagem(valor_TUSD_kWh*qtd_kWh, total_a_pagar );
    // printf("perc distribuicao = %.2f%% \n", res);
    // res = porcentagem(outros, total_a_pagar );
    // printf("perc imposto municipal = %.2f%%\n", res);

	return 0;
}