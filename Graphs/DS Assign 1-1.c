# include <stdio.h>

//Sorted using Insertion Sort

struct student{
	char student_name[20];
	int student_roll_no;
	int total_marks;
};


void sortByRoll(struct student a[], int n){
	
	struct student temp;
	int swaps = 0;
	
	for (int i = 0; i<n; i++){
		int num = a[i].student_roll_no;
		int j = i-1;
		
		
		while(j>=0 && a[j].student_roll_no>num){
			temp = a[j+1];
			a[j+1] = a[j];
			a[j] = temp;
			j = j-1;
			swaps++;
		}
		a[j+1].student_roll_no = num;
		
	}
	printf("%d\n", swaps);
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
		scanf("%d", &std[i].student_roll_no);
		printf("Total Marks: ");
		scanf("%d", &std[i].total_marks);
	}
	
	sortByRoll(std,nos);
	printf("\n");
	printf("Name \t \t Roll No \t Total Marks \n");
	for (int i = 0; i<nos; i++){
		printf("%s \t \t %d \t \t %d \n", std[i].student_name, std[i].student_roll_no, std[i].total_marks);
	}
	
	return 0;
}
