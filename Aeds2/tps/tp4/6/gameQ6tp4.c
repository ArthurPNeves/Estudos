#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char** strs;
    int len, 
        cap;
} Strings;

typedef struct {
    char* s;
    int order;
} Data;

typedef struct {
    int appID, age, dlcs, avgPT;
    float price, upvotes;
    bool windows, mac, l;
    Data date;
    char *name, *owners, *website, *developers; 
    Strings languages, genres;
} Game;

typedef struct getNo {
    Game* obj;
    struct getNo* next;
    struct getNo* prev;
} No;

typedef struct {
    No* first;
    No* last;
    int len;
} ListaDuplamenteEncadeada;




void modificarr();

void printar(Game* g);
void printarStrings(Strings strs);
void paraStrings(char** const arr, int len);
void imprimirTempo(int t);

char* read(char* id, FILE* f);

bool eNumero(char c);
bool eFloat(char* const s);
size_t length(const char* const s);
double xerenginisFloat(double b, int e);
float minhaVez(float x);
int mestreSplinter(int b, int e);
bool igualss(const char* const s1, const char* const s2);
int comparCom(char* const s1, char* const s2);
char* removerChar(char* const s, char c);
int meuMes(char* const s);




Game* montarGame(Strings arr);

Strings separacao(char* const s, char c);

int contar(char* const s, char c);


void modificarDAta(Data* const date, char* s);





void alocarString(Strings* strs, int len);

void LiberarString(Strings strs);

int pegarID(char* const s);

char* srovsdolis(char* const s);


No* montarNoVazio();

No* montarNo(Game* obj);

void limparNo(No* getNo);



ListaDuplamenteEncadeada* construirLista();

void destruirLista(ListaDuplamenteEncadeada* const list);

void limpa(ListaDuplamenteEncadeada* const list);


No* getNo(ListaDuplamenteEncadeada* const list, int idx);


Game* listarGet(ListaDuplamenteEncadeada* const list, int idx);



void listarPush(ListaDuplamenteEncadeada* const list, Game* obj);


void listarInsert(ListaDuplamenteEncadeada* const list, Game* obj, int idx);


void listarInsertInicio(ListaDuplamenteEncadeada* const list, Game* obj);


Game* listarPop(ListaDuplamenteEncadeada* const list);


Game* listarRemove(ListaDuplamenteEncadeada* const list, int idx);

Game* listaRemoveBegin(ListaDuplamenteEncadeada* const list);


void quickSort(ListaDuplamenteEncadeada* const list, int first, int last);


int partition(ListaDuplamenteEncadeada* const list, int first, int last);


void swap(ListaDuplamenteEncadeada* const list, int a, int b);





No* montarNoVazio() {
    No* getNo = (No*)malloc(sizeof(No));
    limparNo(getNo);
    return getNo;
}



No* montarNo(Game* obj) {
    No* getNo = (No*)malloc(sizeof(No));
    getNo->obj = obj;
    getNo->next = NULL;
    getNo->prev = NULL;
    return getNo;
}


void limparNo(No* getNo) {
    getNo->obj = NULL;
    getNo->next = NULL;
    getNo->prev = NULL;
}



ListaDuplamenteEncadeada* construirLista() {
    ListaDuplamenteEncadeada* list = (ListaDuplamenteEncadeada*)malloc(sizeof(ListaDuplamenteEncadeada));
    limpa(list);
    return list;
}



void limpa(ListaDuplamenteEncadeada* const list) {
    list->first = NULL;
    list->last = NULL;
    list->len = 0;
}


void destruirLista(ListaDuplamenteEncadeada* const list) {
    No* curr = list->first;
    No* rem;
    for(int i = 0; i < list->len; i++) {
        rem = curr->next;
        free(curr);
        curr = rem;
    }
    free(list);
}




No* getNo(ListaDuplamenteEncadeada* const list, int idx) {
    No* cell = NULL;

    if(idx >= 0 && idx < list->len) {
        if(idx < list->len / 2) {
            cell = list->first;
            for(int i = 0; i < idx; i++) cell = cell->next;
        } else {
            cell = list->last;
            for(int i = list->len - 1; i > idx; i--) cell = cell->prev;
        }
    }

    return cell;
}



Game* listarGet(ListaDuplamenteEncadeada* const list, int idx) {
    return getNo(list, idx)->obj;
}



void listarPush(ListaDuplamenteEncadeada* const list, Game* obj) {
    No* cell = montarNo(obj);

    if(list->len == 0) {
        list->first = cell;
        list->last = cell; 
    } else {
        cell->prev = list->last;
        list->last->next = cell;
        list->last = cell;
    }

    list->len++;
}



void listarInsert(ListaDuplamenteEncadeada* const list, Game* obj, int idx) {
    if(idx >= 0 && idx <= list->len) {
        if(idx == 0) listarInsertInicio(list, obj);
        else if(idx == list->len) listarPush(list, obj);
        else {
            No* cell = montarNo(obj);
            No* curr = getNo(list, idx);
            cell->next = curr;
            cell->prev = curr->prev;
            curr->prev = cell;
            cell->prev->next = cell;
            list->len++;
        }
    }
}





void listarInsertInicio(ListaDuplamenteEncadeada* const list, Game* obj) {
    No* cell = montarNo(obj);

    if(list->len == 0) {
        list->first = cell;
        list->last = cell;
    } else {
        cell->next = list->first;
        list->first->prev = cell;
        list->first = cell;
    }

    list->len++;
}




Game* listarPop(ListaDuplamenteEncadeada* const list) {
    Game* g = NULL;

    if(list->len != 0) {
        g = list->last->obj;
        if(list->first == list->last) {
            free(list->first);
            list->first = list->last = NULL;
        } else {
            list->last = list->last->prev;
            free(list->last->next);
            list->last->next = NULL;
        }
    }

    list->len--;
    return g;
}



Game* listarRemove(ListaDuplamenteEncadeada* const list, int idx) {
    Game* g = NULL;

    if(list->len != 0 && idx >= 0 && idx < list->len) {
        if(idx == 0) g = listaRemoveBegin(list);
        else if(idx == list->len - 1) g = listarPop(list);
        else {
            No* curr = getNo(list, idx);
            g = curr->obj;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = NULL;
            curr->prev = NULL;
            free(curr);
            list->len--;
        }
    }

    return g;
}




Game* listaRemoveBegin(ListaDuplamenteEncadeada* const list) {
    Game* g = NULL;
    
    if(list->len != 0) {
        g = list->first->obj;
        if(list->first == list->last) {
            free(list->first);
            list->first = list->last = NULL;
        } else {
            list->first = list->first->next;
            list->first->prev->next = NULL;
            free(list->first->prev);
            list->first->prev = NULL;
        }
    }

    list->len--;
    return g;
}




Game* montarGame(Strings arr) {
    Game* g = (Game*)malloc(sizeof(Game));
    g->appID = atoi(arr.strs[0]);
    g->name = arr.strs[1];
    modificarDAta(&g->date, arr.strs[2]);
    g->owners = arr.strs[3];
    g->age = atoi(arr.strs[4]);
    g->price = atof(arr.strs[5]);
    g->dlcs = atoi(arr.strs[6]);
    g->languages = separacao(removerChar(removerChar(arr.strs[7], '['), ']'), ',');
    g->website = arr.strs[8];
    g->windows = arr.strs[9][0] == 'T';
    g->mac = arr.strs[10][0] == 'T';
    g->l = arr.strs[11][0] == 'T';
    
    g->upvotes = (atof(arr.strs[12]) / (atof(arr.strs[13]) + atof(arr.strs[12]))) * 100;
    
    g->avgPT = atoi(arr.strs[14]);
    g->developers = arr.strs[15];
    g->genres = separacao(arr.strs[16], ',');

    return g;
}




Strings separacao(char* const s, char c) { 
    int len = length(s),
        cont = contar(s, c);
    Strings strs;
    strs.len = cont + 1;
    strs.strs = (char**)malloc(sizeof(char*) * (cont + 1));
    char* str = (char*)calloc(1000, sizeof(char));

    int m = 0, j = 0;
    for(int i = 0, l = 0, k = 0; i < len; i++) {
        if(s[i] == '[' || s[i] == ']') l++;
        if(s[i] == '\"') k++;
        else if(s[i] != c || k % 2 != 0) {
            if(l % 2 == 0) str[j++] += s[i];
            else if(s[i] != '\'') str[j++] += s[i];
        } else {
            str[j] = '\0';
            strs.strs[m++] = str;
            str = (char*)calloc(1000, sizeof(char));
            j = 0;
            str[j] = '\0';
        }
    }

    str[j] = '\0';
    strs.strs[m] = str;
    return strs;
}





int contar(char* const s, char c) {
    int qtd = 0,
        len = length(s);
    for(int i = 0, a = 0; i < len; i++) {
        if(s[i] == 34) a++;
        else if(s[i] == c && a % 2 == 0) qtd++;
    }
    
    return qtd;
}




void printar(Game* g) {
    printf("%i %s %s %s %i %.2f %i ", g->appID, g->name, g->date.s, g->owners, g->age, g->price, g->dlcs);
    paraStrings(g->languages.strs, g->languages.len);
    printf(" %s %s %s %s %i%% ", (length(g->website) == 0) ? "null" : g->website, g->windows ? "true" : "false", g->mac ? "true" : "false", g->l ? "true" : "false", (int)minhaVez(g->upvotes));
    imprimirTempo(g->avgPT);
    printf(" %s ", g->developers);
    printarStrings(g->genres);
    puts("");
}



void printarStrings(Strings strs) {
    printf("[");
    for(int i = 0; i < strs.len; i++) {
        printf("%s", strs.strs[i]);
        if(i != strs.len - 1) printf(", ");
    }
    printf("]");
}




void paraStrings(char** const arr, int len) {
    printf("[");
    for(int i = 0; i < len; i++) {
        printf("%s", arr[i]);
        if(i != len - 1) printf(",");
    } 
    printf("]");
}




void imprimirTempo(int t) {
    int h = t / 60;
    int m = t % 60;

    if(h != 0 && m != 0) printf("%ih %im", h, m);
    else if(h == 0 && m != 0) printf("%im", m);
    else if(h != 0 && m == 0) printf("%ih", h);
    else printf("null");
}





bool eNumero(char c) {
    return (int)c >= 48 && (int)c <= 57;
}




bool eFloat(char* const s) {
    bool value = true;
    for(int i = 0, j = 0; i < length(s) && value; i++) {
        if(s[i] == ',' || s[i] == '.') j++; 
        else value = eNumero(s[i]);
        if(value) value = j <= 1; 
    } 
    return value;
}



bool igualss(const char* const s1, const char* const s2) {
    int len1 = length(s1),
        len2 = length(s2);
    bool value = len1 == len2;

    for(int i = 0; i < len1 && value; i++) 
        value = s1[i] == s2[i];
    return value;
}



size_t length(const char* const s) {
    size_t i = 0;
    if(s != NULL)
        while(s[i] != '\0') i++;
    return i;
}




double xerenginisFloat(double b, int e) {
    double res = 1;
    for(int i = 0; i < e; i++) res *= b;
    return res;
}



int mestreSplinter(int b, int e) {
    int res = 1;
    for(int i = 0; i < e; i++) res *= b;
    return res;
}



float minhaVez(float x) {
    float dif = x - (float)((int)x);
    if(dif >= 0.5) x = (float)((int)x + 1);
    else x = (float)((int)x);
    return x;
}




int pegarID(char* const s) {
    char* str = (char*)calloc(50, sizeof(char));
    int len = length(s);

    int j = 0;
    for(int i = 0; i < len && s[i] != ','; i++) 
        str[j++] = s[i];

    str[j] = '\0';
    int res = atoi(str);
    free(str);
    return res;
}




void alocarString(Strings* strs, int len) {
    strs->len = len;
    strs->strs = (char**)malloc(sizeof(char*) * len);
    for(int i = 0; i < len; i++) strs->strs[i] = (char*)calloc(1000, sizeof(char));
}



void LiberarString(Strings strs) {
    for(int i = 0; i < strs.len; i++) free(strs.strs[i]);
    free(strs.strs);
}



void modificarDAta(Data* const date, char* s) {
    s = srovsdolis(s);
    s = removerChar(s, ',');
    Strings arr = separacao(s, ' ');

    int len = length(s);
    char* str = (char*)calloc(len + 1, sizeof(char));
    
    int sum = 0,
        i = 0;

    if(arr.len > 2) {
        sum += meuMes(arr.strs[0]) * 100;
        sum += atoi(arr.strs[1]);
        sum += atoi(arr.strs[2]) * 10000;
    } else {
        sum += meuMes(arr.strs[0]) * 100;
        sum += atoi(arr.strs[1]) * 10000;
    }

    for(int j = 0; j < length(arr.strs[0]); j++)
        str[i++] = arr.strs[0][j];

    str[i++] = '/';

    for(int j = len - 4; j < len; j++)
        str[i++] = s[j];

    str[i] = '\0';
    date->s = str;
    date->order = sum; 
    LiberarString(arr);
}





int meuMes(char* const s) {
    char* arr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int i = 0; i < 12; i++) 
        if(igualss(arr[i], s)) return (i + 1);
    return -1;
}




char* srovsdolis(char* const s) {
    int len = length(s);
    char* str = (char*)calloc(len + 1, sizeof(char));
    
    int j = len - 1,
        i = 0;
    while(s[j] == ' ' || s[i] == ' ') {
        if(s[i] == ' ') i++;
        if(s[j] == ' ') j--;
    }


    int k = 0;
    while(i <= j) 
        str[k++] = s[i++];

    str[k] = '\0';
    return str;
}



char* removerChar(char* const s, char c) {
    int len = length(s),
        j = 0;
    char* str = (char*)calloc(len + 1, sizeof(char));

    for(int i = 0; i < len; i++) 
        if(s[i] != c) str[j++] = s[i];

    str[j] = '\0';
    return str;
}



void quickSort(ListaDuplamenteEncadeada* const list, int first, int last)  {
    if(first < last) {
        int p = partition(list, first, last);

        quickSort(list, p, last);
        quickSort(list, first, p - 1);
    }
}

int partition(ListaDuplamenteEncadeada* const list, int first, int last) {
    Game* p = listarGet(list, (first + last) / 2);

    int i = first,
        j = last;

    while(i <= j) {
        while(listarGet(list, i)->date.order < p->date.order || 
             (listarGet(list, i)->date.order == p->date.order && strcmp(listarGet(list, i)->name, p->name) < 0)) i++;
        while(listarGet(list, j)->date.order > p->date.order ||
             (listarGet(list, j)->date.order == p->date.order && strcmp(listarGet(list, j)->name, p->name) > 0)) j--;
        if(i <= j) {
            swap(list, i, j);
            i++;
            j--;
        }
    }

    return i;
}



void swap(ListaDuplamenteEncadeada* const list, int a, int b) {
    Game* g = listarGet(list, a);
    getNo(list, a)->obj = listarGet(list, b);
    getNo(list, b)->obj = g;
}




void modificarr() {
    char* s = (char*)calloc(1000, sizeof(char));
    ListaDuplamenteEncadeada* list = construirLista();

    FILE* f = fopen("games.csv", "r");
    if(f == NULL) {
        f = fopen("/tmp/games.csv", "r");
        if(f == NULL) {
            printf("Arquivo não encontrado!\n");
            exit(1);
        }
    }

    scanf(" %[^\n\r]", s);
    while(!igualss(s, "FIM")) {
        char* str = read(s, f);
        listarPush(list, montarGame(separacao(read(str, f), ',')));
        free(str);
        scanf(" %[^\n\r]", s);
    }

    quickSort(list, 0, list->len - 1);

    for(int i = 0; i < list->len; i++) {
        printar(listarGet(list, i));
    }
    
    destruirLista(list);
    free(s);
    fclose(f);
}




char* read(char* id, FILE* f) {
    char* str = (char*)calloc(1000, sizeof(char));
    bool value = false;

    rewind(f);
    do {
        fscanf(f, " %[^\r\n]", str);
        value = pegarID(str) == atoi(id);
    } while(!feof(f) && !value);

    return str;
}



int main(int argc, char** args) {  
    modificarr();
    return 0;
}