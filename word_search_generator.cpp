#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>


const int  num_rows=8;
const int num_of_words=10;
char word_search[num_rows*num_rows];
std::string list_of_words_added[num_of_words];
bool filled_spaces[num_rows*num_rows];
void create_new_word_search();
void add_new_word(int j);
int main()
{
     for(int w=0;w<1000;w++){
         create_new_word_search();
         for(int j=0;j<num_of_words;j++){
         add_new_word(j);
         }
    for(int i=0;i<num_of_words;i++){
        printf("\"");
        for(int j=0; j<list_of_words_added[i].length();j++){
            printf("%c", list_of_words_added[i][j]);
        }
        printf("\",");
    }
    //print puzzle
    printf("\"");
    for (int i=0;i<num_rows;i++){
        for(int j=0; j<num_rows;j++){
            printf("%c",word_search[num_rows*i+j]);
        }
        printf("\n");
    }
    printf("\",\n");
    }

return 0;
}
void create_new_word_search(){
char letters[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int p=0;p<num_rows;p++){
        for (int l=0;l<num_rows;l++){
            filled_spaces[num_rows*p+l]=false;
        }
    }
    for (int p=0;p<num_rows;p++){
        for(int h=0;h<num_rows;h++){
            int x = rand()%26;
            word_search[num_rows*p+h]=letters[x];
        }
    }
}
void add_new_word(int j){
 std::string list_all_words[62]={"feed",
    "title",
    "faith",
    "river",
    "count",
    "marry",
    "path",
    "shop",
    "folk",
    "lift",
    "jump",
    "limit",
    "worth",
    "warm",
    "soft",
    "gift",
    "speed",
    "cross",
    "youth",
    "wave",
    "broad",
    "deny",
    "twice",
    "suit",
    "blow",
    "cook",
    "burn",
    "shoe",
    "grade",
    "quiet",
    "dress",
    "aware",
    "bone",
    "chief",
    "wine",
    "below",
    "cool",
    "voter",
    "hell",
    "moral",
    "tour",
    "photo",
    "grab",
    "daily",
    "fair",
    "pair",
    "knee",
    "tape",
    "hire",
    "fully",
    "actor",
    "birth",
    "clean",
    "train",
    "lady",
    "neck",
    "lean",
    "tall",
    "plate",
    "hate",
    "male",
    "alive",
    };
    
    int x=rand()%5+6*j;
    std::string new_word_to_add=list_all_words[x];
    std::string type_of_position;
    int row_start;
    int column_start;
    int row_end;
    int column_end;

    x=rand()%4;
    if(x==0){
        type_of_position="horizontal";
        row_start=rand()%num_rows;
        column_start=rand()%(num_rows-new_word_to_add.length()+1);
        row_end=row_start;
        column_end=column_start+new_word_to_add.length()-1;
    }else if(x==1){
        type_of_position="vertical";
        row_start=rand()%(num_rows-new_word_to_add.length()+1);
        column_start=rand()%num_rows;
        row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start;
    }else if(x==2){
        type_of_position="diagonal_SE";
        row_start=rand()%(num_rows-new_word_to_add.length()+1);
        column_start=rand()%(num_rows-new_word_to_add.length()+1);
        row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start+new_word_to_add.length()-1;
    }else{
        type_of_position="diagonal_SO";
        row_start=rand()%(num_rows-new_word_to_add.length()+1);;
        column_start=num_rows-rand()%(num_rows-new_word_to_add.length()+1);
        row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start-new_word_to_add.length()+1;
    }
    bool is_reversed=false;
    x=rand()%2;
    if(x==1){
        is_reversed=true;
    }
    bool shocks=false;
    int limit_row=0;
    int limit_column=0;
    if(type_of_position=="horizontal"){
    for(int k=0; k<num_rows;k++){
        for(int l=0;l<num_rows;l++){
            row_start=row_start+k-limit_row;
            column_start=column_start+l-limit_column;
            if(row_start==num_rows){
                row_start=0;
                limit_row=k;
            }
            if(column_start==num_rows){
                column_start=0;
                limit_column=l;
            }
            row_end=row_start;
            column_end=column_start+new_word_to_add.length()-1;
            for (int i =0; i<new_word_to_add.length();i++){
        if(filled_spaces[row_start*num_rows+column_start+i]==1){
            if(is_reversed){
                if(new_word_to_add[new_word_to_add.length()-1-i]!=word_search[row_start*num_rows+column_start+i]){
                    shocks=true;
                }
            }else{
                if(new_word_to_add[i]!=word_search[row_start*num_rows+column_start+i]){
                    shocks=true;
                }
            }
        }
    }
    if(shocks==false){
        break;
    }
    }
    if(shocks==false){
        break;
    }
    }
    }else if(type_of_position=="vertical"){
for(int k=0; k<num_rows;k++){
        for(int l=0;l<num_rows;l++){
            row_start=row_start+k-limit_row;
            column_start=column_start+l-limit_column;
            if(row_start==num_rows){
                row_start=0;
                limit_row=k;
            }
            if(column_start==num_rows){
                column_start=0;
                limit_column=l;
            }
            row_end=row_start+new_word_to_add.length()-1;
            column_end=column_start;
            for (int i =0; i<new_word_to_add.length();i++){
        if(filled_spaces[(row_start+i)*num_rows+column_start]==1){
            if(is_reversed){
                if(new_word_to_add[new_word_to_add.length()-1-i]!=word_search[(row_start+i)*num_rows+column_start]){
                    shocks=true;
                }
            }else{
                if(new_word_to_add[i]!=word_search[(row_start+i)*num_rows+column_start]){
                    shocks=true;
                }
            }
        }
    }
    if(shocks==false){
        break;
    }
    }
    if(shocks==false){
        break;
    }
    }
    }else if(type_of_position=="diagonal_SE"){
for(int k=0; k<num_rows;k++){
        for(int l=0;l<num_rows;l++){
            row_start=row_start+k-limit_row;
            column_start=column_start+l-limit_column;
            if(row_start==num_rows){
                row_start=0;
                limit_row=k;
            }
            if(column_start==num_rows){
                column_start=0;
                limit_column=l;
            }
            row_end=row_start+new_word_to_add.length()-1;
            column_end=column_start+new_word_to_add.length()-1;
            for (int i =0; i<new_word_to_add.length();i++){
        if(filled_spaces[(row_start+i)*num_rows+column_start+i]==1){
            if(is_reversed){
                if(new_word_to_add[new_word_to_add.length()-1-i]!=word_search[(row_start+i)*num_rows+column_start+i]){
                    shocks=true;
                }
            }else{
                if(new_word_to_add[i]!=word_search[(row_start+i)*num_rows+column_start+i]){
                    shocks=true;
                }
            }
        }
    }
    if(shocks==false){
        break;
    }
    }
    if(shocks==false){
        break;
    }
    }
    }else if(type_of_position=="diagonal_SO"){
        for(int k=0; k<num_rows;k++){
        for(int l=0;l<num_rows;l++){
            row_start=row_start+k-limit_row;
            column_start=column_start+l-limit_column;
            if(row_start==num_rows){
                row_start=0;
                limit_row=k;
            }
            if(column_start==num_rows){
                column_start=0;
                limit_column=l;
            }
            row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start-new_word_to_add.length()+1;
            for (int i =0; i<new_word_to_add.length();i++){
        if(filled_spaces[(row_start+i)*num_rows+column_start-i]==1){
            if(is_reversed){
                if(new_word_to_add[new_word_to_add.length()-1-i]!=word_search[(row_start+i)*num_rows+column_start-i]){
                    shocks=true;
                }
            }else{
                if(new_word_to_add[i]!=word_search[(row_start+i)*num_rows+column_start-i]){
                    shocks=true;
                }
            }
        }
    }
    if(shocks==false){
        break;
    }
    }
    if(shocks==false){
        break;
    }
    }
    }



    if(shocks){
        add_new_word(j);
    }else{
    if(type_of_position=="horizontal"){
    if(is_reversed){
        for(int i=0; i<new_word_to_add.length();i++){
        word_search[num_rows*(row_start)+column_start+i]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(row_start)+column_start+i]=1;
    }
    }
    else{
    for(int i=0; i<new_word_to_add.length();i++){
        word_search[num_rows*(row_start)+column_start+i]=new_word_to_add[i];
        filled_spaces[num_rows*(row_start)+column_start+i]=1;
    }

    }
    }else if(type_of_position=="vertical"){
    if(is_reversed){
        for(int i=0; i<new_word_to_add.length();i++){
        word_search[num_rows*(row_start+i)+column_start]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(row_start+i)+column_start]=1;
    }
    }
    else{
    for(int i=0; i<new_word_to_add.length();i++){
        word_search[num_rows*(row_start+i)+column_start]=new_word_to_add[i];
        filled_spaces[num_rows*(row_start+i)+column_start]=1;
    }
    }
    }else if(type_of_position=="diagonal_SE"){
    if(is_reversed){
        for(int i=0; i<new_word_to_add.length();i++){
        word_search[num_rows*(row_start+i)+column_start+i]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(row_start+i)+column_start+i]=1;
    }
    }
    else{
    for(int i=0; i<new_word_to_add.length();i++){
        word_search[num_rows*(row_start+i)+column_start+i]=new_word_to_add[i];
        filled_spaces[num_rows*(row_start+i)+column_start+i]=1;
    }
    }
    }else if(type_of_position=="diagonal_SO"){
    if(is_reversed){
        for(int i=0; i<new_word_to_add.length();i++){
        word_search[num_rows*(row_start+i)+column_start-i]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(row_start+i)+column_start-i]=1;
    }
    }
    else{
    for(int i=0; i<new_word_to_add.length();i++){
        word_search[num_rows*(row_start+i)+column_start-i]=new_word_to_add[i];
        filled_spaces[num_rows*(row_start+i)+column_start-i]=1;
    }
    }
    }
    list_of_words_added[j]=new_word_to_add;
    
}
}
