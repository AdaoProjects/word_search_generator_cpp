#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

std::string list_all_words[36]={
    "chief",
    "quiet",
    "dress",
    "aware",
    "grade",
    "twice",
    "broad",
    "limit",
    "worth",
    "below",
    "feed",
    "path",
    "shop",
    "folk",
    "lift",
    "jump",
    "warm",
    "soft",
    "gift",
    "wave",
    "deny",
    "suit",
    "blow",
    "cook",
    "burn",
    "shoe",
    "bone",
    "wine",
    "boy",
    "bad",
    "buy",
    "jet",
    "cat",
    "dog",
    "pig",
    "and",
    };

const int  num_rows=8;
const int num_of_words=12;
int restart_count_down;
char word_search[num_rows*num_rows];
int solution_pos[num_of_words][4];
bool list_of_is_reversed[num_of_words];
std::string list_of_type_pos[num_of_words];
std::string list_of_words_added[num_of_words];
bool filled_spaces[num_rows*num_rows];
void create_new_word_search();
void add_new_word(int u);
int main()
{
     for(int w=0;w<5;w++){
         create_new_word_search();
    for(int i=0;i<num_of_words;i++){
        printf("\"");
        for(int j=0; j<list_of_words_added[i].length();j++){
            printf("%c", list_of_words_added[i][j]);
        }
        printf("\",");
    }
    //print puzzle
    printf("\n\"");
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
    restart_count_down=0;
         for(int j=0;j<num_of_words;j++){
         add_new_word(j);
         }
}
void add_new_word(int u){
restart_count_down++;
    if(restart_count_down>100){
        create_new_word_search();
        return ;
    }
    int x=rand()%3+3*u;
    std::string new_word_to_add=list_all_words[x];
    std::string type_of_position;
    int row_start;
    int column_start;
    int row_end;
    int column_end;
    bool shocks;
    bool is_reversed;
    bool connection=false;
    if(u>0){
    for(int p=0;p<list_of_words_added[u-1].length();p++){
        for(int r=0;r<new_word_to_add.length();r++){
            if(list_of_words_added[u-1][p]==new_word_to_add[r]){
                if(list_of_type_pos[u-1]=="horizontal"){
                    if(list_of_is_reversed){
                    type_of_position="vertical";
                    is_reversed=false;
                    row_start=solution_pos[u-1][0]-r;
                    column_start=solution_pos[u-1][3]-p;
                    row_end=row_start+new_word_to_add.length()-1;
                    column_end=column_start;
                   for (int i =0; i<new_word_to_add.length();i++){
                if(filled_spaces[(row_start+i)*num_rows+column_start]==1){
                    if(is_reversed){
                        if(new_word_to_add[new_word_to_add.length()-1-i]!=word_search[(row_start+i)*num_rows        +column_start]){
                            shocks=true;
                        }
            }else{
                if(new_word_to_add[i]!=word_search[(row_start+i)*num_rows+column_start]){
                    shocks=true;
                }
            }
        }
    }
    if(row_start<0 || row_start>num_rows-new_word_to_add.length()){
        shocks=true;
    }
    if(shocks){
                    shocks=false;
                    row_start=solution_pos[u-1][0]+new_word_to_add.length()-1+r;
                    column_start=solution_pos[u-1][3]-p;
                    row_end=row_start+new_word_to_add.length()-1;
                    column_end=column_start;
                   for (int i =0; i<new_word_to_add.length();i++){
                if(filled_spaces[(row_start+i)*num_rows+column_start]==1){
                    if(is_reversed){
                        if(new_word_to_add[new_word_to_add.length()-1-i]!=word_search[(row_start+i)*num_rows        +column_start]){
                            shocks=true;
                        }
            }else{
                if(new_word_to_add[i]!=word_search[(row_start+i)*num_rows+column_start]){
                    shocks=true;
                }
            }
        }
    }
    if(row_start<0 || row_start>num_rows-new_word_to_add.length()){
        shocks=true;
    }
    }
                    }else{

                    }
    if(shocks){
        connection=false;
    }else{
        connection=true;
    }
                }
            }
            if(connection){
                break;
            }
        }
    if(connection){
        break;
    }
    }
    }

printf("\n%i\n",connection);
    if(!connection){
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
    is_reversed=false;
    x=rand()%2;
    if(x==1){
        is_reversed=true;
    }
    shocks=false;
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
                        if(new_word_to_add[new_word_to_add.length()-1-i]!=word_search[(row_start+i)*num_rows        +column_start]){
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

    }


    if(shocks){
        add_new_word(u);
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
    list_of_words_added[u]=new_word_to_add;
    solution_pos[u][0]=row_start;
    solution_pos[u][1]=column_start;
    solution_pos[u][2]=row_end;
    solution_pos[u][3]=column_end;
    list_of_is_reversed[u]=is_reversed;
    list_of_type_pos[u]=type_of_position;
}
}