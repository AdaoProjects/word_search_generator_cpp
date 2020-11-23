#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
const short num_of_possibilites__words=10;
static std::string list_all_words[200]={
"aspecto",
"virtude",
"candura",
"deboche",
"mitigar",
"cultura",
"almejar",
"redimir",
"cordial",
"exortar",
"emergir",
"trivial",
"imputar",
"recesso",
"cinismo",
"refutar",
"sucinto",
"sublime",
"empatia",
"embuste",
"mazela",
"alocar",
"remoto",
"nuance",
"acesso",
"ciente",
"esteio",
"receio",
"objeto",
"avidez",
"acento",
"isento",
"eximir",
"sisudo",
"perene",
"embora",
"escusa",
"alento",
"dispor",
"abster",
"infame",
"utopia",
"nocivo",
"alheio",
"adorno",
"gentil",
"hostil",
"legado",
"idiota",
"casual",
"anseio",
"escopo",
"pressa",
"apogeu",
"exceto",
"vereda",
"mister",
"eficaz",
"julgar",
"limiar",
"justo",
"honra",
"muito",
"lapso",
"tange",
"corja",
"expor",
"posse",
"haver",
"ardil",
"desde",
"sanar",
"fazer",
"cerne",
"ideia",
"torpe",
"anexo",
"moral",
"poder",
"assim",
"recuo",
"rubor",
"folgo",
"borra",
"dotar",
"nisto",
"lance",
"junta",
"adido",
"santo",
"soar",
"ater",
"fase",
"gozo",
"casa",
"rima",
"sina",
"rude",
"voga",
"cujo",
"cedo",
"onde",
"sela",
"mais",
"cela",
"nojo",
"meio",
"face",
"auto",
"teor",
"tudo",
"pela",
"foda",
"pose",
"ante",
"teve",
"base",
"asco",
"para",
"alvo",
"numa",
"jugo",
"traz",
"logo",
"alva",
"agir",
"vale",
"nexo",
"meta",
"pude",
"ente",
"coxo",
"vida",
"saga",
"medo",
"idem",
"cota",
"veio",
"urge",
"zelo",
"ruim",
"pois",
"ermo",
"mote",
"apto",
"suma",
"tolo",
"crer",
"como",
"auge",
"sede",
"amor",
"fato",
"mito",
"esmo",
"brio",
"caos",
"vide",
"rege",
"todo",
"toar",
"saca",
"remo",
"neca",
"golo",
"sapa",
"fone",
"triz",
"enta",
"goro",
"fel",
"sob",
"vil",
"paz",
"ser",
"mal",
"ver",
"ter",
"bem",
"ego",
"vir",
"dar",
"mas",
"bom",
"ora",
"era",
"rol",
"elo",
"tal",
"vis",
"luz",
"com",
"dia",
"ato",
"hum",
"eis",
"tez",
"pro",
"dor",
"pai",
    };

const short  num_rows=12;
const short num_of_words=20;
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
void fit_words_connections(){
    short x=rand()%num_of_possibilites__words;
    std::string new_word_to_add=list_all_words[x];
    list_of_words_added[0]=new_word_to_add;
    solution_pos[0][0]=rand()%(num_rows-new_word_to_add.length()+1);
    solution_pos[0][1]=rand()%(num_rows-new_word_to_add.length()+1);
    solution_pos[0][2]=solution_pos[0][0]+new_word_to_add.length()-1;
    solution_pos[0][3]=solution_pos[0][1]+new_word_to_add.length()-1;
    bool is_reversed=false;
    if(rand()%2==0){
        is_reversed=true;
    }
    if(is_reversed){
        for(short i=0, length=new_word_to_add.length(); i<length;i++){
        word_search[num_rows*(solution_pos[0][0]+i)+solution_pos[0][1]+i]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(solution_pos[0][0]+i)+solution_pos[0][1]+i]=1;
    }
    }
    else{
    for(short i=0, length=new_word_to_add.length(); i<length;i++){
        word_search[num_rows*(solution_pos[0][0]+i)+solution_pos[0][1]+i]=new_word_to_add[i];
        filled_spaces[num_rows*(solution_pos[0][0]+i)+solution_pos[0][1]+i]=1;
    }
    }
    bool connection=false;
    x=rand()%num_of_possibilites__words+num_of_possibilites__words;
    new_word_to_add=list_all_words[x];
    for (short i=0,length=list_of_words_added[0].length(); i<length;i++){
        for (short j=0, length_two=new_word_to_add.length(); j<length_two;j++){
            if(list_of_words_added[0][i]==new_word_to_add[j]){
                connection=true;
                if(is_reversed){
                    solution_pos[1][0]=solution_pos[0][0]+list_of_words_added[0].length()-1-i;
                    solution_pos[1][1]=solution_pos[0][1]+list_of_words_added[0].length()-1-i-j;
                    solution_pos[1][2]=solution_pos[1][0];
                    solution_pos[1][3]=solution_pos[1][1]+new_word_to_add.length()-1;
                    is_reversed=false;
                    if(solution_pos[1][1]<0 || solution_pos[1][1]>num_rows-new_word_to_add.length()){
                    solution_pos[1][0]=solution_pos[0][0]+i;
                    solution_pos[1][1]=solution_pos[0][1]+list_of_words_added[0].length()-1-i-new_word_to_add.length()+1+j;
                    solution_pos[1][2]=solution_pos[1][0];
                    solution_pos[1][3]=solution_pos[1][1]+new_word_to_add.length()-1;
                    is_reversed=true;
                    if(solution_pos[1][1]<0 || solution_pos[1][1]>num_rows-new_word_to_add.length()){
                    connection=false;
                    }
                    }
                }else{
                    solution_pos[1][0]=solution_pos[0][0]+list_of_words_added[0].length()-1-i;
                    solution_pos[1][1]=solution_pos[0][1]+i-j;
                    solution_pos[1][2]=solution_pos[1][0];
                    solution_pos[1][3]=solution_pos[1][1]+new_word_to_add.length()-1;
                    is_reversed=false;
                    if(solution_pos[1][1]<0 || solution_pos[1][1]>num_rows-new_word_to_add.length()){
                    solution_pos[1][0]=solution_pos[0][0]+i;
                    solution_pos[1][1]=solution_pos[0][1]+i-new_word_to_add.length()+1+j;
                    solution_pos[1][2]=solution_pos[1][0];
                    solution_pos[1][3]=solution_pos[1][1]+new_word_to_add.length()-1;
                    is_reversed=true;
                    if(solution_pos[1][1]<0 || solution_pos[1][1]>num_rows-new_word_to_add.length()){
                    connection=false;
                    }
                    }
                }
            }
            if(connection==1){
                break;
            }
        }
        if(connection==1){
                break;
            }
    }
    
    if(!connection){
        add_new_word(1);
    }else{
    if(is_reversed){
        for(short i=0, length=new_word_to_add.length(); i<length;i++){
        word_search[num_rows*(solution_pos[1][0])+solution_pos[1][1]+i]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(solution_pos[1][0])+solution_pos[1][1]+i]=1;
    }
    }
    else{
    for(short i=0, length=new_word_to_add.length(); i<length;i++){
        word_search[num_rows*(solution_pos[1][0])+solution_pos[1][1]+i]=new_word_to_add[i];
        filled_spaces[num_rows*(solution_pos[1][0])+solution_pos[1][1]+i]=1;
    }

    }
list_of_words_added[1]=new_word_to_add;
    }
    
    connection=false;
    bool shocks=false;
    x=rand()%num_of_possibilites__words+num_of_possibilites__words*2;
    new_word_to_add=list_all_words[x];
    for (short i=0, length=list_of_words_added[1].length(); i<length;i++){
        for (short j=0, length_two=new_word_to_add.length(); j<length_two;j++){
            if(list_of_words_added[1][i]==new_word_to_add[j]){
                connection=true;
                if(is_reversed){
                    solution_pos[2][0]=solution_pos[1][0]-j;
                    solution_pos[2][1]=solution_pos[1][1]+list_of_words_added[1].length()-1-i;
                    solution_pos[2][2]=solution_pos[2][0]+new_word_to_add.length()-1;
                    solution_pos[2][3]=solution_pos[2][1];
                    is_reversed=false;
                    if(solution_pos[2][0]<0 || solution_pos[2][0]>num_rows-new_word_to_add.length()){
                    solution_pos[2][0]=solution_pos[1][0]-new_word_to_add.length()+1+j;
                    solution_pos[2][1]=solution_pos[1][1]+list_of_words_added[1].length()-1-i;
                    solution_pos[2][2]=solution_pos[2][0]+new_word_to_add.length()-1;
                    solution_pos[2][3]=solution_pos[2][1];
                    is_reversed=true;
                    if(solution_pos[2][0]<0 || solution_pos[2][0]>num_rows-new_word_to_add.length()){
                    connection=false;
                    }
                    }
                }else{
                    solution_pos[2][0]=solution_pos[1][0]-j;
                    solution_pos[2][1]=solution_pos[1][1]+i;
                    solution_pos[2][2]=solution_pos[2][0]+new_word_to_add.length()-1;
                    solution_pos[2][3]=solution_pos[2][1];
                    is_reversed=false;
                    if(solution_pos[2][0]<0 || solution_pos[2][0]>num_rows-new_word_to_add.length()){
                    solution_pos[2][0]=solution_pos[1][0]-new_word_to_add.length()+1+j;
                    solution_pos[2][1]=solution_pos[1][1]+i;
                    solution_pos[2][2]=solution_pos[2][0]+new_word_to_add.length()-1;
                    solution_pos[2][3]=solution_pos[2][1];
                    is_reversed=true;
                    if(solution_pos[2][0]<0 || solution_pos[2][0]>num_rows-new_word_to_add.length()){
                    connection=false;
                    }
                    }
                }
            }
            shocks=false;
            if(connection){
                for (short k =0,length_three=new_word_to_add.length(); k<length_three;k++){
                if(filled_spaces[(solution_pos[2][0]+k)*num_rows+solution_pos[2][1]]==1){
                    if(is_reversed){
                        if(new_word_to_add[new_word_to_add.length()-1-k]!=word_search[(solution_pos[2][0]+k)*num_rows        +solution_pos[2][1]]){
                            shocks=true;
                        }
            }else{
                if(new_word_to_add[k]!=word_search[(solution_pos[2][0]+k)*num_rows+solution_pos[2][1]]){
                    shocks=true;
                }
            }
        }
    }
            }
            if(connection && !shocks){
                break;
            }
        }
        if(connection && !shocks){
                break;
            }
    }
    if(!connection || shocks){
        add_new_word(2);
    }else{
if(is_reversed){
        for(short i=0, length=new_word_to_add.length(); i<length;i++){
        word_search[num_rows*(solution_pos[2][0]+i)+solution_pos[2][1]]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(solution_pos[2][0]+i)+solution_pos[2][1]]=1;
    }
    }
    else{
    for(short i=0, length=new_word_to_add.length(); i<length;i++){
        word_search[num_rows*(solution_pos[2][0]+i)+solution_pos[2][1]]=new_word_to_add[i];
        filled_spaces[num_rows*(solution_pos[2][0]+i)+solution_pos[2][1]]=1;
    }
    }
    list_of_words_added[2]=new_word_to_add;
    }
    
    connection=false;
    shocks=false;
    x=rand()%num_of_possibilites__words+num_of_possibilites__words*3;
    new_word_to_add=list_all_words[x];
    for (short i=0, length=list_of_words_added[1].length(); i<length;i++){
        for (short j=0, length_two=new_word_to_add.length(); j<length_two;j++){
            if(list_of_words_added[1][i]==new_word_to_add[j]){
                connection=true;
                if(is_reversed){
                    solution_pos[3][0]=solution_pos[1][0]-j;
                    solution_pos[3][1]=solution_pos[1][1]+list_of_words_added[1].length()-1-i;
                    solution_pos[3][2]=solution_pos[3][0]+new_word_to_add.length()-1;
                    solution_pos[3][3]=solution_pos[3][1];
                    is_reversed=false;
                    if(solution_pos[3][0]<0 || solution_pos[3][0]>num_rows-new_word_to_add.length()){
                    solution_pos[3][0]=solution_pos[1][0]-new_word_to_add.length()+1+j;
                    solution_pos[3][1]=solution_pos[1][1]+list_of_words_added[1].length()-1-i;
                    solution_pos[3][2]=solution_pos[3][0]+new_word_to_add.length()-1;
                    solution_pos[3][3]=solution_pos[3][1];
                    is_reversed=true;
                    if(solution_pos[3][0]<0 || solution_pos[3][0]>num_rows-new_word_to_add.length()){
                    connection=false;
                    }
                    }
                }else{
                    solution_pos[3][0]=solution_pos[1][0]-j;
                    solution_pos[3][1]=solution_pos[1][1]+i;
                    solution_pos[3][2]=solution_pos[3][0]+new_word_to_add.length()-1;
                    solution_pos[3][3]=solution_pos[3][1];
                    is_reversed=false;
                    if(solution_pos[3][0]<0 || solution_pos[3][0]>num_rows-new_word_to_add.length()){
                    solution_pos[3][0]=solution_pos[1][0]-new_word_to_add.length()+1+j;
                    solution_pos[3][1]=solution_pos[1][1]+i;
                    solution_pos[3][2]=solution_pos[3][0]+new_word_to_add.length()-1;
                    solution_pos[3][3]=solution_pos[3][1];
                    is_reversed=true;
                    if(solution_pos[3][0]<0 || solution_pos[3][0]>num_rows-new_word_to_add.length()){
                    connection=false;
                    }
                    }
                }
            }
            shocks=false;
            if(connection){
                for (short k =0, length_three=new_word_to_add.length(); k<length_three;k++){
                if(filled_spaces[(solution_pos[3][0]+k)*num_rows+solution_pos[3][1]]==1){
                    if(is_reversed){
                        if(new_word_to_add[new_word_to_add.length()-1-k]!=word_search[(solution_pos[3][0]+k)*num_rows        +solution_pos[3][1]]){
                            shocks=true;
                        }
            }else{
                if(new_word_to_add[k]!=word_search[(solution_pos[3][0]+k)*num_rows+solution_pos[3][1]]){
                    shocks=true;
                }
            }
        }
    }
            }
            if(connection && !shocks){
                break;
            }
        }
        if(connection && !shocks){
                break;
            }
    }
    
    if(!connection || shocks){
        add_new_word(3);
    }else{
if(is_reversed){
        for(short i=0, length=new_word_to_add.length(); i<length;i++){
        word_search[num_rows*(solution_pos[3][0]+i)+solution_pos[3][1]]=new_word_to_add[new_word_to_add.length()-i-1];
        filled_spaces[num_rows*(solution_pos[3][0]+i)+solution_pos[3][1]]=1;
    }
    }
    else{
    for(short i=0, length=new_word_to_add.length(); i<length;i++){
        word_search[num_rows*(solution_pos[3][0]+i)+solution_pos[3][1]]=new_word_to_add[i];
        filled_spaces[num_rows*(solution_pos[3][0]+i)+solution_pos[3][1]]=1;
    }
    }
    list_of_words_added[3]=new_word_to_add;
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
        column_start=num_rows-1-rand()%(num_rows-new_word_to_add.length()+1);
        row_end=row_start+new_word_to_add.length()-1;
        column_end=column_start-new_word_to_add.length()+1;
    }
    is_reversed=false;
    x=rand()%2;
    if(x==1){
        is_reversed=true;
    }
    shocks=false;
    short limit_row=0;
    short limit_column=0;
    if(type_of_position=="horizontal"){
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
    }else if(type_of_position=="vertical"){
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
    }else if(type_of_position=="diagonal_SE"){
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
    }else if(type_of_position=="diagonal_SO"){
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
    }
    
    


    if(shocks){
        add_new_word(u);
    }else{
    if(type_of_position=="horizontal"){
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
    }else if(type_of_position=="vertical"){
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
    }else if(type_of_position=="diagonal_SE"){
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
    }else if(type_of_position=="diagonal_SO"){
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
    }
    
    list_of_words_added[u]=new_word_to_add;
    solution_pos[u][0]=row_start;
    solution_pos[u][1]=column_start;
    solution_pos[u][2]=row_end;
    solution_pos[u][3]=column_end;
    
    }
}