
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#define MAX_GAMES 9000
#define MAX_FIELD_SIZE 250
#define MAX_STRING_ARRAY_SIZE 100


typedef struct
{
    int year,
        month;
} Date;

typedef struct
{
    char *name;
    char *owners;
    char *website;
    char *developers;
    char **languages;
    char **genres;

    Date release_date;
    int app_id, age, dlcs, avg_playtime, count_languages, count_genres;
    float price, upvotes;
    bool windows_os, mac_os, linux_os;
} Game;

bool isFim(char *string) { return string[0] == 'F' && string[1] == 'I' && string[2] == 'M'; }
void SubPalavra(char *string, char *string_start, int length)
{
    strncpy(string, string_start, length);
    string[length] = '\0';
}



char *getMesNome(int month)
{
    switch (month)
    {
    case 1:
        return "Jan";
        break;
    case 2:
        return "Feb";
        break;
    case 3:
        return "Mar";
        break;
    case 4:
        return "Apr";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "Jun";
        break;
    case 7:
        return "Jul";
        break;
    case 8:
        return "Aug";
        break;
    case 9:
        return "Sep";
        break;
    case 10:
        return "Oct";
        break;
    case 11:
        return "Nov";
        break;
    case 12:
        return "Dec";
        break;

    default:
        return "N/A";
        break;
    }
}

int getMesNumero(char *month)
{

    
    if (!strcmp(month, "Jan"))
        return 1;
    else if (!strcmp(month, "Feb"))
        return 2;
    else if (!strcmp(month, "Mar"))
        return 3;
    else if (!strcmp(month, "Apr"))
        return 4;
    else if (!strcmp(month, "May"))
        return 5;
    else if (!strcmp(month, "Jun"))
        return 6;
    else if (!strcmp(month, "Jul"))
        return 7;
    else if (!strcmp(month, "Aug"))
        return 8;
    else if (!strcmp(month, "Sep"))
        return 9;
    else if (!strcmp(month, "Oct"))
        return 10;
    else if (!strcmp(month, "Nov"))
        return 11;
    else if (!strcmp(month, "Dec"))
        return 12;
}


void game_inicio(Game *game)
{
    game->name = malloc(100 * sizeof(char));
    game->owners = malloc(100 * sizeof(char));
    game->website = malloc(250 * sizeof(char));
    game->developers = malloc(250 * sizeof(char));
    game->languages = malloc(100 * sizeof(char *));
    for (int i = 0; i < 100; i++)
    {
        game->languages[i] = (char *)malloc(100 * sizeof(char));
    }
    game->genres = malloc(100 * sizeof(char *));
    for (int i = 0; i < 100; i++)
    {
        game->genres[i] = (char *)malloc(100 * sizeof(char));
    }

    strcpy(game->name, "");
    strcpy(game->owners, "");
    strcpy(game->website, "");
    strcpy(game->developers, "");

    for (int i = 0; i < 40; i++)
    {
        strcpy(game->languages[i], "\0");
        strcpy(game->genres[i], "\0");
    }

    game->release_date.month = -1;
    game->release_date.year = -1;
    game->app_id = -1;
    game->age = -1;
    game->dlcs = -1;
    game->avg_playtime = -1;
    game->price = -1;
    game->upvotes = -1;
    game->windows_os = false;
    game->mac_os = false;
    game->linux_os = false;
    game->count_languages = 0;
    game->count_genres = 0;
}

void game_printar(Game *game)
{
    int hours = game->avg_playtime / 60,
        minutes = game->avg_playtime % 60;

    printf("%i %s %s/%04i %s %i %.2f %i [", game->app_id, game->name, getMesNome(game->release_date.month), game->release_date.year, game->owners, game->age, game->price, game->dlcs);

    for (int i = 0; i < game->count_languages; i++)
    {
        printf("%s%s", game->languages[i], i < game->count_languages - 1 ? ", " : "");
    }

    printf("] %s %s %s %s ", game->website, game->windows_os ? "true" : "false", game->mac_os ? "true" : "false", game->linux_os ? "true" : "false");

    if (isnan(game->upvotes))
        printf("0.0%% ");
    else
        printf("%.0f%% ", game->upvotes);

    if (hours > 0)
    {
        printf("%ih ", hours);

        if (minutes > 0)
            printf("%im ", minutes);
    }
    else
    {

        if (minutes > 0)
            printf("%im ", minutes);
        else
            printf("null ");
    }

    printf("%s [", game->developers);

    for (int i = 0; i < game->count_genres; i++)
    {

        printf("%s%s", game->genres[i], i < game->count_genres - 1 ? ", " : "");
    }

    printf("]\n");
}

Game game_clone(Game *game)
{

    Game cloned;

    strcpy(cloned.name, game->name);
    strcpy(cloned.owners, game->owners);
    strcpy(cloned.website, game->website);
    strcpy(cloned.developers, game->developers);

    for (int i = 0; i < game->count_languages; i++)
        strcpy(cloned.languages[i], game->languages[i]);
    for (int i = 0; i < game->count_genres; i++)
        strcpy(cloned.genres[i], game->genres[i]);

    cloned.release_date.month = game->release_date.month;
    cloned.release_date.year = game->release_date.year;
    cloned.app_id = game->app_id;
    cloned.age = game->age;
    cloned.dlcs = game->dlcs;
    cloned.avg_playtime = game->avg_playtime;
    cloned.price = game->price;
    cloned.upvotes = game->upvotes;
    cloned.windows_os = game->windows_os;
    cloned.mac_os = game->mac_os;
    cloned.linux_os = game->linux_os;
    return cloned;
}

void game_ler(Game *game, char *line)
{
    game->name = malloc(100 * sizeof(char));
    game->owners = malloc(100 * sizeof(char));
    game->website = malloc(250 * sizeof(char));
    game->developers = malloc(250 * sizeof(char));

    char c_search, sub[MAX_FIELD_SIZE];
    int index = 0, atr_index = 0;

    // ------------------------------------------------------------ //
    // Find "AppID"
    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            game->app_id = atoi(sub);
            atr_index = ++index;
            break;
        }
    }

    // ------------------------------------------------------------ //
    // Find "Name"
    if (line[atr_index] != ',')
    {
        if (line[atr_index] == '\"')
        {
            atr_index++;
            c_search = '\"';
        }
        else
            c_search = ',';
        while (true)
        {
            index++;
            if (line[index] == c_search)
            {
                SubPalavra(sub, &line[atr_index], index - atr_index);
                strcpy(game->name, sub);
                if (c_search == ',')
                    index++;
                else if (c_search == '\"')
                    index += 2;
                atr_index = index;
                break;
            }
        }
    }
    else
    {
        strcpy(game->name, "null");
        atr_index = ++index;
    }

    // ------------------------------------------------------------ //
    // Find release date
    if (line[atr_index] != ',')
    {
        if (line[atr_index] == '\"')
        {
            atr_index++;
            c_search = '\"';
        }
        else
            c_search = ',';
        while (true)
        {
            index++;
            if (line[index] == c_search)
            {
                SubPalavra(sub, &line[atr_index], index - atr_index);
                char subDate[10];
                SubPalavra(subDate, &sub[0], 3);
                game->release_date.month = getMesNumero(subDate);
                if (c_search == ',')
                {
                    SubPalavra(subDate, &sub[4], 4);
                    game->release_date.year = atoi(subDate);
                    index++;
                }
                else if (c_search == '\"')
                {
                    int nmbSpace = 0;
                    for (int i = 0;; i++)
                    {
                        if (sub[i] == ' ')
                            nmbSpace++;
                        if (nmbSpace == 2)
                        {
                            i++;
                            SubPalavra(subDate, &sub[i], 4);
                            game->release_date.year = atoi(subDate);
                            break;
                        }
                    }
                    index += 2;
                }
                atr_index = index;
                break;
            }
        }
    }
    else
    {
        game->release_date.month = 0;
        game->release_date.year = 0;
        atr_index = ++index;
    }


    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            strcpy(game->owners, sub);
            atr_index = ++index;
            break;
        }
    }

    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            game->age = atoi(sub);
            atr_index = ++index;
            break;
        }
    }

  

    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            game->price = atof(sub);
            atr_index = ++index;
            break;
        }
    }

 
    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            game->dlcs = atoi(sub);
            atr_index = ++index;
            break;
        }
    }


    while (true)
    {
        index++;
        if (line[index] == ']')
        {
            index++;
            if (line[index] == ',')
                index++;
            else if (line[index] == '\"')
                index += 2;
            atr_index = index;
            break;
        }
        else if (line[index] == '\'')
        {
            int wordStart = index + 1;
            while (true)
            {
                index++;
                if (line[index] == '\'')
                {
                    SubPalavra(sub, &line[wordStart], index - wordStart);
                    strcpy(game->languages[game->count_languages++], sub);
                    break;
                }
            }
        }
    }

    if (line[atr_index] != ',')
    {
        if (line[atr_index] == '\"')
        {
            atr_index++;
            c_search = '\"';
        }
        else
            c_search = ',';
        while (true)
        {
            index++;
            if (line[index] == c_search)
            {
                SubPalavra(sub, &line[atr_index], index - atr_index);
                strcpy(game->website, sub);
                atr_index = ++index;
                break;
            }
        }
    }
    else
    {
        strcpy(game->website, "null");
        atr_index = ++index;
    }


    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            if (!strcmp(sub, "True"))
                game->windows_os = true;
            atr_index = ++index;
            break;
        }
    }


    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            if (!strcmp(sub, "True"))
                game->mac_os = true;
            atr_index = ++index;
            break;
        }
    }

 
    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            if (!strcmp(sub, "True"))
                game->linux_os = true;
            atr_index = ++index;
            break;
        }
    }


    int positives, negatives;
    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            positives = atoi(sub);
            atr_index = ++index;
            break;
        }
    }
    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            negatives = atoi(sub);
            atr_index = ++index;
            break;
        }
    }
    game->upvotes = (float)(positives * 100) / (float)(positives + negatives);


    while (true)
    {
        index++;
        if (line[index] == ',')
        {
            SubPalavra(sub, &line[atr_index], index - atr_index);
            game->avg_playtime = atoi(sub);
            atr_index = ++index;
            break;
        }
    }

  
    if (line[atr_index] != ',')
    {
        if (line[atr_index] == '\"')
        {
            atr_index++;
            c_search = '\"';
        }
        else
            c_search = ',';

        while (true)
        {
            index++;
            if (line[index] == c_search)
            {
                SubPalavra(sub, &line[atr_index], index - atr_index);
                strcpy(game->developers, sub);
                atr_index = ++index;
                break;
            }
        }
    }
    else
    {
        strcpy(game->developers, "null");
        atr_index = ++index;
    }


    if (index < strlen(line) - 1)
    {
        if (line[index] == ',')
            atr_index = ++index;
        if (line[atr_index] == '\"')
        {
            atr_index++;
            while (true)
            {
                index++;
                if (line[index] == ',')
                {
                    SubPalavra(sub, &line[atr_index], index - atr_index);
                    strcpy(game->genres[game->count_genres++], sub);
                    atr_index = ++index;
                }
                else if (line[index] == '\"')
                {
                    SubPalavra(sub, &line[atr_index], strlen(line) - 1 - atr_index);
                    if (sub[strlen(sub) - 2] == '\"')
                        sub[strlen(sub) - 2] = '\0';
                    strcpy(game->genres[game->count_genres++], sub);
                    break;
                }
            }
        }
        else
        {
            SubPalavra(sub, &line[atr_index], strlen(line) - 1 - atr_index);
            sub[strlen(line) - 2 - atr_index] = '\0';
            strcpy(game->genres[game->count_genres++], sub);
        }
    }
}

Game procurarGame(Game game[], int id)
{
    Game temp = game[0];
    for (int i = 0; i < 4403; i++)
    {
        if (game[i].app_id == id)
        {
            temp = game[i];
            i = 4403;
        }
    }
    return temp;
}

void inserirFim(Game game[], Game novo, int n_games)
{
    game[n_games] = novo;
    n_games++;
}

void ordernar_rec(Game game[], int n_games, int *comparacoes, int *movimentacoes, int i)
{
    Game temp;
    if (i < n_games - 1)
    {
        int menor = i;
        for (int j = (i + 1); j < n_games; j++)
        {
            *comparacoes += 1;
            if (strcmp(game[menor].name, game[j].name) > 0)
            {
                menor = j;
            }
        }
        // swap
        temp = game[i];
        game[i] = game[menor];
        game[menor] = temp;
        *movimentacoes += 3;

        ordernar_rec(game, n_games, comparacoes, movimentacoes, i + 1);
    }
}

int main(void)
{


    char entrada[1000];
    Game game[4403];
    Game lista[300];
    int lista_size = 0;
  

    FILE *arquivo = fopen("/tmp/games.csv", "r");
    for (int i = 0; !feof(arquivo) && i < 4403; i++)
    {
        fgets(entrada, 4403, arquivo);
        game_inicio(&game[i]);
        game_ler(&game[i], entrada);
    }
    fclose(arquivo);
    

    entrada[0] = '\0';
    for (int i = 0; !isFim(entrada); i++)
    {
        scanf(" %1000[^\n]", entrada);
        if (!isFim(entrada))
        {
            for (int j = 0; j < 4403; j++)
            {
                if (game[j].app_id == atoi(entrada))
                {
                    lista[lista_size] = game[j];
                    lista_size++;
                    j = 4403;
                }
            }
        }
    }

   
    int comparacoes = 0;
    int movimentacoes = 0;
    
    clock_t t1 = clock();
   
    ordernar_rec(lista, lista_size, &comparacoes, &movimentacoes, 0);
    


    clock_t t2 = clock();
    int diff = (int)((((double)t2 - (double)t1) / (double)CLOCKS_PER_SEC) * 1000);
   
    FILE *log = fopen("matricula_selecaoRecursiva.txt", "w");
    fprintf(log, "763994\t%d\t%d\t%d", comparacoes, movimentacoes, diff);
    fclose(log);
  
    for (int i = 0; i < lista_size; i++)
    {
        game_printar(&lista[i]);
    }



    return 0;
}