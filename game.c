/*
Projeto 01) Enunciado: Deve-se desenvolver uma aplicação onde ao ser inicializada solicite ao usuário escolher o nível de
dificuldade do jogo e após isso gera e apresenta, de forma aletaória, um cálculo para que possamos
informar o resultado.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dificuldade;
    int num1;
    int num2;
    int operacao;
    int resultado;
} Calcular;

// define - se uma struct para se trabalhar com os tipos
// de dados que o meu programa exige.

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);


int pontos = 0; //inicializando o contador de pontos em 0;
/*
passo 02: como o ato de jogar o jogo é automático,
é necessário criar um procedimento (função vazia) ANTES do  main
para inicializar o jogo pelo método principal 'int main'
*/
int main () {

    //deve ser chamado apenas 1 vez;
    srand(time(NULL));
    jogar();

    return 0;
}

/*
passo 03: devemos agora implementar o procedimento jogar() que foi
criado antes do int main.

OBS: em PROJETOS REAIS, SEMPRE se declara os procediemntos ANTES do main
para que depois do int main , façamos suas respectivas implementações.
*/
void jogar () {
    Calcular calc;
    int dificuldade;

    printf("\n\t Informe o nível de dificuldade desejada [1, 2, 3 ou 4]: ");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;

    //gera um valor aleatório entre 0 e 2
    //0 == somar, 1 == subtrair, 2 == multiplicar
    calc.operacao = rand() % 3;

    if (calc.dificuldade == 1) {
        //nível fácil.
        calc.num1 = rand() % 11; // vai me gerar um valor aleatório entre 0 a 10.
        calc.num2 = rand() % 11; // vai me gerar um valor aleatório entre 0 a 10.
    } else if (calc.dificuldade == 2) {
        //nível médio.
        calc.num1 = rand() % 101; // vai me gerar um valor aleatório entre 0 e 100.
        calc.num2 = rand() % 101; // vai me gerar um valor aleatório entre 0 e 100.
    } else if (calc.dificuldade == 3) {
        //nível difícil.
        calc.num1 = rand() % 1001; // vai me gerar um número alatório entre 0 e 1000.
        calc.num2 = rand() % 1001; // vai me gerar um número alatório entre 0 e 1000.
    } else if (calc.dificuldade == 4) {
        //nível insano.
        calc.num1 = rand() % 10001; // vai me gerar um número aleatório entre 0 e 10000.
        calc.num2 = rand() % 10001; // vai me gerar um número aleatório entre 0 e 10000.
    } else {
        //DIFICULDADE IMPOSSÍVEL hahahahahahahahaha (risada maléfica).
        calc.num1 = rand() % 100001; // vai me gerar um número aleatório entre 0 e 100000.
        calc.num2 = rand() % 100001; // vai me gerar um número aleatório entre 0 e 100000.
    }

    int resposta;
    printf("\n\t Digite o resultado para a seguinte operação: \n");

    //somar:
    if (calc.operacao == 0) {
        printf("\n\t %d + %d\n", calc.num1, calc.num2);
        scanf("%d", &resposta);

        if (somar(resposta, calc)) {
            pontos++;
            printf("\n\t Você tem %d ponto(s)", pontos);
        }
    }//diminuir:
    else if (calc.operacao == 1) {
        printf("\n\t %d - %d\n", calc.num1, calc.num2);
        scanf("%d", &resposta);

        if (diminuir(resposta, calc)) {
            pontos = pontos + 1;
            printf("\n\t Você tem %d ponto(s)", pontos);
        }
    }//multiplicar:
    else if (calc.operacao == 2) {
        printf("\n\t %d X %d\n", calc.num1, calc.num2);
        scanf("%d", &resposta);

        if (multiplicar(resposta, calc)) {
            pontos +=1;
            printf("\n\t Você tem %d ponto(s)", pontos);
        }
    }// operação desconhecida
    else {
        printf("\n\t A operação %d não é reconhecida.\n\n", calc.operacao);
    }

    //deseja recomeçar o jogo ? (continuar o jogo)
    int continuar;
    printf("\n\t Deseja continuar jogando ? [1 - SIM, 0 - NÃO]\n ");
    scanf("%d", &continuar);

    if (continuar) {
        jogar();
    } else {
        printf("\n\t Você terminou o jogo com %d ponto(s)\n", pontos);
        printf("\n\t Até a próxima. \n\n");
        exit(0);
    }
}

void mostraInfo(Calcular calc) {
    char op[25]; //criando um vetor que poderá armazenar até 25 carateres.

    if(calc.operacao == 0) {//0 == somar
        sprintf(op, "\n\t Somar");
    }else if (calc.operacao == 1) {
        sprintf(op, "\n\t Diminuir");
    }else if (calc.operacao == 2) {
        sprintf(op, "\n\t Multiplicar");
    }else{
        sprintf(op, "\n\t Operação desconhecida");
    }
    printf("\n\t valor 1: %d\n valor 2: %d\n Dificuldade: %d\n Operação: %s",
    calc.num1, calc.num2, calc.dificuldade, op);
}

int somar (int resposta, Calcular calc) {
    int resuktado = calc.num1 + calc.num2;
    calc.resultado = resuktado;
    int certo = 0; // 0 = errou, 1 = acertou.

    if (resposta == calc.resultado) {
        printf("\n\t Resposta correta!\n");
        certo = 1;
    } else {
        printf("\n\t Resposta errada!\n");
    }
    printf("\n\t %d + %d = %d\n", calc.num1, calc.num2, calc.resultado);
    return certo;
}

int diminuir (int resposta, Calcular calc) {
    int resultado = calc.num1 - calc.num2;
    calc.resultado = resultado;
    int certo = 0; //fazendo exatamente a mesma coisa que o caso acima, só qu eagora para a subtração.

    if (resposta = calc.resultado) {
        printf("\n\t Resposta correta!\n");
        certo = 1;
    } else {
        printf("\n\t Resposta errada!\n");
    }
    printf("\n\t %d - %d = %d\n", calc.num1, calc.num2, calc.resultado);
    return certo;
}

int multiplicar (int resposta, Calcular calc) {
    int resultado = calc.num1 * calc.num2;
    calc.resultado = resultado;
    int certo = 0; //fazendo exatamente a mesma coisa que o caso acima, só qu eagora para a multiplicação.

    if (resposta = calc.resultado) {
        printf("\n\t Resposta correta!\n");
        certo = 1;
    } else {
        printf("\n\t Resposta errada!\n");
    }
    printf("\n\t %d X %d = %d\n", calc.num1, calc.num2, calc.resultado);
    return certo;
}