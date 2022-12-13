#include <stdio.h>

//Sorting using Quick sort.

struct student{
	char student_name[20];
	int roll_no;
	int total_marks;
};

int partition(struct student a[], int low, int high){
	int pivot = a[high].roll_no;
	int i = low-1;
	struct student temp;
	int swaps = 0;
	
	for(int j = low; j<high; j++){
		if(a[j].roll_no<pivot){
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			swaps++;
		}
		
	}
	printf("%d\n", swaps);
	
	temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    return (i + 1);
}

void sortByRoll(struct student a[], int low, int high){
	int partitionIndex;
    if(low<high){
    partitionIndex = partition(a,low,high);
    sortByRoll(a,low, partitionIndex-1); 
    sortByRoll(a,partitionIndex+1,high); 
    }
}


int main(){
	int nos;
	printf("Enter No. of Students: ");
	scanf("%d", &nos);
	struct student std[nos];
	
	for (int i=0; i<nos; i++){
		printf("\n");
		printf("Student %d \n",i+1);
		printf("Enter Name: ");
		scanf("%s", &std[i].student_name);
		printf("Roll No: ");
		scanf("%d", &std[i].roll_no);
		printf("Total Marks: ");
		scanf("%d", &std[i].total_marks);
	}
	
	sortByRoll(std,0,nos-1);
	printf("Name \t \t Roll No \t Total Marks \n");
	for (int i = 0; i<nos; i++){
		printf("%s \t \t %d \t \t %d \n", std[i].student_name, std[i].roll_no, std[i].total_marks);
	}
	
	return 0;
}



