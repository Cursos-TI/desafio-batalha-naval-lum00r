#include <stdio.h>
#include <stdbool.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
// Tamanho dos navios
#define TAMANHO_NAVIO 3
// Símbolos para representar o tabuleiro
#define AGUA '0'
#define NAVIO '3'

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical) {
    // Verifica se a posição inicial está dentro do tabuleiro
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return false;
    }
    
    // Verifica se o navio cabe na posição escolhida
    if (vertical) {
        if (linha + tamanho - 1 >= TAMANHO_TABULEIRO) {
            return false;
        }
    } else {
        if (coluna + tamanho - 1 >= TAMANHO_TABULEIRO) {
            return false;
        }
    }
    
    return true;
}

// Função para verificar se há sobreposição com outro navio
bool semSobreposicao(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            if (tabuleiro[i][coluna] != AGUA) {
                return false;
            }
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            if (tabuleiro[linha][j] != AGUA) {
                return false;
            }
        }
    }
    return true;
}

// Função para posicionar um navio no tabuleiro
bool posicionarNavio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha, int coluna, int tamanho, bool vertical) {
    // Verifica se a posição é válida
    if (!posicaoValida(linha, coluna, tamanho, vertical)) {
        printf("Posição inválida para o navio!\n");
        return false;
    }
    
    // Verifica se há sobreposição com outro navio
    if (!semSobreposicao(tabuleiro, linha, coluna, tamanho, vertical)) {
        printf("Navio sobreposto a outro navio!\n");
        return false;
    }
    
    // Posiciona o navio
    if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            tabuleiro[i][coluna] = NAVIO;
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            tabuleiro[linha][j] = NAVIO;
        }
    }
    
    return true;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d", j); // Imprime números das colunas
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Imprime número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2c", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Declaração do tabuleiro
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    
    printf("Posicionando navios no tabuleiro de Batalha Naval\n");
    
    // Posiciona o navio horizontal (coordenadas fixas no código)
    int linhaHorizontal = 2, colunaHorizontal = 3;
    bool posicionadoHorizontal = posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 
                                               TAMANHO_NAVIO, false);
    
    if (!posicionadoHorizontal) {
        printf("Falha ao posicionar navio horizontal. Usando posição alternativa.\n");
        // Tentativa com posição alternativa
        posicionarNavio(tabuleiro, 4, 2, TAMANHO_NAVIO, false);
    }
    
    // Posiciona o navio vertical (coordenadas fixas no código)
    int linhaVertical = 5, colunaVertical = 7;
    bool posicionadoVertical = posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 
                                             TAMANHO_NAVIO, true);
    
    if (!posicionadoVertical) {
        printf("Falha ao posicionar navio vertical. Usando posição alternativa.\n");
        // Tentativa com posição alternativa
        posicionarNavio(tabuleiro, 1, 8, TAMANHO_NAVIO, true);
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}