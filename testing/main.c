#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int main() 
{
    int fd;
    int res;
    char *line;
    int i;
    line = NULL;
    // abre o texto
    fd = open("txt_files/text_gray.txt", O_RDONLY);
    res = 1; // resposta tem que ser 1 pra igular com o resultado esperado
    i = 1;
    while (res == 1)
    {
        res = get_next_line(fd, &line);
        printf("tipo(%d) %dº chamada\n", res, i); //numero da chamada
        printf("Chamada %d: %s\n", i, line); //printar a linha
        free(line);
        line = NULL;
        i++;
    }
	close(fd);
}

// eu tenho que correr o todo o BUFFER_SIZE caso haja um \n ele printa até o \n e caso 
// ele o (res < BUFFer) isso mostra que acabou o arquivo. 