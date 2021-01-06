#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
const short num_of_possibilites__words=10;
static std::string list_all_words[200]={
"rungs",
"runny",
"rural",
"rusty",
"saber",
"sable",
"sacks",
"sadly",
"safer",
"sages",
"purge",
"purse",
"pushy",
"pussy",
"putty",
"pylon",
"qatar",
"quack",
"quads",
"quake",
"notes",
"novas",
"novel",
"nudge",
"nukes",
"nurse",
"nutty",
"oasis",
"obese",
"obeys",
"axed",
"axel",
"axes",
"axis",
"axle",
"ayes",
"baba",
"babe",
"baby",
"bach",
"cusp",
"cute",
"cuts",
"dada",
"dads",
"daft",
"dale",
"damn",
"damp",
"dams",
"exes",
"exit",
"expo",
"eyed",
"eyes",
"face",
"fact",
"fade",
"fads",
"fail",
"guns",
"guru",
"guts",
"guys",
"hack",
"hail",
"hair",
"hajj",
"hale",
"half",
"isis",
"isle",
"itch",
"item",
"jack",
"jade",
"jail",
"jake",
"jams",
"jane",
"knox",
"kong",
"kook",
"kris",
"kyle",
"labs",
"lace",
"lack",
"lacy",
"lady",
"lust",
"lynn",
"lynx",
"lyon",
"mack",
"macs",
"made",
"mags",
"mail",
"main",
"pure",
"push",
"puts",
"quad",
"qual",
"quin",
"quit",
"quiz",
"race",
"rack",
"awe",
"aye",
"bad",
"bag",
"bah",
"ban",
"bar",
"bat",
"bay",
"bed",
"cry",
"cue",
"cum",
"cup",
"cur",
"cut",
"dad",
"dal",
"dam",
"dan",
"fun",
"fur",
"gad",
"gag",
"gan",
"gap",
"gar",
"gas",
"gay",
"gee",
"fun",
"fur",
"gad",
"gag",
"gan",
"gap",
"gar",
"gas",
"gay",
"gee",
    };

const short  num_rows=8;
const short num_of_words=15;
short restart_count_down;
char word_search[num_rows*num_rows];
short solution_pos[num_of_words][4];
std::string list_of_words_added[num_of_words];
bool filled_spaces[num_rows*num_rows];
void create_new_word_search();
void fit_words_connections();
void add_new_word(short u);
int main()
{
     for(short w=0;w<1000 ;w++){
         create_new_word_search();
         /*
         printf("[");
         for(short i=0;i<num_of_words;i++){
         printf("%i,%i,%i,%i,",solution_pos[i][0],solution_pos[i][1],solution_pos[i][2],solution_pos[i][3]);
         }
         printf("],\n");
        */

         printf("[");
    for(short i=0;i<num_of_words;i++){
        printf("\"");
        for(short j=0; j<list_of_words_added[i].length();j++){
            printf("%c", list_of_words_added[i][j]);
        }
        printf("\",");
    }
    printf("],\n");
  
   //prshort puzzle
   /*
    printf("[\"");
    for (short i=0;i<num_rows;i++){
        for(short j=0; j<num_rows;j++){
            printf("%c",word_search[num_rows*i+j]);
        }
    }
    printf("\"],\n");

    */
    }
return 0;
}
void create_new_word_search(){
char letters[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (short p=0;p<num_rows;p++){
        for (short l=0;l<num_rows;l++){
            filled_spaces[num_rows*p+l]=false;
        }
    }
    for (short p=0;p<num_rows;p++){
        for(short h=0;h<num_rows;h++){
            short x = rand()%26;
            word_search[num_rows*p+h]=letters[x];
        }
    }

    restart_count_down=0;
         for(short j=0;j<num_of_words;j++){
         add_new_word(j);
         }
}
void add_new_word(short u){
restart_count_down++;
    if(restart_count_down>500){
        create_new_word_search();
        return ;
    }
    short x=rand()%num_of_possibilites__words+num_of_possibilites__words*u;
    std::string new_word_to_add=list_all_words[x];
    std::string type_of_position;
    short row_start;
    short column_start;
    short row_end;
    short column_end;
    bool shocks;
    bool is_reversed;
    short length=new_word_to_add.length();

x=rand()%4;
switch(x) {
    case 0 :
        row_start=rand()%num_rows;
        column_start=rand()%(num_rows-new_word_to_add.length()+1);
        row_end=row_start;
        column_end=column_start+new_word_to_add.length()-1;
      break;
    case 1 :
        row_start=rand()%(num_rows-new_word_to_add.length()+1);
        column_start=rand()%num_rows;
        row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start;
      break; //op
      case 2 :
        row_start=rand()%(num_rows-new_word_to_add.length()+1);
        column_start=rand()%(num_rows-new_word_to_add.length()+1);
        row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start+new_word_to_add.length()-1;
      break; //op
      case 3 :
        row_start=rand()%(num_rows-new_word_to_add.length()+1);;
        column_start=num_rows-1-rand()%(num_rows-new_word_to_add.length()+1);
        row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start-new_word_to_add.length()+1;
      break; //op
};
    is_reversed=rand()%2;
    shocks=false;
    short limit_row=0;
    short limit_column=0;
    switch(x) {
    case 0 :
        for(short k=0; k<num_rows;k++){
        for(short l=0;l<num_rows;l++){
            row_start=row_start+k-limit_row;
            column_start=column_start+l-limit_column;
            if(row_start==num_rows){
                row_start=0;
                limit_row=k;
            }
            if(column_start==num_rows-new_word_to_add.length()+1){
                column_start=0;
                limit_column=l;
            }
            row_end=row_start;
            column_end=column_start+new_word_to_add.length()-1;
            for (short i =0; i<length;i++){
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
      break;
    case 1 :
        for(short k=0; k<num_rows;k++){
        for(short l=0;l<num_rows;l++){
            row_start=row_start+k-limit_row;
            column_start=column_start+l-limit_column;
            if(row_start==num_rows-new_word_to_add.length()+1){
                row_start=0;
                limit_row=k;
            }
            if(column_start==num_rows){
                column_start=0;
                limit_column=l;
            }
            row_end=row_start+new_word_to_add.length()-1;
            column_end=column_start;
            for (short i =0; i<length;i++){
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
      break; //op
      case 2 :
        for(short k=0; k<num_rows;k++){
        for(short l=0;l<num_rows;l++){
            row_start=row_start+k-limit_row;
            column_start=column_start+l-limit_column;
            if(row_start==num_rows-new_word_to_add.length()+1){
                row_start=0;
                limit_row=k;
            }
            if(column_start==num_rows-new_word_to_add.length()+1){
                column_start=0;
                limit_column=l;
            }
            row_end=row_start+new_word_to_add.length()-1;
            column_end=column_start+new_word_to_add.length()-1;
            for (short i =0; i<length;i++){
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
      break; //op
      case 3 :
         for(short k=0; k<num_rows;k++){
        for(short l=0;l<num_rows;l++){
            row_start=row_start+k-limit_row;
            column_start=column_start-l+limit_column;
            if(row_start==num_rows-new_word_to_add.length()+1){
                row_start=0;
                limit_row=k;
            }
            if(column_start==num_rows-new_word_to_add.length()-2){
                column_start=num_rows-1;
                limit_column=l;
            }
            row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start-new_word_to_add.length()+1;
            for (short i =0; i<length;i++){
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
      break; //op
};
   
    


    if(shocks){
        add_new_word(u);
    }else{
        switch(x) {
    case 0 :
        if(is_reversed){
        for(short i=0; i<length;i++){
        word_search[num_rows*(row_start)+column_start+i]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(row_start)+column_start+i]=1;
    }
    }
    else{
    for(short i=0; i<length;i++){
        word_search[num_rows*(row_start)+column_start+i]=new_word_to_add[i];
        filled_spaces[num_rows*(row_start)+column_start+i]=1;
    }

    }
      break;
    case 1 :
        if(is_reversed){
        for(short i=0; i<length;i++){
        word_search[num_rows*(row_start+i)+column_start]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(row_start+i)+column_start]=1;
    }
    }
    else{
    for(short i=0; i<length;i++){
        word_search[num_rows*(row_start+i)+column_start]=new_word_to_add[i];
        filled_spaces[num_rows*(row_start+i)+column_start]=1;
    }
    }
      break; //op
      case 2 :
         if(is_reversed){
        for(short i=0; i<length;i++){
        word_search[num_rows*(row_start+i)+column_start+i]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(row_start+i)+column_start+i]=1;
    }
    }
    else{
    for(short i=0; i<length;i++){
        word_search[num_rows*(row_start+i)+column_start+i]=new_word_to_add[i];
        filled_spaces[num_rows*(row_start+i)+column_start+i]=1;
    }
    }
      break; //op
      case 3 :
        if(is_reversed){
        for(short i=0; i<length;i++){
        word_search[num_rows*(row_start+i)+column_start-i]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(row_start+i)+column_start-i]=1;
    }
    }
    else{
    for(short i=0; i<length;i++){
        word_search[num_rows*(row_start+i)+column_start-i]=new_word_to_add[i];
        filled_spaces[num_rows*(row_start+i)+column_start-i]=1;
    }
    }
      break; //op
};
    
    list_of_words_added[u]=new_word_to_add;
    solution_pos[u][0]=row_start;
    solution_pos[u][1]=column_start;
    solution_pos[u][2]=row_end;
    solution_pos[u][3]=column_end;
    
    }
}