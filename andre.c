#include <stdio.h>

void HelloWorld(){
	printf("OII\n");
}

float tarifa_base(int qtd_kWh, float valor_TUSD_kWh, float valor_TE_kWh){
	// float valor_a_pagar = qtd_kWh * valor_TUSD_kWh;
 //    valor_a_pagar += qtd_kWh * valor_TE_kWh;
 //    return valor_a_pagar;
    return qtd_kWh * (valor_TUSD_kWh + valor_TE_kWh);
}

float calcula_porcentagem_recuperar_valor(float valor_base, float porc_impostos){
	float valor_com_imposto = valor_base*porc_impostos/100;
	float valor_sem_imposto = valor_base - valor_com_imposto;
	float res = valor_base / valor_sem_imposto;
	return res; 
}

float porcentagem(float parcela, float total){
	return parcela/total*100;
}

void printContaDiscriminada(int qtd_kWh, float v_distribuicao, float v_energia, float outros, float add){
	float dist = qtd_kWh*v_distribuicao;
	float energia = qtd_kWh*v_energia;
	float valor_total = dist + energia + add + outros;
	
	printf("\n\n#################################################\n");
	printf("#       DISCRIMINACAO GASTOS       \n");
	printf("#       CONSUMO = %iKwH       \n", qtd_kWh);
	printf("#################################################\n");
	printf("#       Distribuicao (TUSD) = %.2f%% \t R$%.2f   \n", porcentagem(dist, valor_total), dist);
	printf("#       Energia (TE)        = %.2f%% \t R$%.2f   \n", porcentagem(energia, valor_total), qtd_kWh*v_energia);
	printf("#       Adicional Bandeira  = %.2f%% \t R$%.2f   \n", porcentagem(add, valor_total), add);
	printf("#       Outros              = %.2f%% \t R$%.2f   \n", porcentagem(outros, valor_total), outros);
	printf("#################################################\n");
	printf("#       Valor TOTAL         = %.2f%% \t R$%.2f      \n", 100.0, valor_total);
	printf("#################################################\n");
}

void printContaImpostos(float pis, float cofins, float outros, float valor_total){
	printf("\n\n#################################################\n");
	printf("#       IMPOSTOS       \n");
	printf("#################################################\n");
	printf("#       ICMS   - estadual  = %.2f%% \t R$%.2f      \n", 30.0, 0.3*valor_total);
	printf("#       PIS    - federal   = %.2f%% \t R$%.2f     \n", pis, pis*valor_total/100);
	printf("#       COFINS - federal   = %.2f%% \t R$%.2f     \n", cofins, cofins*valor_total/100);
	printf("#       IP-CIP - municipal = %.2f%% \t R$%.2f      \n", porcentagem(outros, valor_total), outros);
	printf("#################################################\n");

float soma = 30+pis+cofins+porcentagem(outros, valor_total);
float valor_do_imposto = soma*valor_total/100;

	printf("#       Valor DO Imposto  = %.2f%% \t R$%.2f      \n", soma, valor_do_imposto);
	printf("#       Valor SEM Imposto = %.2f%% \t R$%.2f      \n", 100.0-soma, valor_total-valor_do_imposto);
	printf("#       Valor TOTAL       = %.2f%% \t R$%.2f      \n", 100.0, valor_total);
	printf("#################################################\n");
	printf("#       Valor SEM Imposto = R$%.2f      \n", valor_total-valor_do_imposto);
	printf("#       + %.2f%% impostos = R$%.2f      \n", (calcula_porcentagem_recuperar_valor(valor_total, soma)-1)*100, valor_total);
	printf("#################################################\n");
}


float adicional_bandeira(char cod_bandeira, float tributos, int qtd_kWh, int dias_na_bandeira, int total_dias){
	float add_bandeira;
	switch(cod_bandeira){
    	case 'e':
    	case 'E':
    		add_bandeira = 0.0;
    	break;
    	case 'a':
    	case 'A':
    		add_bandeira = 1.34 * tributos * qtd_kWh / 100;
    	break;
    	case 'v':
    	case 'V':
    		add_bandeira = 4.16 * tributos* qtd_kWh / 100;
    	break;
    	case 'r':
    	case 'R':
    		add_bandeira = 6.24 * tributos* qtd_kWh / 100;
    	break;
    	default:
    		add_bandeira = 0.0;
    	break;
    }

    return add_bandeira * dias_na_bandeira / total_dias;
}