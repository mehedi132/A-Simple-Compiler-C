/*
Name    : Mehedi Hasan
ID  : 180104132
Lab Group   : C2
Course No.  : CSE-4130
Course Title    : Formal Languages and Compilers Lab
Assignment No.  : 04
*/


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>


struct SymbolTable{
    int serial;
    char idName[100],idtype[100],scope[100],datatype[100],value[100];
}SymbolTable1[100];


int NumericDFA(char* lex)
{
    int i=0,l,s;

    if(isdigit(lex[i]))         s=1, i++;
    else if(lex[i]=='.')        s=2, i++;
    else s=0;

    l=strlen(lex);

    if(s==1)
    {
        for( ; i<l ; i++)
        {
            if(isdigit(lex[i]))      s=1;
            else 
            {
                if(lex[i]=='.') 
                {
                    s=2; i++; break;
                }        
                else 
                {
                    s=0; break;
                }
            }
        }
    }

    if(s==2)
    {
        if(isdigit(lex[i])) s=3, i++;      
        else    s=0;
    }
    if(s==3)
    {
        for( ; i<l ; i++) 
        {
            if(isdigit(lex[i])) s=3;
            else 
            {
                s=0; break;
            }
        }
    }

    if(s==3) s=1;
    return s;
}





int DetectDFA(char *lex)
{
    int i=0,l,s;

    if(isalpha(lex[i]))         s=1,i++;
    else s=0;

    if(s==1)
    {
        l = strlen(lex);

        for( ; i < l ; i++)
        {
            if(isalpha(lex[i]))     s=1;
            else
            {
                if(lex[i] == '_' || isdigit(lex[i]))
                {
                    s=2;
                }
                else   
                {
                    s=0;    break;
                }
            }
        }

        if(s==1)
        {      
            if(l == 1)  s = 2;  

            else if(l > 1 && l < 9)
            {           
                if( strcmp(lex,"do") == 0   || strcmp(lex,"if") == 0   || strcmp(lex,"int") == 0  || strcmp(lex,"for") == 0  || 
                    strcmp(lex,"char") == 0 || strcmp(lex,"case") == 0 || strcmp(lex,"else") == 0 || strcmp(lex,"auto") == 0 || 
                    strcmp(lex,"enum") == 0 || strcmp(lex,"goto") == 0 || strcmp(lex,"register") == 0 || strcmp(lex,"long") == 0 || 
                    strcmp(lex,"void") == 0 || strcmp(lex,"bool") == 0 || strcmp(lex,"unsigned") == 0 || strcmp(lex,"continue") == 0 || 
                    strcmp(lex,"const") == 0 || strcmp(lex,"float") == 0  || strcmp(lex,"short") == 0  || strcmp(lex,"union") == 0 || 
                    strcmp(lex,"while") == 0 || strcmp(lex,"typedef") == 0 || strcmp(lex,"default") == 0 || strcmp(lex,"volatile") == 0 ||
                    strcmp(lex,"double") == 0 || strcmp(lex,"struct") == 0 || strcmp(lex,"extern") == 0 || strcmp(lex,"return") == 0  || 
                    strcmp(lex,"signed") == 0 || strcmp(lex,"static") == 0 || strcmp(lex,"sizeof") == 0 || strcmp(lex,"break") == 0 )
                {
                    s = 1;
                }
                else   s = 2;
            }
            else s = 0;
        }
    }
    return s;
}













void InsertSymbolTable(int SearialNo, char IdName[100], char IdType[100], char DataType[100], char Scope[100], char Value[100])
{
    SymbolTable1[SearialNo].serial = SearialNo+1;               
    if(strcmp(IdName,"") != 0)    strcpy(SymbolTable1[SearialNo].idName   ,IdName);                
    if(strcmp(IdType,"") != 0)    strcpy(SymbolTable1[SearialNo].idtype ,IdType);
    if(strcmp(DataType,"") != 0)    strcpy(SymbolTable1[SearialNo].datatype    ,DataType);
    if(strcmp(Scope,"") != 0)    strcpy(SymbolTable1[SearialNo].scope   ,Scope);                
    if(strcmp(Value,"") != 0)    strcpy(SymbolTable1[SearialNo].value ,Value);

    //printf("New Data: %d %s %s %s %s %s\n\n",SearialNo+1,IdName,IdType,DataType,Scope,Value);
}


void UpdateSymbolTable(int SerialNo, int ColumnOfTable, char UpdateItem[100])
{
    if(ColumnOfTable == 2)  strcpy(SymbolTable1[SerialNo].idName,UpdateItem);
    else if(ColumnOfTable == 3)  strcpy(SymbolTable1[SerialNo].idtype,UpdateItem);
    else if(ColumnOfTable == 4)  strcpy(SymbolTable1[SerialNo].datatype,UpdateItem);
    else if(ColumnOfTable == 5)  strcpy(SymbolTable1[SerialNo].scope,UpdateItem);
    else if(ColumnOfTable == 6)  strcpy(SymbolTable1[SerialNo].value,UpdateItem);  
}


int SearchSymbolTable(int SerialNo, int ColumnOfTable, char SearchingItem[100])
{
    if(ColumnOfTable == 2 && strcmp(SymbolTable1[SerialNo].idName,SearchingItem) == 0)      return 0; 
    if(ColumnOfTable == 3 && strcmp(SymbolTable1[SerialNo].idtype,SearchingItem) == 0)      return 0;
    if(ColumnOfTable == 4 && strcmp(SymbolTable1[SerialNo].datatype,SearchingItem) == 0)    return 0;
    if(ColumnOfTable == 5 && strcmp(SymbolTable1[SerialNo].scope,SearchingItem) == 0)       return 0;
    if(ColumnOfTable == 6 && strcmp(SymbolTable1[SerialNo].value,SearchingItem) == 0)       return 0;

    return 1; 
}


void DisplaySymbolTable(int SerialNo)
{
    printf("SL. No.\tName\tID-Type\tData-Type\tScope\tValue\n\n");
    for(int i = 0 ; i < SerialNo ; i++)
    {
        printf("%d\t%s\t%s\t%s\t\t%s\t%s\n",SymbolTable1[i].serial,SymbolTable1[i].idName,SymbolTable1[i].idtype,SymbolTable1[i].datatype,SymbolTable1[i].scope,SymbolTable1[i].value);
    }
}

void DeleteSymbolTable(int SerialNo)
{

}


char* modify(char * x)
{
    if(strlen(x)==0)
        return x;
    if(x[0]>='0' && x[0]<='9')
        return x;
    return "";
}
















int main(void)
{



    /*------------------------------------------------------------------------------------------------------
    ///////////////////////////////////////////// Assignment-1 /////////////////////////////////////////////
    ------------------------------------------------------------------------------------------------------*/



    // Variables declaration //
    FILE *p1, *p2, *p3; 
    char c,StoringUserInput[20000];
    int LengthOfInput = 0;


    // Initializing the character array with ~ measure the input length after taking input //
    for(int i = 0 ; i < 20000 ; i++)    StoringUserInput[i]='~';


    // Taking user input until user enters '@' //
    printf("\nWrite a C program below (Enter @ to stop taking input):\n\n");
    scanf("%[^@]s",StoringUserInput);


    // Counting the length of the input // 
    //printf("\n\nGiven Input: \n");
    for(int i = 0 ; i < 2000 ; i++)    
    {
        if(StoringUserInput[i]=='~')   break;    //printf("%c",CodeInput[i]);  
        LengthOfInput++;
    }


    // Writing the input to a 'C' file //
    p1 = fopen("UserInputFile.c","w");
    for(int i = 0 ; i < LengthOfInput ; i++)        fputc(StoringUserInput[i],p1);
    fclose(p1);
    

    // Now reading from the C file to store it in another Text file //
    p1 = fopen("UserInputFile.c","r");
    p2 = fopen("1. User input from Console.txt","w");

    while((c = fgetc(p1)) != EOF)   fputc(c, p2);

    fclose(p1);
    fclose(p2);



    // Variables declaration //
    int flag = 0,index1 = 0,index2 = 0;
    char UI_Comments_NewLines_Removed[100000],UI_Lexemes_Separated[100000],TempArray[1000];  

    // Now fetching the user input from the C file to further process it 
    // by removing the comments, extra spaces and newlines and save it in a Text file
    p1 = fopen("UserInputFile.c","r");
    p2 = fopen("2. Comments and Newline removed.txt","w");

    // Fetching user input from the C file, stored in the array UI_Comments_NewLines_Removed[]
    LengthOfInput = 0;
    while((c = fgetc(p1)) != EOF)  UI_Comments_NewLines_Removed[LengthOfInput] = c,  LengthOfInput++;  

    // Process for removing newlines, comments
    for(int i = 0 ; i < LengthOfInput ; i++)
    {   
        // Comment removal process  
        if(i+1 < LengthOfInput) 
        {
            // Single line comment removal, if found '//' then skipping to the end of the line
            if(UI_Comments_NewLines_Removed[i] == '/' && UI_Comments_NewLines_Removed[i+1] == '/') 
            {
                for(int j = i ; j < LengthOfInput ; j++)
                {
                    if(UI_Comments_NewLines_Removed[j] == '\n')
                    {
                        i = j;  break;
                    }
                }
                continue;
            }
            // Multi line comment removal, if found '/*' then skipping characters until '*/' found
            else if(UI_Comments_NewLines_Removed[i] == '/' && UI_Comments_NewLines_Removed[i+1] == '*')
            {
                for(int j = i ; j<LengthOfInput-1 ; j++)
                {
                    if(UI_Comments_NewLines_Removed[j] == '*' && UI_Comments_NewLines_Removed[j+1] == '/')
                    {
                        i = j+1;  break;
                    }
                }
                continue;
            }
        }   

        // New line removal process
        if(UI_Comments_NewLines_Removed[i] == '\n')    
        {            
            // Skipping newlines
            for(int j = i+1 ; j<LengthOfInput ; j++)
            {
                //if(UI_Comments_NewLines_Removed[j] == '\n' || UI_Comments_NewLines_Removed[j] == ' ')   continue;
                if(UI_Comments_NewLines_Removed[j] == '\n')   continue;
                else
                {
                    i = j;    break;
                }
            }
            i--; continue;
        }
        
        // Keeping all the characters inside a double quotation marks e.g. ' "ab cd" '
        else if(UI_Comments_NewLines_Removed[i] == '"')   
        {
            fputc(UI_Comments_NewLines_Removed[i],p2);

            for(int j = i+1 ; j<LengthOfInput ; j++)
            {
                fputc(UI_Comments_NewLines_Removed[j],p2);
                if(UI_Comments_NewLines_Removed[j] == '"')    
                {                    
                    i = j;    break;
                }
            }
            continue;
        }   
        fputc(UI_Comments_NewLines_Removed[i],p2);
    }

    LengthOfInput = 0;

    fclose(p1);
    fclose(p2);

    
    // Reading the text file with comments and newlines removed and storing it to the array UI_Comments_NewLines_Removed[]
    p2 = fopen("2. Comments and Newline removed.txt","r");

    while((c = fgetc(p2)) != EOF)  UI_Comments_NewLines_Removed[LengthOfInput] = c,  LengthOfInput++;

    // Showing output with comments and newlines removed
    printf("\n\nOutput: \n\n");
    printf("\nAssignment-1\n-------------\n\n");
    printf("Step-1:\n-------\n");
    for(int i = 0 ; i<LengthOfInput ; i++)      printf("%c",UI_Comments_NewLines_Removed[i]);
    printf("\n\n--------------------------------------------------------------------------------------\n\n");



    /*------------------------------------------------------------------------------------------------------
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ------------------------------------------------------------------------------------------------------*/














    /*------------------------------------------------------------------------------------------------------
    ///////////////////////////////////////////// Assignment-2 /////////////////////////////////////////////
    ------------------------------------------------------------------------------------------------------*/



    // Now filtering for lexems separation
    for(int i = 0 ; i < LengthOfInput ; i++)
    {    
        // Checking if any relational operator found with dual characters ( <= , >= , != , ==)
        if((UI_Comments_NewLines_Removed[i] == '>' || UI_Comments_NewLines_Removed[i] == '<' || UI_Comments_NewLines_Removed[i] == '!' || UI_Comments_NewLines_Removed[i] == '=') && UI_Comments_NewLines_Removed[i+1] == '=')
        {
            // Giving a space if the previous character is not space
            if(UI_Comments_NewLines_Removed[i-1] != ' ' && UI_Lexemes_Separated[index1-1] != ' ')  
            {
                UI_Lexemes_Separated[index1] = ' ';
                index1++;
            }

            // Storing the relational character
            UI_Lexemes_Separated[index1] = UI_Comments_NewLines_Removed[i];            
            UI_Lexemes_Separated[index1+1] = UI_Comments_NewLines_Removed[i+1];          
            index1+=2; 

            // Giving a space if the previous and the next character is not space
            if(UI_Comments_NewLines_Removed[i+1] != ' ' && UI_Lexemes_Separated[index1-1] != ' ')  
            {
                UI_Lexemes_Separated[index1] = ' ';
                index1++;  
            }

            i++;
        }
        // If '#' character appears, it is a header file
        else if(UI_Comments_NewLines_Removed[i] == '#')
        {
            for(int j = i ; j < LengthOfInput ; j++)
            { 
                UI_Lexemes_Separated[index1] = UI_Comments_NewLines_Removed[j];         
                index1++;
                if(UI_Comments_NewLines_Removed[j] == '>')    
                {
                    i = j;
                    break;
                }
            }

            // Giving a space if the previous and the next character is not space
            if(UI_Comments_NewLines_Removed[i+1] != ' ' && UI_Lexemes_Separated[index1-1] != ' ')  
            {
                UI_Lexemes_Separated[index1] = ' ';
                index1++;  
            }
        }

        // Checking if any relational operator found with single characters
        else if( UI_Comments_NewLines_Removed[i] == ',' || UI_Comments_NewLines_Removed[i] == ';' || UI_Comments_NewLines_Removed[i] == '/' || UI_Comments_NewLines_Removed[i] == '+' || UI_Comments_NewLines_Removed[i] == '*' || UI_Comments_NewLines_Removed[i] == '-'
                || UI_Comments_NewLines_Removed[i] == '=' || UI_Comments_NewLines_Removed[i] == '<' || UI_Comments_NewLines_Removed[i] == '>' || UI_Comments_NewLines_Removed[i] == '"' || UI_Comments_NewLines_Removed[i] == '(' || UI_Comments_NewLines_Removed[i] == ')'
                || UI_Comments_NewLines_Removed[i] == '{' || UI_Comments_NewLines_Removed[i] == '}' || UI_Comments_NewLines_Removed[i] == '[' || UI_Comments_NewLines_Removed[i] == ']' || UI_Comments_NewLines_Removed[i] == 34  || UI_Comments_NewLines_Removed[i] == 39 )
        {
            // Giving a space if the previous character is not space
            if(UI_Comments_NewLines_Removed[i-1] != ' ' && UI_Lexemes_Separated[index1-1] != ' ')  
            {
                UI_Lexemes_Separated[index1] = ' ';
                index1++;
            }
            UI_Lexemes_Separated[index1] = UI_Comments_NewLines_Removed[i];
            index1++; 

            // Giving a space if the previous and the next character is not space
            if(UI_Comments_NewLines_Removed[i+1] != ' ' && UI_Lexemes_Separated[index1-1] != ' ')  
            {
                UI_Lexemes_Separated[index1] = ' ';
                index1++; 
            }
        }  
        // Else just store 
        else     
        {
            UI_Lexemes_Separated[index1] = UI_Comments_NewLines_Removed[i];
            index1++; 
        }
    }

    fclose(p1);
    fclose(p2);


    // Showing output with lexems separated
    printf("\nAssignment-2\n-------------\n\n");
    printf("Step-1:\n-------\n");
    
    // Writing the output in a text file
    p1 = fopen("3. Lexems Separated.txt","w");

    for(int i = 0 ; i < index1 ; i++)
    {
        printf("%c",UI_Lexemes_Separated[i]);
        fputc(UI_Lexemes_Separated[i],p1);  
    }
    fclose(p1);
    printf("\n\n\n");


    // Now writing to a text file, the tokenized form of the last input and showing the output
    p1 = fopen("4. User Input Tokenized.txt","w");

    printf("Step-2:\n-------\n");

    for(int i = 0 ; i < index1 ; i++)
    {    
        // Storing it into an array if the character is not a space
        if(UI_Lexemes_Separated[i] != ' ')    
        {
            TempArray[index2] = UI_Lexemes_Separated[i];
            index2++;
        }

        // Conditions for checking alphabet/digits/others
        else if(UI_Lexemes_Separated[i] == ' ')
        {    
            // If the word is digit then proceeding 
            if(isdigit(TempArray[0]))
            {
                // If number found then printing number
                if(NumericDFA(TempArray) == 1)
                {
                    fputc('[',p1); fputc('n',p1); fputc('u',p1); fputc('m',p1); fputc(' ',p1); 
                    
                    printf("[num ");   for(int j = 0 ; j < index2 ; j++)   printf("%c",TempArray[j]), fputc(TempArray[j],p1);
                    
                    printf("] ");   fputc(']',p1); fputc(' ',p1);
                }

                // else its Unknown
                else
                {
                    fputc('[',p1); fputc('u',p1); fputc('n',p1); fputc('k',p1); fputc('n',p1); fputc(' ',p1); 

                    printf("[unkn ");  for(int j = 0 ; j < index2 ; j++)   printf("%c",TempArray[j]), fputc(TempArray[j],p1);
                    
                    printf("] ");  fputc(']',p1); fputc(' ',p1);
                }
            }

            // If the word is alphabet then proceeding 
            else if(isalpha(TempArray[0]))
            {
                // If keyword found then printing keyword
                if(DetectDFA(TempArray) == 1)
                {
                    fputc('[',p1); fputc('k',p1); fputc('w',p1); fputc(' ',p1); 

                    printf("[kw ");    for(int j = 0 ; j < index2 ; j++)   printf("%c",TempArray[j]), fputc(TempArray[j],p1);
                    
                    printf("] ");  fputc(']',p1); fputc(' ',p1);
                }

                // else if variable found then its an ID
                else if(DetectDFA(TempArray) == 2)
                {
                    fputc('[',p1); fputc('i',p1); fputc('d',p1); fputc(' ',p1); 

                    printf("[id ");    for(int j = 0 ; j < index2 ; j++)   printf("%c",TempArray[j]), fputc(TempArray[j],p1);
                    
                    printf("] ");  fputc(']',p1); fputc(' ',p1);
                }

                // else it is Unknown
                else
                {
                    fputc('[',p1); fputc('u',p1); fputc('n',p1); fputc('k',p1); fputc('n',p1); fputc(' ',p1); 

                    printf("[unkn ");  for(int j = 0 ; j < index2 ; j++)   printf("%c",TempArray[j]), fputc(TempArray[j],p1);
                    
                    printf("] ");  fputc(']',p1); fputc(' ',p1);
                }
            }
            // If the word begins with '#' then proceeding
            else if(TempArray[0] == '#')
            {
                fputc('[',p1); fputc('h',p1); fputc('e',p1); fputc('a',p1); fputc('d',p1); fputc('e',p1); fputc('r',p1); fputc(' ',p1); 

                printf("[header ");  for(int j = 0 ; j < index2 ; j++)   printf("%c",TempArray[j]), fputc(TempArray[j],p1);
        
                printf("] ");  fputc(']',p1); fputc(' ',p1);
            }

            else if(index2 == 1)
            {
                // Conditions for separators
                if(TempArray[0] == ',' || TempArray[0] == ';' || TempArray[0] == '\'' || TempArray[0] == "\"")     
                {
                    fputc('[',p1); fputc('s',p1); fputc('e',p1); fputc('p',p1); fputc(' ',p1);  fputc(TempArray[0],p1); fputc(']',p1); fputc(' ',p1);
                    printf("[sep %c] ",TempArray[0]);
                }

                // Conditions for operators
                else if(TempArray[0] == '=' || TempArray[0] == '/' || TempArray[0] == '+' || TempArray[0] == '*' || TempArray[0] == '-' || TempArray[0] == '|' || TempArray[0] == '&')
                {
                    fputc('[',p1); fputc('o',p1); fputc('p',p1); fputc(' ',p1); fputc(TempArray[0],p1); fputc(']',p1); fputc(' ',p1);
                    printf("[op %c] ",TempArray[0]);
                }   

                // Conditions for parenthesis
                else if(TempArray[0] == '(' || TempArray[0] == ')')
                {
                    fputc('[',p1); fputc('p',p1); fputc('a',p1); fputc('r',p1); fputc(' ',p1); fputc(TempArray[0],p1); fputc(']',p1); fputc(' ',p1);
                    printf("[par %c] ",TempArray[0]);
                }  

                // Conditions for curly-braces
                else if(TempArray[0] == '{' || TempArray[0] == '}')
                {
                    fputc('[',p1); fputc('b',p1); fputc('r',p1); fputc('c',p1); fputc(' ',p1); fputc(TempArray[0],p1); fputc(']',p1); fputc(' ',p1);
                    printf("[brc %c] ",TempArray[0]); 
                } 

                // Conditions for brackets
                else if(TempArray[0] == '[' || TempArray[0] == ']')
                {
                    fputc('[',p1); fputc('b',p1); fputc('r',p1); fputc('c',p1); fputc('k',p1);fputc('t',p1); fputc(' ',p1); fputc(TempArray[0],p1); fputc(']',p1); fputc(' ',p1);
                    printf("[brckt %c] ",TempArray[0]);
                }  
            }
            else if(index2 >= 2)
            {
                // Conditions for operators
                if(TempArray[0] == '!' && TempArray[1] == '=' || 
                    TempArray[0] == '|' && TempArray[1] == '|' || 
                    TempArray[0] == '&' && TempArray[1] == '&' || 
                    TempArray[0] == '=' && TempArray[1] == '=' || 
                    TempArray[0] == '<' && TempArray[1] == '=' || 
                    TempArray[0] == '>' && TempArray[1] == '=')
                {
                    fputc('[',p1); fputc('o',p1); fputc('p',p1); fputc(' ',p1); fputc(TempArray[0],p1); fputc(TempArray[1],p1); fputc(']',p1); fputc(' ',p1);
                    printf("[op %c%c] ",TempArray[0],TempArray[1]); 
                }
            }

            index2 = 0;   memset(TempArray, 0, 1000);  
            // Clearing the TempArray after processing because we are storing every word separated by spaces in it.
        }  
    }
    printf("\n\n--------------------------------------------------------------------------------------\n\n");

    
    fclose(p1);
    fclose(p2);



    /*------------------------------------------------------------------------------------------------------
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ------------------------------------------------------------------------------------------------------*/














    /*------------------------------------------------------------------------------------------------------
    ///////////////////////////////////////////// Assignment-3 /////////////////////////////////////////////
    ------------------------------------------------------------------------------------------------------*/

    // Variables declared
    char Token_Names_Removed[90000], Id_Replaced_With_Serials[90000], Removed_Tokens[100][100];

    int index3 = 0,replaceIndex = 0, removedTokensIndex = 0;

    index2 = 0;   memset(TempArray, 0, 1000);  

    // Reading from the tokenized lexem file
    p1 = fopen("4. User Input Tokenized.txt","r");
    p2 = fopen("5. Token Names Removed.txt","w");

    // After complete recognition of all the lexemes only identifiers are kept in pairs for formation of Symbol Tables
    while((c = fgetc(p1)) != EOF)  
    {
        TempArray[index2] = c;
        index2++;

        // Inserting characters into TempArray[index2] until ']' found
        if(c == ']')
        {
            for(int j = 0 ; j < index2 ; j++)
            {
                // if 'kw' or 'op' found then skipping
                if(j+1 < index2 && (TempArray[j] == 'k' && TempArray[j+1] == 'w' || TempArray[j] == 'o' && TempArray[j+1] == 'p'))
                {
                    j++;
                }
                // if 'sep'/'num'/'par'/'brc' found then skipping
                else if( j+2 < index2 && 
                (TempArray[j] == 's' && TempArray[j+1] == 'e' && TempArray[j+2] == 'p' ||
                TempArray[j] == 'n' && TempArray[j+1] == 'u' && TempArray[j+2] == 'm' ||
                TempArray[j] == 'p' && TempArray[j+1] == 'a' && TempArray[j+2] == 'r' ||
                TempArray[j] == 'b' && TempArray[j+1] == 'r' && TempArray[j+2] == 'c') )
                {
                    j+=2;
                }
                // if 'unkn' found then skipping
                else if(j+3 < index2 && TempArray[j] == 'u' && TempArray[j+1] == 'n' && TempArray[j+2] == 'k' && TempArray[j+3] == 'n')
                {
                    j+=3;
                }
                // if 'brckt' found then skipping
                else if(j+4 < index2 && TempArray[j] == 'b' && TempArray[j+1] == 'r' && TempArray[j+2] == 'c' && TempArray[j+3] == 'k' && TempArray[j+4] == 't')
                {
                    j+=4;
                }
                // if 'header' found then skipping
                else if(j+5 < index2 && TempArray[j] == 'h' && TempArray[j+1] == 'e' && TempArray[j+2] == 'a' && TempArray[j+3] == 'd' && TempArray[j+4] == 'e' && TempArray[j+5] == 'r' )
                {
                    j+=5;
                } 
                // keeping the 'id'
                else
                {
                    // if 'id' found then keeping it
                    if(j+1 < index2 && TempArray[j] == 'i' && TempArray[j+1] == 'd')
                    {                    
                        Token_Names_Removed[index3] = TempArray[j];
                        Token_Names_Removed[index3+1] = TempArray[j+1];
                        Token_Names_Removed[index3+2] = ' ';                    
                        index3+=3;
                        j++;
                    }
                    // keeping every character except a space
                    else if(TempArray[j] != 32)
                    {
                        Token_Names_Removed[index3] = TempArray[j];
                        index3++;
                    }
                }                
            }    

            index2 = 0;   memset(TempArray, 0, 1000);  
        }
    }


    // Showing output of tokens without names except id
    printf("\nAssignment-3\n-------------\n\n");
    printf("Step-1:\n-------\n");

    for(int i = 0 ; i < index3 ; i++)
    {
        printf("%c",Token_Names_Removed[i]);
        fputc(Token_Names_Removed[i],p2);  
    }

    fclose(p1);
    printf("\n\n\n");

    


    // Variables declared

    int currentSL = 0,dataTypeFound = 0, idTypeFound = 0,index4 = 0, scope = 0, tokenIndex = 0;

    char idType[100],idName[100],dataType[100],value[100],TempArray1[100],currentScope[] = "global",Tokens[100][100],ScopeOfTokens[100][100];
    
    index2 = 0;   memset(TempArray, 0, 1000);



    // Generating the Symbol Table
    for(int i = 0 ; i < index3 ; i++)
    {
        // If characters found except '[' and ']'
        if(Token_Names_Removed[i] != ']' && Token_Names_Removed[i] != '[')
        {
            TempArray[index2] = Token_Names_Removed[i];
            index2++;
        }
        else
        {
            //printf("Current : %s.\n",TempArray);

            // Saving the immediate token and scope of the token of any identifier
            if(strcmp(TempArray,"") != 0 && TempArray[0] =='i' && TempArray[1] == 'd')
            {
                strcpy(Tokens[tokenIndex],TempArray);     
                strcpy(ScopeOfTokens[tokenIndex],currentScope);       
                tokenIndex++;
                //printf("1.Token: %s || Scope: %s || Index: %d\n\n",Tokens[tokenIndex-1],ScopeOfTokens[tokenIndex-1],tokenIndex-1); 
            }
            
            // If found any of the following datatypes then saving it to the string 'dataType'
            if(strcmp(TempArray,"int") == 0 || strcmp(TempArray,"float") == 0 || strcmp(TempArray,"double") == 0 ||
            strcmp(TempArray,"char") == 0 || strcmp(TempArray,"long") == 0 || strcmp(TempArray,"bool") == 0)
            {
                dataTypeFound = 1; 
                strcpy(dataType,TempArray);     
                //printf("Current data type: %s\n",dataType);
            }

            // if found any token having 'id'
            else if(TempArray[0] == 'i' && TempArray[1] == 'd')
            {
                index4 = 0; memset(TempArray1, 0, 100);

                idTypeFound = 1; 

                for(int j = 3 ; j < index2 ; j++)
                {
                    TempArray1[index4] = TempArray[j];  index4++;
                }

                strcpy(idName,TempArray1);     
                //printf("Current id: %s\n",idName);
            }

            // if any '}' found then it is global scope
            else if(strcmp(TempArray,"}") == 0)
            {
                strcpy(currentScope,"global");
            }
            
            else 
            {
                if(idTypeFound == 1 && dataTypeFound == 1)
                {
                    InsertSymbolTable(currentSL,idName,"",dataType,currentScope,""); 

                    //printf("Data : %d %s %s %s -----",currentSL+1,idName,dataType,currentScope);
                    //printf("%d %s %s %s ",SymbolTable1[currentSL].serial, SymbolTable1[currentSL].idName,SymbolTable1[currentSL].datatype, SymbolTable1[currentSL].scope);

                    if(strcmp(TempArray,";") == 0 || strcmp(TempArray,",") == 0 || strcmp(TempArray,")") == 0)
                    {
                        if(strcmp(TempArray,";") == 0 || strcmp(TempArray,")") == 0)  idTypeFound = dataTypeFound = 0;

                        if(strcmp(value,"") == 0)
                        {
                            strcpy(idType,"var");
                            UpdateSymbolTable(currentSL,3,idType);
                            //InsertSymbolTable(currentSL,idName,idType,dataType,currentScope,""); 
                            //printf("%s ",SymbolTable1[currentSL].idtype); 
                            currentSL++;
                        }
                    }

                    else if(strcmp(TempArray,"(") == 0)
                    {
                        strcpy(idType,"func");                         
                        UpdateSymbolTable(currentSL,3,idType);
                        //InsertSymbolTable(currentSL,idName,idType,dataType,currentScope,""); 
                        UpdateSymbolTable(currentSL,5,currentScope);
                        strcpy(currentScope,idName);
                        //printf("%s ",SymbolTable1[currentSL].idtype);
                        currentSL++;
                        idTypeFound = dataTypeFound = 0;
                    }


                    else if(strcmp(TempArray,"=") == 0)
                    {
                        index2 = 0; memset(TempArray, 0, 1000);
                        index4 = 0; memset(TempArray1, 0, 100);

                        strcpy(idType,"var");  
                        UpdateSymbolTable(currentSL,3,idType);

                        for(int j = i+2 ; j < index3 ; j++)
                        {
                            if(Token_Names_Removed[j] == ',' || Token_Names_Removed[j] == ';')
                            {
                                i = j;  break;
                            }
                            else if(j+1 < index3 && Token_Names_Removed[j] == 'i' && Token_Names_Removed[j+1] == 'd')
                            {
                                index4 = 0; memset(TempArray1, 0, 100);
                                for(int h = j ; h < index3 ; h++)
                                {
                                    if(Token_Names_Removed[h] == '[' || Token_Names_Removed[h] == ']' ||
                                    Token_Names_Removed[h] == '-' || Token_Names_Removed[h] == '*' ||  
                                    Token_Names_Removed[h] == '/' || Token_Names_Removed[h] == '+' )   break;
                                    
                                    TempArray1[index4] = Token_Names_Removed[h];     index4++;
                                }
                                //printf("Varible type token found: %s\n",TempArray1);
                                strcpy(Tokens[tokenIndex],TempArray1);     
                                strcpy(ScopeOfTokens[tokenIndex],currentScope);       
                                tokenIndex++;                            
                                index4 = 0; memset(TempArray1, 0, 100);

                                j+=2;
                            }
                            else if(Token_Names_Removed[j] != '[' && Token_Names_Removed[j] != ']' &&
                            (Token_Names_Removed[j] >= 'A' && Token_Names_Removed[j] <= 'Z' ||
                            Token_Names_Removed[j] >= 'a' && Token_Names_Removed[j] <= 'z' ||
                            Token_Names_Removed[j] >= '0' && Token_Names_Removed[j] <= '9' || Token_Names_Removed[j] == '.' ||
                            Token_Names_Removed[j] == '+' || Token_Names_Removed[j] == '-' || Token_Names_Removed[j] == '*' ||
                            Token_Names_Removed[j] == '/' ))
                            {
                                TempArray[index2] = Token_Names_Removed[j];     index2++;
                            }
                        }

                        strcpy(value,TempArray);
                        UpdateSymbolTable(currentSL,6,value);
                        //InsertSymbolTable(currentSL,idName,idType,dataType,currentScope,""); 
                        //printf("%s ",SymbolTable1[currentSL].value); 
                        memset(value, 0, 100);                                              
                        currentSL++;
                                                  
                    }
                    //printf("%s %s\n\n",idType,value);
                }




                else if(idTypeFound == 1 && dataTypeFound == 0)
                {
                    if(strcmp(TempArray,"=") == 0)
                    {
                        index2 = 0; memset(TempArray, 0, 1000);
                        index4 = 0; memset(TempArray1, 0, 100);

                        strcpy(idType,"var");  
                        UpdateSymbolTable(currentSL,3,idType);

                        for(int j = i+2 ; j < index3 ; j++)
                        {
                            if(Token_Names_Removed[j] == ',' || Token_Names_Removed[j] == ';')
                            {
                                i = j;  break;
                            }
                            else if(j+1 < index3 && Token_Names_Removed[j] == 'i' && Token_Names_Removed[j+1] == 'd')
                            {
                                index4 = 0; memset(TempArray1, 0, 100);
                                for(int h = j ; h < index3 ; h++)
                                {
                                    if(Token_Names_Removed[h] == '[' || Token_Names_Removed[h] == ']' ||
                                    Token_Names_Removed[h] == '-' || Token_Names_Removed[h] == '*' ||  
                                    Token_Names_Removed[h] == '/' || Token_Names_Removed[h] == '+' )   break;
                                    
                                    TempArray1[index4] = Token_Names_Removed[h];     index4++;
                                }
                                //printf("\nVarible type token found: %s\n",TempArray1);
                                strcpy(Tokens[tokenIndex],TempArray1);     
                                strcpy(ScopeOfTokens[tokenIndex],currentScope);       
                                tokenIndex++;                            
                                index4 = 0; memset(TempArray1, 0, 100);

                                j+=2;
                            }
                            else if(Token_Names_Removed[j] != '[' && Token_Names_Removed[j] != ']' && 
                            Token_Names_Removed[j] != 'i' && Token_Names_Removed[j+1] != 'd' &&  (
                            Token_Names_Removed[j] >= '(' && Token_Names_Removed[j] <= ')' ||
                            Token_Names_Removed[j] >= '{' && Token_Names_Removed[j] <= '}' ||
                            Token_Names_Removed[j] >= 'A' && Token_Names_Removed[j] <= 'Z' ||
                            Token_Names_Removed[j] >= 'a' && Token_Names_Removed[j] <= 'z' ||
                            Token_Names_Removed[j] >= '0' && Token_Names_Removed[j] <= '9' || Token_Names_Removed[j] == '.' ||
                            Token_Names_Removed[j] == '+' || Token_Names_Removed[j] == '-' || Token_Names_Removed[j] == '*' ||
                            Token_Names_Removed[j] == '/'))
                            {
                                TempArray[index2] = Token_Names_Removed[j];     index2++;
                            }
                        }

                        for(int k = 0 ; k < currentSL ; k++)
                        {                                
                            if(SearchSymbolTable(k,5,currentScope) == 0 && SearchSymbolTable(k,2,idName) == 0)
                            {
                                strcpy(value,TempArray);
                                strcpy(idType,"var");                        
                                UpdateSymbolTable(k,6,value);
                                UpdateSymbolTable(k,3,idType);
                                //printf("%s %s\n",SymbolTable1[k].idtype,SymbolTable1[k].value);
                                idTypeFound = 0;
                                memset(value, 0, 100);
                                break;
                            }
                        }                        
                        idTypeFound = dataTypeFound = 0;                       
                    }               
                }
            }
            //printf("\n");
            memset(TempArray, 0, 1000);  index2 = 0; 
        }
    }

    printf("Step-2:\n-------\n\nSymbol Table:\n------------\n");
    DisplaySymbolTable(currentSL);


    printf("\n\n");

    removedTokensIndex = 0;
    index4 = 0; memset(TempArray1, 0, 100);            

    for(int j = 0 ; j < index3 ; j++)
    {
        if(Token_Names_Removed[j] != '[' && Token_Names_Removed[j] != ']')
        {
            TempArray1[index4++] = Token_Names_Removed[j];
        }
        else if(Token_Names_Removed[j] == ']')
        {
            strcpy(Removed_Tokens[removedTokensIndex],TempArray1);
            removedTokensIndex++; 
            index4 = 0; memset(TempArray1, 0, 100);            
        }
    }


    tokenIndex = 0;  

    int temp1 = 0, temp2 = 0, temp3 = 0;
    char submit[20];

    printf("Step-4:\n-------\n");

    for(int i = 0 ; i < removedTokensIndex ; i++)
    {
        //printf("Token: %s --> %s ",Tokens[tokenIndex],Removed_Tokens[i]);
        if(Removed_Tokens[i][0] == 'i' && Removed_Tokens[i][1] == 'd' && strcmp(Removed_Tokens[i],Tokens[tokenIndex]) == 0)
        {
            //printf("Token: %s --> %s ",Tokens[tokenIndex],Removed_Tokens[i]);

            memset(idName, 0, 100);
            strcpy(currentScope,ScopeOfTokens[tokenIndex]);    
            index4 = 0;

            for(int k = 3 ; k < strlen(Removed_Tokens[i]) ; k++)     
            {
                idName[k-3] = Removed_Tokens[i][k];
            }

            for(int k = 0 ; k < currentSL ; k++)
            {                             
                if(strcmp(SymbolTable1[k].idName,idName) == 0)
                {
                    if(strcmp(SymbolTable1[k].scope,currentScope) == 0 || 
                    strcmp(SymbolTable1[k].idName,"main") != 0 && strcmp(SymbolTable1[k].idtype,"func") == 0)
                    {
                        //printf("Id Name: %s --> %s and scope: %s --> %s\n\n",SymbolTable1[k].idName,idName,SymbolTable1[k].scope,currentScope);

                        memset(Removed_Tokens[i], 0, 100);

                        Removed_Tokens[i][0] = 'i';
                        Removed_Tokens[i][1] = 'd';
                        Removed_Tokens[i][2] = ' ';

                        temp2 = 0;
                        temp3 = k+1;
                        
                        while(temp3 > 0)
                        {
                            temp1 = temp3%10;
                            temp3/=10;
                            submit[temp2] = temp1+48;
                            temp2++;
                        }   

                        temp3 = 3; 

                        while(temp2 > 0)
                        {
                            Removed_Tokens[i][temp3] = submit[temp2-1];
                            temp3++;
                            temp2--;
                        } 

                        break;
                    }
                }
            }
            tokenIndex++; //printf("\n"); 
        }
        //printf("\n");
    }

    

    for(int i = 0 ; i < removedTokensIndex ; i++)
    {
        printf("[%s]",Removed_Tokens[i]);
    }
    printf("\n\n--------------------------------------------------------------------------------------\n\n");




    /*------------------------------------------------------------------------------------------------------
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ------------------------------------------------------------------------------------------------------*/


















    /*------------------------------------------------------------------------------------------------------
    ///////////////////////////////////////////// Assignment-4 /////////////////////////////////////////////
    ------------------------------------------------------------------------------------------------------*/

    
    
    
    p1 = fopen("1. User input from Console.txt","r");
    p2 = fopen("Intermediate Output.txt","w");
    p3 = fopen("Detected Errors.txt","w");

    char User_Input_File[1000][1000],TempArray2[1000],TempArray3[1000];
    
    int index5 = 0, singleComment = 0 , multiComment = 0;

    while(fgets(User_Input_File[index5],500,p1))
    {
        int sizeOfLine = strlen(User_Input_File[index5]);

        singleComment = 0;

        for(int j = 0 ; j < sizeOfLine ; j++)
        {
            if(j+1<sizeOfLine)
            {
                if(User_Input_File[index5][j]=='/' && User_Input_File[index5][j+1]=='/')
                {
                    User_Input_File[index5][j]  = User_Input_File[index5][j+1]  = ' ';
                    singleComment = 1;    j++;
                }
                else if(User_Input_File[index5][j]=='/' && User_Input_File[index5][j+1]=='*')
                {
                    User_Input_File[index5][j] = User_Input_File[index5][j+1]  =' ';
                    multiComment = 1;     j++;
                }
                else if(User_Input_File[index5][j]=='*' && User_Input_File[index5][j+1]=='/')
                {
                    User_Input_File[index5][j]  = User_Input_File[index5][j+1] = ' ';
                    multiComment = 0;     j++;
                }
            }
            if(singleComment == 1 || multiComment == 1 || User_Input_File[index5][0] == '\n')
            {
                User_Input_File[index5][j]  = ' ';
            }

        }
        index5++;
    }




    for(int k = 1 ; k < index5 ; k++)
    {
        int flag = 0, n = strlen(User_Input_File[k]), singleQuoteOn = 0;
        temp3 = 0;
        
        strcpy(TempArray2,User_Input_File[k]);

        for(int i = 0 ; i < n ; i++)
        {
            if(TempArray2[i] == ',' || TempArray2[i] == ';' || TempArray2[i] == 39 || TempArray2[i] == 34)
            {
                if(TempArray2[i]=='\'')
                {
                    if(singleQuoteOn)
                    {
                        singleQuoteOn = 0;
                        TempArray3[temp3++]  = ' ';   TempArray3[temp3++]  = TempArray2[i];
                    }
                    else
                    {
                        TempArray3[temp3++]  = TempArray2[i];   TempArray3[temp3++]  = ' ';
                        singleQuoteOn = 1;
                    }
                }
                else
                {
                    TempArray3[temp3++]  = ' ';
                    TempArray3[temp3++]  = TempArray2[i];
                }
                TempArray3[temp3++]  = ' ';
            }


            else if(TempArray2[i] == '=' || TempArray2[i] == '/' || TempArray2[i] == '+' || 
                TempArray2[i] == '<' || TempArray2[i] == '>' || TempArray2[i] == '*' || 
                TempArray2[i] == '-' || TempArray2[i] == '|' || TempArray2[i] == '&')
            {
                if(TempArray2[i] == '!' && TempArray2[i+1] == '=' ||  TempArray2[i] == '|' && TempArray2[i+1] == '|' || 
                    TempArray2[i] == '&' && TempArray2[i+1] == '&' || TempArray2[i] == '=' && TempArray2[i+1] == '=' || 
                    TempArray2[i] == '<' && TempArray2[i+1] == '=' || TempArray2[i] == '>' && TempArray2[i+1] == '=')
                {
                    TempArray3[temp3++]  = ' ';
                    TempArray3[temp3++]  = TempArray2[i];
                    TempArray3[temp3++]  = TempArray2[i+1];
                    TempArray3[temp3++]  = ' ';
                    i++;
                }
                else
                {
                    TempArray3[temp3++]  = ' ';
                    TempArray3[temp3++]  = TempArray2[i];
                    TempArray3[temp3++]  = ' ';
                }
                flag = 1;
            }
            else if(isdigit(TempArray2[i]) == 1)
            {
                if(flag == 0)
                {
                    flag = 1;
                    TempArray3[temp3++]  = ' ';
                }
                TempArray3[temp3++]  = TempArray2[i];
            }
            else if(TempArray2[i] == '(' || TempArray2[i] == ')' || TempArray2[i] == '{' || TempArray2[i] == '}' || TempArray2[i] == '[' || TempArray2[i] == ']')
            {
                TempArray3[temp3++]  = ' ';
                TempArray3[temp3++]  = TempArray2[i];
                if(TempArray2[i]!=')' || TempArray2[i]!='}' || TempArray2[i]!=']')        TempArray3[temp3++]  = ' ';
            }
            else
            {
                flag = 1;
                TempArray3[temp3++]  = TempArray2[i];
            }
        }
        TempArray3[temp3-1]  = ' ';
        TempArray3[temp3] = '\0';

        strcpy(User_Input_File[k],TempArray3);
    }


    // Showing output of tokens without names except id
    printf("\nAssignment-4\n-------------\n\n");
    printf("Step-1:\n-------\n");

    for(int i = 0 ; i < index5 ; i++)
    {
        printf("%d.%s\n",i+1,User_Input_File[i]);
    }
    printf("\n\n");




    char TokenDetails[70][70][120],PreviousToken[100];

    int SerialIndex[10000], TokenPerLine[1000], Parenthesis = 0, CurlyBraces = 0, IfFound = 0, SemiColonFound = 0, ForLoopSemiColon = 0, TokenPerLineIndex = 0;;

    currentSL = 0;

    for(int k = 0 ; k < index5 ; k++)
    {
        memset(PreviousToken,0,100);

        temp3 = temp2 = ForLoopSemiColon = TokenPerLineIndex = 0;

        fprintf(p2,"%d ",k+1);

        strcpy(TempArray3,User_Input_File[k]);

        for(int i = 0 ; i < strlen(TempArray3) ; i++)
        {
            if(TempArray3[i] == ' ')
            {
                TempArray2[temp2++] = '\0';

                if(strlen(TempArray2) == 0)
                {
                    temp2 = 0;
                    continue;
                }

                if(strcmp(TempArray2,";") == 0 || strcmp(TempArray2,",") == 0 || strcmp(TempArray2,"\"") == 0 || strcmp(TempArray2,"\'") == 0)
                {
                    fprintf(p2,"sep %s ",TempArray2);

                    if(strcmp(TempArray2,";") == 0)
                    {
                        SemiColonFound = 1;

                        if(ForLoopSemiColon == 2 || ForLoopSemiColon == 3)     
                        {
                            ForLoopSemiColon++;
                        }
                        else if(ForLoopSemiColon >= 4)
                        {
                            fprintf(p3,"Only two semicolon in for loop at line %d\n",k+1);
                        }
                        else if(strcmp(TempArray2,PreviousToken) == 0)
                        {
                            fprintf(p3,"Duplicate token at line %d\n",k+1);
                        }
                    }
                    else if(strcmp(TempArray2,PreviousToken)==0)
                    {
                        fprintf(p3,"Duplicate token at line %d\n",k+1);
                    }
                    strcpy(TokenDetails[k][TokenPerLineIndex++],TempArray2);
                }


                else if(DetectDFA(TempArray2) == 1)
                {
                    fprintf(p2,"kw %s ",TempArray2);

                    if(strcmp(TempArray2,"if") == 0)
                    {
                        IfFound = 1;
                        SemiColonFound = 0;
                    }
                    else if(strcmp(TempArray2,"else") == 0)
                    {
                        if(IfFound == 0 || SemiColonFound != 1)
                        {
                            fprintf(p3,"'else' without a previous 'if' at line %d\n",k+1);
                        }
                        else IfFound  = 0;
                    }
                    else if(strcmp(TempArray2,"for") == 0)
                    {
                        ForLoopSemiColon = 1;
                    }

                    if(strcmp(TempArray2,PreviousToken)==0)
                    {
                        fprintf(p3,"Duplicate token at line %d\n",k+1);
                    }
                    strcpy(TokenDetails[k][TokenPerLineIndex++],TempArray2);

                }


                else if(DetectDFA(TempArray2) == 2)
                {
                    fprintf(p2,"id %s ",TempArray2);
                    if(strcmp(TempArray2,PreviousToken) == 0)
                    {
                        fprintf(p3,"Duplicate token at line %d\n",k+1);
                    }
                    strcpy(TokenDetails[k][TokenPerLineIndex++],"id");
                    strcpy(TokenDetails[k][TokenPerLineIndex++],TempArray2);
                }


                else if(strcmp(TempArray2,"=") == 0 || strcmp(TempArray2,"/") == 0 || strcmp(TempArray2,"+") == 0 || 
                strcmp(TempArray2,"*") == 0  || strcmp(TempArray2,"-") == 0  || strcmp(TempArray2,"|") == 0  || 
                strcmp(TempArray2,"&") == 0  || strcmp(TempArray2,"<") == 0  || strcmp(TempArray2,">") == 0  ||
                strcmp(TempArray2,">=") == 0 || strcmp(TempArray2,"<=") == 0 || strcmp(TempArray2,"||") == 0 || 
                strcmp(TempArray2,"!=") == 0 || strcmp(TempArray2,"&&") == 0)
                {
                    fprintf(p2,"op %s ",TempArray2);
                    strcpy(TokenDetails[k][TokenPerLineIndex++],TempArray2);
                }


                else if(strcmp(TempArray2,"(") == 0 || strcmp(TempArray2,")") == 0)
                {
                    fprintf(p2,"par %s ",TempArray2);

                    if(strcmp(TempArray2,"(") == 0)
                    {
                        Parenthesis++;
                        if(ForLoopSemiColon == 1)        
                        {
                            ForLoopSemiColon++;
                        }
                    }
                    else
                    {
                        if(ForLoopSemiColon > 0 && ForLoopSemiColon < 4)
                        {
                            fprintf(p3,"Expected ; in for loop at line %d\n",k+1);
                        }
                        else if(Parenthesis == 0)    
                        {
                            fprintf(p3,"Misplaced ) at line %d\n",k+1);
                        }
                        else
                        {
                            Parenthesis--;   
                            if(ForLoopSemiColon > 0)         
                            {
                                ForLoopSemiColon = 0;
                            }
                        }
                    }
                    strcpy(TokenDetails[k][TokenPerLineIndex++],TempArray2);
                }


                else if(strcmp(TempArray2,"{") == 0 || strcmp(TempArray2,"}") == 0)
                {
                    fprintf(p2,"brc %s ",TempArray2);

                    if(strcmp(TempArray2,"{")==0)       
                    {
                        CurlyBraces++;
                    }
                    else
                    {
                        if(CurlyBraces == 0)    
                        {
                            fprintf(p3,"Misplaced } at line %d\n",k+1);
                        }
                        else CurlyBraces--;
                    }
                    strcpy(TokenDetails[k][TokenPerLineIndex++],TempArray2);
                }

                
                else if(NumericDFA(TempArray2) == 1)
                {
                    fprintf(p2,"num %s ",TempArray2);
                    strcpy(TokenDetails[k][TokenPerLineIndex++],TempArray2);
                }


                else
                {
                    fprintf(p2,"unkn %s ",TempArray2);
                    fprintf(p3,"Undeclared/Unknown %s at line %d\n",TempArray2,k+1);
                    strcpy(TokenDetails[k][TokenPerLineIndex++],TempArray2);
                }

                temp2 = 0;

                strcpy(PreviousToken,TempArray2);

            }
            else
            {
                TempArray2[temp2++]  = TempArray3[i];
            }

        }

        fprintf(p2,"\n");

        TokenPerLine[k] =  TokenPerLineIndex;
    }

    while(CurlyBraces-- > 0)    fprintf(p3,"Expected } at line %d\n",index5);

    while(Parenthesis-- > 0)    fprintf(p3,"Expected ) at line %d\n",index5);    


    /*printf("\n\n\nToken Details: \n\n");

    for(int i = 0 ; i < 70 ; i++)
    {
        for(int j = 0 ; j < 70 ; j++)
        {
            printf("%s ",TokenDetails[i][j]);            
        }
        printf("\n");
    }
    printf("\n");printf("\n");*/


    int it = 0;

    char* CurrentScope = "global";

    for(int k = 0 ; k < index5 ; k++)
    {
        for(int i = 0 ; i < TokenPerLine[k] ; i++)
        {
            if(strcmp(TokenDetails[k][i],"id") == 0)
            {
                if(strcmp(TokenDetails[k][i+2],"(") == 0)
                {

                    if(strcmp(TokenDetails[k][i-1],"int") == 0 || strcmp(TokenDetails[k][i-1],"double")==0 || 
                    strcmp(TokenDetails[k][i-1],"float") == 0 || strcmp(TokenDetails[k][i-1],"char") == 0 || 
                    strcmp(TokenDetails[k][i-1],"void") == 0)
                    {
                        SerialIndex[it++]  = currentSL;
                        InsertSymbolTable(currentSL++,TokenDetails[k][i+1],"func",TokenDetails[k][i-1],CurrentScope,"");
                        CurrentScope = TokenDetails[k][i+1];
                        i+=2;
                    }

                    else
                    {
                        int Found  = -1;

                        for(int h = 0 ; h < currentSL ; h++)
                        {                                
                            if(SearchSymbolTable(h,3,"func") == 0 && SearchSymbolTable(h,5,"global") == 0 
                            && SearchSymbolTable(h,2,TokenDetails[k][i+1]) == 0)
                            {
                                Found = h;
                                break;
                            }
                        }                          

                        if(Found !=-1 )    SerialIndex[it++] = Found;

                        else fprintf(p3,"Expected declaration of function %s at line %d\n",TokenDetails[k][i+1],k+1);
                        
                        i+=2;
                    }
                }


                else if(strcmp(TokenDetails[k][i+2],"=") == 0)
                {
                    if(strcmp(TokenDetails[k][i-1],"int") == 0 || strcmp(TokenDetails[k][i-1],"double") == 0 || 
                    strcmp(TokenDetails[k][i-1],"float") == 0 || strcmp(TokenDetails[k][i-1],"char") == 0 )
                    {
                        int Found  = -1;

                        for(int h = 0 ; h < currentSL ; h++)
                        {                                
                            if(SearchSymbolTable(h,3,"var") == 0 && SearchSymbolTable(h,5,CurrentScope) == 0 && 
                            SearchSymbolTable(h,2,TokenDetails[k][i+1]) == 0)
                            {
                                Found = h;
                                break;
                            }
                        }  

                        if(Found == -1)
                        {
                            SerialIndex[it++]  = currentSL;
                            InsertSymbolTable(currentSL++,TokenDetails[k][i+1],"var",TokenDetails[k][i-1],CurrentScope,TokenDetails[k][i+3]);
                        }
                        else
                        {
                            fprintf(p3,"ID %s at line %d already declared in %s scope\n",TokenDetails[k][i+1],k+1,CurrentScope);
                        }
                    }
                    else
                    {
                        int Found  = -1;

                        for(int h = 0 ; h < currentSL ; h++)
                        {                                
                            if(SearchSymbolTable(h,3,"var") == 0 && SearchSymbolTable(h,5,CurrentScope) == 0 && 
                            SearchSymbolTable(h,2,TokenDetails[k][i+1]) == 0)
                            {
                                Found = h;
                                break;
                            }
                        }  

                        if(Found == -1)
                        {
                            fprintf(p3,"Expected declaration of %s at line %d\n",TokenDetails[k][i+1],k+1);
                        }
                        else
                        {
                            UpdateSymbolTable(Found,6,TokenDetails[k][i+3]);
                            SerialIndex[it++]  = Found;
                        }
                    }
                    i+=2;
                }


                else if(strcmp(TokenDetails[k][i+2],";") == 0 || strcmp(TokenDetails[k][i+2],",") == 0 || strcmp(TokenDetails[k][i+2],")") == 0 )
                {
                    
                    
                    if(strcmp(TokenDetails[k][i-1],"int") == 0 || strcmp(TokenDetails[k][i-1],"double") == 0 || 
                    strcmp(TokenDetails[k][i-1],"float") == 0 || strcmp(TokenDetails[k][i-1],"char") == 0 )
                    {
                        int Found  = -1;

                        for(int h = 0 ; h < currentSL ; h++)
                        {                                
                            if(SearchSymbolTable(h,3,"var") == 0 && SearchSymbolTable(h,5,CurrentScope) == 0 && 
                            SearchSymbolTable(h,2,TokenDetails[k][i+1]) == 0)
                            {
                                Found = h;
                                break;
                            }
                        }  

                        if(Found == -1)
                        {
                            SerialIndex[it++]  = currentSL;
                            InsertSymbolTable(currentSL++,TokenDetails[k][i+1],"var",TokenDetails[k][i-1],CurrentScope,"");
                        }
                        else fprintf(p3,"ID %s at line %d already declared in %s scope\n",TokenDetails[k][i+1],k+1,CurrentScope);
                        i+=2;
                    }
                   
                   
                    else
                    {
                        int Found  = -1;

                        for(int h = 0 ; h < currentSL ; h++)
                        {                                
                            if(SearchSymbolTable(h,3,"var") == 0 && SearchSymbolTable(h,5,CurrentScope) == 0 && SearchSymbolTable(h,2,TokenDetails[k][i+1]) == 0)
                            {
                                Found = h;
                                break;
                            }
                        }  

                        if(Found == -1)
                        {
                            int AgainFound  = -1;

                            if(CurrentScope != "global") 
                            {                            
                                for(int h = 0 ; h < currentSL ; h++)
                                {                                
                                    if(SearchSymbolTable(h,3,"var") == 0 && SearchSymbolTable(h,5,"global") == 0 && SearchSymbolTable(h,2,TokenDetails[k][i+1]) == 0)
                                    {
                                        AgainFound = h;
                                        break;
                                    }
                                } 
                            }

                            if(AgainFound == -1)
                            {
                                fprintf(p3,"Expected declaration of %s at line %d\n",TokenDetails[k][i+1],k+1);
                            }
                            else SerialIndex[it++]  = Found;
                        }
                        else SerialIndex[it++]  = Found;
                        
                        i+=2;
                    }


                }
            }
            else if(strcmp(TokenDetails[k][i],"}")==0)
            {
                CurrentScope = "global";
            }
        }
    }

    return 0;
}


/*

Input:

// A program fragment

float x1 = 3.125;

/* Definition of the function f1 (*)/

double f1(int x)
{
double z;
z = 0.01;
return z;
}

char lex(char pt)
{
    double Dx,Dy=1.29,Dz,De;
    Dx = 0.516;
    Dy = 0.47;
    Dz = Dx + Dy;
    return "Ok";
}

/* Beginning of 'main'

int main(void)
{

int n1; double z=14.6,Dz,hn;
n1=25; z=f1(n1); 
Dz = 129.32;
z = 1.5;
}

*/