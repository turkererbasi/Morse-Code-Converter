#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

typedef struct tree
{
    char *data;
    char letter;                               /* It is keeping Morse code & letter & number.*/
    int number;
    struct tree *left, *right;
} tree;

tree *insert (tree *root, char data[], char letter, int number)
{
    if (root == NULL)
    {
        tree *new_root = (tree*) malloc(sizeof(tree));                         /* Insert function for building a tree. */
        new_root->data = data;
        new_root->number = number;
        new_root->letter = letter;
        new_root->left = new_root->right = NULL;
        return new_root;
    }
    else if (number < root->number)
    {
        root->left = insert (root->left, data, letter, number);
    }
    else if (number > root->number)
    {
        root->right = insert (root->right, data, letter, number);
    }
    else
    {
        /* Already in tree*/
    }
    return root ;
}

tree *searchLetter (tree *root, char data[], int q)
{
    if (root != NULL && strcmp(data, root->data) != 0)    /* We can search  <=> the root is not NULL. */
    {
        if (data[q] == '.')         /* Checking the characters one by one if it is "." go left. */
        {
            //printf("plus");
            return searchLetter (root->left, data, q+1);

        }
        if (data[q] == '-')         /* Checking the characters one by one if it is "-" go right. */
        {
            //printf("minus");
            return searchLetter (root->right, data, q+1);
        }
    }

    return root;
}

//void inorder(tree *root)            /* Don't need just for checking every thing is all right. */
//{
//    if (root == NULL)
//        return;
//    inorder(root -> left);
//    printf(" %s ", root->data);
//    printf(" %d ", root->number);
//    printf(" %c ", root->letter);
//    inorder(root->right);
//}

void Coder ()
{
    char S[MAX];
    char c;
    int i = 0;
    getchar();
    while (c != '\n')
    {
        c = getchar();
        if (c != '\n')              /* Getting char putting it in to the "S" string. */
        {
            S[i] = c;
            i++;
        }
    }
    S[i] = '\0';                  /* Adding sting terminator at the end of the string. */

    int length;
    length = strlen(S);                                      /* Finding the length of the text that we wrote. */
    printf("Length of the text is: %d \n", length);

    char h;
    for (int i=0; i<length; i++)                                /* Search loop for the codding. */
    {
        h = S[i];
        if      (h == 'A' || h == 'a'){printf(".-");}
        else if (h == 'B' || h == 'b'){printf("-...");}
        else if (h == 'C' || h == 'c'){printf("-.-.");}
        else if (h == 'D' || h == 'd'){printf("-..");}
        else if (h == 'E' || h == 'e'){printf(".");}
        else if (h == 'F' || h == 'f'){printf("..-.");}
        else if (h == 'G' || h == 'g'){printf("--.");}
        else if (h == 'H' || h == 'h'){printf("....");}
        else if (h == 'I' || h == 'i'){printf("..");}
        else if (h == 'J' || h == 'j'){printf(".---");}
        else if (h == 'K' || h == 'k'){printf("-.-");}
        else if (h == 'L' || h == 'l'){printf(".-..");}
        else if (h == 'M' || h == 'm'){printf("--");}
        else if (h == 'N' || h == 'n'){printf("-.");}
        else if (h == 'O' || h == 'o'){printf("---");}
        else if (h == 'P' || h == 'p'){printf(".--.");}
        else if (h == 'Q' || h == 'q'){printf("--.-");}
        else if (h == 'R' || h == 'r'){printf(".-.");}
        else if (h == 'S' || h == 's'){printf("...");}
        else if (h == 'T' || h == 't'){printf("-");}
        else if (h == 'U' || h == 'u'){printf("..-");}
        else if (h == 'V' || h == 'v'){printf("...-");}
        else if (h == 'W' || h == 'w'){printf(".--");}
        else if (h == 'X' || h == 'x'){printf("-..-");}
        else if (h == 'Y' || h == 'y'){printf("-.--");}
        else if (h == 'Z' || h == 'z'){printf("--..");}
        else if (h == '0'){printf("-----");}
        else if (h == '1'){printf(".----");}
        else if (h == '2'){printf("..---");}
        else if (h == '3'){printf("...--");}
        else if (h == '4'){printf("....-");}
        else if (h == '5'){printf(".....");}
        else if (h == '6'){printf("-....");}
        else if (h == '7'){printf("--...");}
        else if (h == '8'){printf("---..");}
        else if (h == '9'){printf("----.");}
        else if (h == '&'){printf(".-...");}
        else if (h == '"'){printf(".-..-.");}
        else if (h == '@'){printf(".--.-.");}
        else if (h == '('){printf("-.--.");}
        else if (h == ')'){printf("-.--.-");}
        else if (h == ':'){printf("---...");}
        else if (h == ','){printf("--..--");}
        else if (h == '='){printf("-...-");}
        else if (h == '!'){printf("-.-.--");}
        else if (h == '.'){printf(".-.-.-");}
        else if (h == '-'){printf("-....-");}
        else if (h == '+'){printf(".-.-.");}
        else if (h == '?'){printf("..--..");}
        else if (h == '/'){printf("-..-.");}
        else if (h == '_'){printf("..--.-");}
        else if (h == ';'){printf("-.-.-.");}
        else if (h == '\''){printf(".----.");}
        if      (h == ' '){printf("/");}
        printf(" ");                                            /* "/" between characters. */
    }
}



int main ()
{
    int numberS[63]= { 1024,512,1536,256,786,1280,1792,128,384,640,896,1152,1408,1664,1920,64,192,320, 448,576, 704,832,960,              /* Skeleton of the tree. */
                     1088,1216,1344,1472,1600,1728, 1856, 1994,32,96,210, 400,480,550, 600,660, 850,1000,1050,1100,1170, 1350,1450,1570,
                     1650,1800,1950,2000,390,420,590,680,840,980,1070,1346,1370,1460,1660,1796
                   };

    char dataS[63][6]= {"/", ".", "-", "..", ".-", "-.", "--", "...", "..-", ".-.", ".--", "-..", "-.-", "--.", "---", "....",
                        "...-", "..-.", "#", ".-..", "#", ".--.", ".---", "-...", "-..-", "-.-.", "-.--", "--..", "--.-", "#", "#", ".....", "....-",
                        "...--", "#", "..---", ".-...", "#", ".-.-.", "#" , ".----", "-....", "-...-", "-..-.", "#", "-.--.", "--...", "#", "---..",
                        "----.", "-----", "..--..", "..--.-", ".-..-.", ".-.-.-", ".--.-.", ".----.", "-....-", "-.-.-.","-.-.--", "-.--.-", "--..--", "---..."
                     };

    char letterS[63]= {' ', 'E', 'T', 'I', 'A', 'N', 'M', 'S', 'U', 'R', 'W', 'D', 'K', 'G', 'O', 'H', 'V', 'F', '#', 'L', '#',
                     'P', 'J', 'B', 'X', 'C', 'Y', 'Z', 'Q', '#', '#', '5', '4', '3', '#', '2', '&', '#', '+', '#', '1', '6', '=', '/', '#', '(', '7',           /* Latin letters for tree. */
                     '#', '8', '9', '0', '?', '_', '"', '.', '@', '\'', '-', ';', '!', ')', ',', ':'
                    };

    tree *root = NULL;
    int i;
    for(i=0; i<63 ; i++)
        root = insert(root, dataS[i], letterS[i], numberS[i]);      /* Building tree with for loop. */

    printf("\tWelcome to the menu!\n\n");
    printf("->Please press (1) for Coder.\n\n");
    printf("->Please press (2) for Decoder.\n\n");
    printf("->Please press (3) for File Coder.\n    (You need to enter every thing into the {Coder} file.)\n\n"); // Menu
    printf("->Please press (4) for File Decoder.\n  (You need to enter every thing into the {Decoder} file.)\n\n");

    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("Welcome to the Coder!\n"); /* Coder section. */
        printf("You may start entering your text:\n");
        Coder();
    }

    else if (n == 2)
    {
        printf("Welcome to the Decoder!\n");
        printf("Please add one more (white space) at the end of your string then hit enter.\n");
        printf("You may start entering your text:\n");

        char T[MAX];//user input
        char b;
        i = 0;
        getchar();
        while (b != '\n')  // Taking input from user
        {
            b = getchar();
            if (b != '\n')  //taking letter by letter
            {
                T[i] = b;
                i++;
            }
        }
        T[i] = '\0'; // adding string terminator at the end

        int length;
        length = strlen(T);  // Finding the length of the string.
        printf("Length of the text is: %d \n", length);


        int read = 0;
        tree *pointer;
        char send[7];  //Little string to send into the search function.6 because biggest possible Morse letter
        int inside=0;
        i = 0;
        while (T[read]!='\0') //Read until the end of the string
        {
            while (T[i]!=' ') // Read until the space
            {
                send[inside]=T[i];  //take the string into little string
                ++inside;
                ++i;
            }
            pointer = searchLetter(root, send, 0);
            printf("%c", pointer->letter);
            read = i+1;
            //send[0] = '\0';
            memset(send,0,strlen(send));
            inside = 0;
            i++;
        }
    }

    else if (n == 3)
    {//Coder for file
        char R[MAX];
        FILE *fp = fopen("Coder.txt", "r");
        fscanf(fp, "%[^\n]", &R);  //The "%[^\n]" solves the problem of scan until the white space
        printf("The written text in the file:\n");
        printf("%s\n\n", R);

        int length;
        length = strlen(R);                                      /* Finding the length of the text that we wrote. */
        printf("Length of the text is: %d \n", length);

        printf("Translation:\n\t");
        char h;
    for (i=0; i<length; i++)                                /* Search loop for the codding. */
    {
        h = R[i];
        if      (h == 'A' || h == 'a'){printf(".-");}
        else if (h == 'B' || h == 'b'){printf("-...");}
        else if (h == 'C' || h == 'c'){printf("-.-.");}
        else if (h == 'D' || h == 'd'){printf("-..");}
        else if (h == 'E' || h == 'e'){printf(".");}
        else if (h == 'F' || h == 'f'){printf("..-.");}
        else if (h == 'G' || h == 'g'){printf("--.");}
        else if (h == 'H' || h == 'h'){printf("....");}
        else if (h == 'I' || h == 'i'){printf("..");}
        else if (h == 'J' || h == 'j'){printf(".---");}
        else if (h == 'K' || h == 'k'){printf("-.-");}
        else if (h == 'L' || h == 'l'){printf(".-..");}
        else if (h == 'M' || h == 'm'){printf("--");}
        else if (h == 'N' || h == 'n'){printf("-.");}
        else if (h == 'O' || h == 'o'){printf("---");}
        else if (h == 'P' || h == 'p'){printf(".--.");}
        else if (h == 'Q' || h == 'q'){printf("--.-");}
        else if (h == 'R' || h == 'r'){printf(".-.");}
        else if (h == 'S' || h == 's'){printf("...");}
        else if (h == 'T' || h == 't'){printf("-");}
        else if (h == 'U' || h == 'u'){printf("..-");}
        else if (h == 'V' || h == 'v'){printf("...-");}
        else if (h == 'W' || h == 'w'){printf(".--");}
        else if (h == 'X' || h == 'x'){printf("-..-");}
        else if (h == 'Y' || h == 'y'){printf("-.--");}
        else if (h == 'Z' || h == 'z'){printf("--..");}
        else if (h == '0'){printf("-----");}
        else if (h == '1'){printf(".----");}
        else if (h == '2'){printf("..---");}
        else if (h == '3'){printf("...--");}
        else if (h == '4'){printf("....-");}
        else if (h == '5'){printf(".....");}
        else if (h == '6'){printf("-....");}
        else if (h == '7'){printf("--...");}
        else if (h == '8'){printf("---..");}
        else if (h == '9'){printf("----.");}
        else if (h == '&'){printf(".-...");}
        else if (h == '"'){printf(".-..-.");}
        else if (h == '@'){printf(".--.-.");}
        else if (h == '('){printf("-.--.");}
        else if (h == ')'){printf("-.--.-");}
        else if (h == ':'){printf("---...");}
        else if (h == ','){printf("--..--");}
        else if (h == '='){printf("-...-");}
        else if (h == '!'){printf("-.-.--");}
        else if (h == '.'){printf(".-.-.-");}
        else if (h == '-'){printf("-....-");}
        else if (h == '+'){printf(".-.-.");}
        else if (h == '?'){printf("..--..");}
        else if (h == '/'){printf("-..-.");}
        else if (h == '_'){printf("..--.-");}
        else if (h == ';'){printf("-.-.-.");}
        else if (h == '\''){printf(".----.");}
        if      (h == ' '){printf("/");}
        printf(" ");                                            /* "/" between characters. */
    }
    fclose(fp);
    }

    else if (n == 4)
    {
        char I[MAX];
        FILE *fpr = fopen("Decoder.txt", "r");
        fscanf(fpr, "%[^\n]", &I);
        printf("Content of this file:\n");
        printf("%s\n\n", I);
        printf("Translation:\n\t");

        int okundu = 0;
        tree *gosterici;
        char gonder[7];  //Little string to send into the search function.6 because biggest possible Morse letter
        int ic = 0;
        int sayi = 0;
        while (I[okundu]!='\0') //Read until the end of the string
        {
            while (I[sayi]!=' ') // Read until the space
            {
                gonder[ic]=I[sayi];  //take the string into little string
                ++ic;
                ++sayi;
            }
            gosterici = searchLetter(root, gonder, 0);
            printf("%c", gosterici->letter);
            okundu = sayi+1;
            //gonder[0] = '\0';
            memset(gonder,0,strlen(gonder));
            ic = 0;
            sayi++;
        }
        fclose(fpr);
    }

    return 0;
}
