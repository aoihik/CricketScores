#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random_num;
int player_runs[22], x, team_alpha_runs, team_beta_runs, num_of_overs, i, j, y, z;
int total_run, num_of_balls, extra_runs; char balls;

void NewMatch(); void PrevMatch(); void Team_Details();
void _zero(); void _one(); void _two(); void _three(); void _four(); void _six();

int main()
{
    int ch;
    srand(time(NULL));
    random_num=rand();
    while(1){
        printf("\n\n1.Start a new match");
        printf("\n2.View team details");
        printf("\n3.Exit\n\n");

        scanf("%d", &ch);
        if(ch==1)
            NewMatch();
        else if(ch==2)
            Team_Details();
        else if(ch==3){
                system("cls");
                exit(0);
        }
        else{
            printf("Invalid choice");
            exit(1);
        }
    }
 return 0;
}
void NewMatch(){
    time_t time_now;
    int ch2, points;
    system("cls");

    printf("\nEnter type of match");
    printf("\n1.20-20");
    printf("\n2.One Day International");
    printf("\n3.Decide random number of overs\n");
    scanf("%d", &ch2);

    switch(ch2){

        case 1: num_of_overs=20; break;
        case 2: num_of_overs=50; break;
        case 3: printf("\nEnter number of overs\n");
                scanf("%d", &num_of_overs);
                break;
        default: printf("\nInvalid choice");
                    exit(1);
                    break;

    }
    total_run=0; num_of_balls=0; x=0; extra_runs=0; team_alpha_runs=0; team_beta_runs=0;
    for(i=0;i<=22;i++)
        player_runs[i]=0;



//decider loop

printf("\n");
for(i=0;i<(num_of_overs*6);i++){
    points=points+10210;
    srand(time(&time_now)+points);
    random_num=rand();


    if(random_num%13==0){
        balls='l';
        printf("(lb )");
    }

    else if(random_num%5==0){
        balls='o';
        printf("(wkt)");
    }

    else if(random_num%17==0){
        balls='w';
        printf("(wde)");
    }

    else if(random_num%23==0){
        balls='n';
        printf("(no )");
    }

    else if(random_num%15==0){
         balls='b';
         printf("(bye)");
    }

    else{
        balls='g';
        printf("(   )");
    }



    if(random_num%19==0)
        _zero();
    else if(random_num%6==0)
        _six();
    else if(random_num%7==0)
        _four();
    else if(random_num%8==0)
        _one();
    else if(random_num%9==0)
        _three();
    else
        _two();
     }
    for(i=0;i<11;i++)
        team_alpha_runs=team_alpha_runs+player_runs[i];
    for(i=11;i<22;i++)
         team_beta_runs=team_beta_runs+player_runs[i];

    printf("\n___________________________________________________________________________________________________________________________________________________\n\n\n");
    printf("SCORE\n");
    printf("\nTeam Alpha:\t%d", team_alpha_runs);
    printf("\nTeam Beta:\t%d", team_beta_runs);
    if(team_alpha_runs>team_beta_runs)  printf("\nTeam Alpha wins");
    else if(team_alpha_runs<team_beta_runs) printf("\nTeam Beta wins");
    else    printf("\nThe Match is a draw");
    srand(time(NULL));
    random_num=rand();

}
void _zero(){

    if(balls=='l'||balls=='b'||balls=='g'){
        num_of_balls++;
        printf("0\t");
    }

    else if(balls=='o'){
            num_of_balls++;
            x++;
            printf("0\t");
    }
    else if(balls=='w'||balls=='n'){
        extra_runs++;
        printf("0\t");
    }


}
void _six(){

     if(balls=='l'||balls=='b'){
            num_of_balls++;
            printf("0\t");
            //A six doesn't happen through byes and leg byes
     }
    else if(balls=='o'){
            num_of_balls++;
            x++;
            printf("0\t");
    }
    else if(balls=='n'){
            extra_runs++;
            player_runs[x]=player_runs[x]+6;
            printf("6\t");

    }
    else if(balls=='g'){
        num_of_balls++;
        player_runs[x]=player_runs[x]+6;
        printf("6\t");

    }
}

void _four(){

    if(balls=='l'||balls=='b'){
        num_of_balls++;
        extra_runs=extra_runs+4;
        printf("0\t");

    }
    else if(balls=='o'){
        printf("0\t");
    }
    else if(balls=='w'){
        extra_runs=extra_runs+5;
        printf("0\t");
    }
    else if(balls=='n'){
        extra_runs++;
        player_runs[x]=player_runs[x]+4;
        printf("4\t");
    }
    else if(balls=='g'){
        num_of_balls++;
        player_runs[x]=player_runs[x]+4;
        printf("4\t");
    }
}
void _three(){

    if(balls=='l'||balls=='b'){
        num_of_balls++;
        extra_runs=extra_runs+3;
        printf("0\t");

    }
    else if(balls=='w'){
        extra_runs=extra_runs+4;
        printf("0\t");
    }
    else if(balls=='o'){
        player_runs[x]=player_runs[x]+3;
        x++;
        num_of_balls++;
        printf("3\t");

    }
    else if(balls=='n'){
        extra_runs++;
        player_runs[x]=player_runs[x]+3;
        printf("3\t");
    }
    else if(balls=='g'){
        num_of_balls++;
        player_runs[x]=player_runs[x]+3;
        printf("3\t");
    }
}
void _two(){


    if(balls=='l'||balls=='b'){
        num_of_balls++;
        extra_runs=extra_runs+2;
        printf("0\t");

    }
    else if(balls=='w'){
        extra_runs=extra_runs+3;
        printf("0\t");
    }
    else if(balls=='o'){
        player_runs[x]=player_runs[x]+2;
        x++;
        num_of_balls++;
        printf("2\t");

    }
    else if(balls=='n'){
        extra_runs++;
        player_runs[x]=player_runs[x]+2;
        printf("2\t");
    }
    else if(balls=='g'){
        num_of_balls++;
        player_runs[x]=player_runs[x]+2;
        printf("2\t");
    }
}
void _one(){


    if(balls=='l'||balls=='b'){
        num_of_balls++;
        extra_runs++;
        printf("0\t");
    }
    else if(balls=='w'){
        extra_runs=extra_runs+2;
        printf("0\t");
    }
    else if(balls=='o'){
        player_runs[x]++;
        x++;
        num_of_balls++;
        printf("1\t");

    }
    else if(balls=='n'){
        extra_runs++;
        player_runs[x]++;
        printf("1\t");
    }
    else if(balls=='g'){
        num_of_balls++;
        player_runs[x]++;
        printf("1\t");
    }
}

void Team_Details(){

    char c;
    FILE *fp;
    fp=fopen("Team Alpha.txt", "r");
    while((c=fgetc(fp))!=EOF)
            putchar(c);
    fclose(fp);
    printf("\n___________________________________________________________________________________________________________________________________________________\n\n\n");
    fp=fopen("Team Beta.txt", "r");
    while((c=fgetc(fp))!=EOF)
        putchar(c);
    fclose(fp);


}
