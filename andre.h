void HelloWorld();

float tarifa_base(int qtd_kWh, float valor_TUSD_kWh, float valor_TE_kWh);
float adicional_bandeira(char cod_bandeira, float tributos, int qtd_kWh, int dias_na_bandeira, int total_dias);
float calcula_porcentagem_recuperar_valor(float valor_base, float porc_impostos);
float porcentagem(float parcela, float total);

void printContaDiscriminada(int qtd_kWh, float v_distribuicao, float v_energia, float outros, float add);
void printContaImpostos(float pis, float cofins, float outros, float valor_total);