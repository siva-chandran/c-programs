#include<stdio.h>
#include<math.h>
#include<conio.h>
int z=0,j=0;

struct question{
    int score;
    int time_to_solve;
}question[10];

struct subset_sum_of_time_and_score{
int subset_time;
int subset_score;
}subset_sum[30];

void store_subset_to_array(struct question a[],int l,int r,int sum_of_time,int sum_of_score){
    if(l>r){
        subset_sum[z].subset_time = sum_of_time;
        subset_sum[z].subset_score = sum_of_score;
        z++;
        return;
    }
    store_subset_to_array(a,l+1,r,sum_of_time+a[l].time_to_solve,sum_of_score+a[l].score);
    store_subset_to_array(a,l+1,r,sum_of_time,sum_of_score);
}

void main(){
    int number_of_question,max_time_limit,i,k,score_within_timelimit[40],size;
    printf("Enter the number of questions\n");
    scanf("%d",&number_of_question);
    printf("Enter the time limit\n");
    scanf("%d",&max_time_limit);
    for(i=0;i<number_of_question;i++){
        printf("Enter the score for question [%d] ",i+1);
        scanf("%d",&question[i].score);
    }
    for(i=0;i<number_of_question;i++){
        printf("Enter the time for question [%d] ",i+1);
        scanf("%d",&question[i].time_to_solve);
    }
    store_subset_to_array(question,0,number_of_question-1,0,0);

    for(i=0;i<pow(2,number_of_question);i++){
        if(subset_sum[i].subset_time<=max_time_limit){
            score_within_timelimit[j] = subset_sum[i].subset_score;
            j++;
        }
    }
    for(i=0;i<j;i++){
        for(k=i+1;k<j;k++){
            if(score_within_timelimit[i]<=score_within_timelimit[j]){
                int temp = score_within_timelimit[i];
                score_within_timelimit[i] = score_within_timelimit[k];
                score_within_timelimit[k] = temp;
            }
        }
    }
        printf("%d\t",score_within_timelimit[0]);
}
