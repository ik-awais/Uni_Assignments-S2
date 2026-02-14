#include <iostream>
#include <iomanip>
using namespace std;

int Display_Menu();
int StringLength(char *str);
void StringCopy(char *org, char*copied);

void StringConcatenate(char *str1, char *str2);
void CompressString(char *compress);
char *ReverseSentence(char *orgsentence);
void pluralWords(char **s, int wordCount);

int main()
{
    int choice;
    while (1)
    {
        choice = Display_Menu();
        if (choice != 0)
        {
            if (choice == 1)
            {
                char string1[] = "Pakistan";
                char string2[] = "My country is  ";
                StringConcatenate(string1, string2);
            }
            else if (choice == 2)
            {
                char string[] = "Muhammad Awais";
                CompressString(string);
            }
            else if (choice == 3)
            {
                char sentence[] = "My country is Pakistan ";
                char *reversedptr = ReverseSentence(sentence);
                for(int i = 0; (*(reversedptr + i)) != '\0'; i++)
                {
                    cout << *(reversedptr + i);
                }
                delete[] reversedptr;
            }
            else if (choice == 4)
            {
                int count = 3;
                char **words2D = new char* [count];
                for(int i = 0; i < count; i++)
                {
                    *(words2D + i) = new char[20]; //Allocates memory for words = count
                }
                char words[] = "Apple Box Cherry";
                int i = 0, j = 0, k = 0;
                while(*(words + i) != '\0')
                {
                    if(*(words + i) == ' ')
                    {
                        *(*(words2D + j)+ k) = '\0';
                        i++;
                        j++;
                        k = 0;
                    }
                    else
                    {
                        *(*(words2D + j) + k) = *(words + i);
                        k++;
                        i++; 
                    }         
                }
                *(*(words2D + j) + k) = '\0';
                pluralWords(words2D, count);
                for(int i = 0; i < count; i++)
                {
                    delete[] *(words2D + i); //Frees allocated memory of words
                }
                delete[] words2D; //Frees the double pointer

            }
            else
            {
                return 0;   
            }
        }
        else
        {
            cout << "Enter a valid choice." << endl;
        }
    }
    return 0;
}

int Display_Menu()
{
    int choice = 0;
    cout << "\n=======\tTEXT PROCESSING ENGINE\t=======" << endl;
    cout << "1. Merge two strings" << endl;
    cout << "2. Compress a string" << endl;
    cout << "3. Reverse a sentence" << endl;
    cout << "4. Convert singular words to plural" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
    {
        return choice;
    }
    else
    {
        return 0;
    }
}
int StringLength(char *str)
{
    int i = 0, size = 0;
    while (*(str + i) != '\0')
    {
        size++;
        i++;
    }
    return size;
}
void StringCopy(char *org, char*copied){
    int i;
    for(i = 0; *(org + i) != '\0'; i++)
    {
        *(copied + i) = *(org + i);
    }
    *(copied + i) = '\0';
}

void StringConcatenate(char *str1, char *str2)
{
    int size1 = StringLength(str1);
    int size2 = StringLength(str2);
    const int SIZE = size1 + size2;
    char *temp = str2;
    str2 = new char[SIZE + 1];
    int i = 0; 
    while(*(temp + i) != '\0')
    {
        *(str2 + i) = *(temp + i);
        i++;
    }
    i = 0;
    while(*(str1 + i) != '\0')
    {
        *(str2 + (size2 + i)) = *(str1 + i); 
        i++;
    }
    i = 0;
    while(1)
    {
        cout << *(str2 + i);
        if(i == SIZE)
        {   
            *(str2 + i) = '\0';
            cout << endl;
            break;
        }
        i++;
    }
    delete[] str2;
}
void CompressString(char *compress){
    int size = StringLength(compress);
    int i = 0, j, k;
    while (*(compress + i) != '\0')
    {
        j = i + 1;
        while(*(compress + j) != '\0')
        {
            if(*(compress + j) == *(compress + i))
            {
                k = j;
                while(*(compress + k) != '\0')
                {
                    *(compress + k) = *(compress + (k + 1));
                    k++;
                }
                j--;
            }
            j++;
        }
        j = i + 1;
        i++;
    }
    size = StringLength(compress);
    for(int i = 0; i < size; i++)
    {
        cout << *(compress + i);
    }
    cout << endl;
}
char *ReverseSentence(char *orgsentence){
    int size = StringLength(orgsentence);
    char *reversedSentence = new char[size + 1];
    int k = 0, temp = 0;
    for(int i = size - 1; i >= 0; i--)
    {
        if(*(orgsentence + i) == ' ')
        {
            temp = i;
            i++;
            while(1)
            {                 
                if(*(orgsentence + i) == '\0')
                {
                    *(reversedSentence + k) = ' ';
                    k++;
                    break;
                }  
                *(reversedSentence + k) = *(orgsentence + i);  
                k++;      
                i++;    
            }
            i = temp;
            *(orgsentence + i) = '\0';
        }
    } 
    int j = 0;
    while(*(orgsentence + j) != '\0')
    {
        *(reversedSentence + k) = *(orgsentence + j);
        k++;
        j++;
    }
    *(reversedSentence + k) = '\0';
    return reversedSentence;
}
void pluralWords(char **s, int wordCount){
    int *lettersCount = new int[wordCount];
    for(int i = 0; i < wordCount; i++)
    {
       *(lettersCount + i) = StringLength(*(s + i)); //Checks how long a word is
    }
    int lastChar, seclastChar, thirdlastChar;
    for(int i = 0; i < wordCount; i++)
    {   
        if(*(lettersCount + i) >= 2)
        {
            seclastChar = *(*(s + i) + (*(lettersCount + i) - 2));
        }
        else
        {
            seclastChar = '\0';
        }
        if(*(lettersCount + i) >= 3)
        {
            thirdlastChar = *(*(s + i) + (*(lettersCount + i) - 3));
        }
        else
        {
            thirdlastChar = '\0';
        }
        lastChar = *(*(s + i) + (*(lettersCount + i)) - 1);
        // Append 'es' if:
        if ((lastChar == 'h' && (seclastChar == 'c' || seclastChar == 's')) ||
        (lastChar == 'x') || (lastChar == 's' && seclastChar == 'i') || 
        ((lastChar == 's' || lastChar == 'z') && 
        (seclastChar != 'a' && seclastChar != 'e' && seclastChar != 'i' && seclastChar != 'o' && seclastChar != 'u')) ||
        (lastChar == 'o' && seclastChar == 't' && thirdlastChar == 'a')) 
        {
            char *plural = new char[*(lettersCount + i) + 3];
            int j;
                 for(j = 0; j < (*(lettersCount + i)); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i)) = 'e';
                *(plural + *(lettersCount + i) + 1) = 's';
                *(plural + *(lettersCount + i) + 2) = '\0';
                
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // Append 'zes' if:
        else if ((lastChar == 'z' && 
            (seclastChar == 'a' || seclastChar == 'e')))
        {
            char *plural = new char[*(lettersCount + i) + 4];
            int j;
                 for(j = 0; j < (*(lettersCount + i)); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i)) = 'z';
                *(plural + *(lettersCount + i) + 1) = 'e';
                *(plural + *(lettersCount + i) + 2) = 's';
                *(plural + *(lettersCount + i) + 3) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }    
        // Append 'ses' if:   
        else if((lastChar == 's' && 
            (seclastChar == 'a' || seclastChar == 'e')))   
        {
            char *plural = new char[*(lettersCount + i) + 4];
            int j;
                 for(j = 0; j < (*(lettersCount + i)); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i)) = 's';
                *(plural + *(lettersCount + i) + 1) = 'e';
                *(plural + *(lettersCount + i) + 2) = 's';
                *(plural + *(lettersCount + i) + 3) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // Append 's' if:
        else if((lastChar == 'f' && seclastChar == 'f'))
        {
            char *plural = new char[*(lettersCount + i) + 2];
            int j;
                 for(j = 0; j < (*(lettersCount + i)); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i)) = 's';
                *(plural + *(lettersCount + i) + 1) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // Replace last 2 characters with 've' and append 's' if:
        else if ((lastChar == 'f') || 
        (lastChar == 'e' && seclastChar == 'f'))
        {
            if (lastChar == 'f')
            {
            char *plural = new char[*(lettersCount + i) + 3];
            int j;
                 for(j = 0; j < (*(lettersCount + i) - 1); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i) - 1) = 'v';
                *(plural + *(lettersCount + i)) = 'e';
                *(plural + *(lettersCount + i) + 1) = 's';
                *(plural + *(lettersCount + i) + 2) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
            }
            else
            {
                char *plural = new char[*(lettersCount + i) + 1];
                int j;
                    for(j = 0; j < (*(lettersCount + i) - 2); j++)
                    {
                        *(plural + j) = *(*(s + i) + j);
                    }
                    *(plural + *(lettersCount + i) - 2) = 'v';
                    *(plural + *(lettersCount + i) - 1) = 'e';
                    *(plural + *(lettersCount + i)) = 's';
                    *(plural + *(lettersCount + i) + 1) = '\0';
                    delete[] *(s + i);
                    *(s + i) = plural;
            }           
        }
        // Replace last 2 characters with 'a' if:
        else if ((lastChar == 'n' && seclastChar == 'o'))
        {
            char *plural = new char[*(lettersCount + i)];
            int j;
                 for(j = 0; j < (*(lettersCount + i) - 2); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i) - 2) = 'a';
                *(plural + *(lettersCount + i) - 1) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // Replace last 2 characters with 'i' if:
        else if ((lastChar == 's' && seclastChar == 'u'))
        {
            char *plural = new char[*(lettersCount + i)];
            int j;
                 for(j = 0; j < (*(lettersCount + i) - 2); j++)
                 {
                    *(plural + j) = *(*(s + i) + j);
                 }
                *(plural + *(lettersCount + i) - 2) = 'i';
                *(plural + *(lettersCount + i) - 1) = '\0';
                delete[] *(s + i);
                *(s + i) = plural;
        }
        // 2 Cases:
        else if (lastChar == 'y')
        {
            // Append 's' if:
            if((lastChar == 'y' && 
            (seclastChar == 'a' || seclastChar == 'e' || seclastChar == 'i' ||
            seclastChar == 'o' || seclastChar == 'u')))
            {
                char *plural = new char[*(lettersCount + i) + 2];
                int j;
                    for(j = 0; j < (*(lettersCount + i)); j++)
                    {
                        *(plural + j) = *(*(s + i) + j);
                    }
                    *(plural + *(lettersCount + i)) = 's';
                    *(plural + *(lettersCount + i) + 1) = '\0';
                    delete[] *(s + i);
                    *(s + i) = plural;
            }
            // Replace last character with 'ies' if:
            else
            {
                char *plural = new char[*(lettersCount + i) + 3];
                int j;
                    for(j = 0; j < (*(lettersCount + i) - 1); j++)
                    {
                        *(plural + j) = *(*(s + i) + j);
                    }
                    *(plural + *(lettersCount + i) - 1) = 'i';
                    *(plural + *(lettersCount + i)) = 'e';
                    *(plural + *(lettersCount + i) + 1) = 's';
                    *(plural + *(lettersCount + i) + 2) = '\0';
                    delete[] *(s + i);
                    *(s + i) = plural;
            }
        }
        // For all other cases, append 's':
        else
        {
                char *plural = new char[*(lettersCount + i) + 2];
                int j;
                    for(j = 0; j < (*(lettersCount + i)); j++)
                    {
                        *(plural + j) = *(*(s + i) + j);
                    }
                    *(plural + *(lettersCount + i)) = 's';
                    *(plural + *(lettersCount + i) + 1) = '\0';
                    delete[] *(s + i);
                    *(s + i) = plural;
        }
    }
    cout << "\nPluraized words: ";
    for (int i = 0; i < wordCount; i++)
    {
        cout << *(s + i) << ' ';
    }
    cout << endl;
    delete[] lettersCount;
    
}