#include <stdio.h>
#include <stdlib.h>

void inserirProdutos(int *codigos, float *precos){
    int codigo;
    float preco;
    for(int i=0; i < 10; i++){
        printf("Digite o codigo do produto %i/10\n",i+1);
        scanf("%i",&codigo);
        printf("Digite o valor do produto %i/10\n", i+1);
        scanf("%f",&preco);
        codigos[i] = codigo;
        precos[i] = preco;
    }
};

float buscarPreco(int codigo, int *codigos, float *precos){
    for(int i=0; i<10; i++){
        if(codigo == codigos[i]){
            return precos[i];
        }
    }
}

int main(void){
    int codigos[10];
    float precos[10];
    int carrinho[2][20];
    char nome[32];
    int cpf;
    int contagem = 0;
    int comprando = 1;
    

   

    inserirProdutos(codigos,precos);



     //login
    printf("Bem vindo! Digite o seu nome:\n");
    scanf("%s",nome);
    printf("agora por favor, digite o seu CPF (apenas numeros):\n");
    scanf("%i",&cpf);

    char resposta;
    while (comprando == 1)
    {
        printf("Digite o codigo do produto %i\n", contagem + 1);
        scanf("%d", &carrinho[0][contagem]);
        printf("E a quantidade desejada\n");
        scanf("%d",&carrinho[1][contagem]);
        contagem++;
        if(contagem == 10){
            comprando = 0;
        }else{
            printf("Encerrar compra?[digite 's' para sim/ outra tecla para nao]:\n");
            scanf(" %c",&resposta);

            if(resposta == 's'){
                comprando = 0;
            }
        }
    }

    //compra finalizada
    float unitario,total, notaTotal = 0;
    int notaCodigo,notaQuantidade;

    printf("Compra finalizada. Nota fiscal:\n Nome do cliente: %s\n CPF: %d\n\n\n",nome,cpf);
    printf("codigo\t quantidade\t valor uni\t valor tot\n");
    for(int i = 0; i < contagem; i++){

        notaCodigo = carrinho[0][i];
        notaQuantidade = carrinho[1][i];
        unitario = buscarPreco(notaCodigo,codigos,precos);
        total = unitario * notaQuantidade;
        printf("%d\t %d\t %f\t %f\n",notaCodigo,notaQuantidade,unitario,total);
        notaTotal = notaTotal + total;
        if(i == (contagem-1)) printf("Valor total da compra: %f\n", notaTotal);

    }
    
    return 0;

}