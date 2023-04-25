#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
//================================================�ṹ���� 
 typedef struct stu{
	//���� 
	char id[20];
	char name[10];
	
	//�ɼ�
	float c; 
	float math; 
	float eng;
	float sum; 
	
	struct stu *next;
	
	void printI(){
		printf("%-10s %-10s %-7.2f %-7.2f %-7.2f %-7.2f\n",id,name,c,math,eng,sum);
	}
} link; 

int num=0;
//=================================================���������� 
void new_link();

int dengLu();		//��½����  
void guanLi();    //����˵�����  
	void search_Stu();   //  1.ѧ����Ϣ��ѯ 
		void search_by_id(); 
		void search_by_name();
		void search_by_c();
		void search_by_math();
		void search_by_eng();
		void search_by_sum();
		
void add_Stu();     //   2.���ѧ�� 
void sort_Stu();     //  3.�����ѯѧ�� 
	void sort_by_c();
	void sort_by_math();
	void sort_by_eng();
	void sort_by_sum();
		
void del_Stu();		//   4.ɾ��ѧ����Ϣ 
//void out_sys();   //     5.�˳����� 
	 
	 
//�Ӹ�������	 
void basic();    //������� 
void openError();   //����ļ��Ƿ�򿪳ɹ� 



link *head,*tail,*ps;
//=================================================main
int main()
{
	new_link();//�����ļ�    

	basic();
	int pan = 1;
	int flag=dengLu();
	 
	if(flag==1){
		
		while(pan){
			//�����ӡ 
			system("cls");
			basic();
			guanLi();
			
			//�ж��û��Ĳ�����Ը 
			int flag_g=0;    scanf("%d",&flag_g);
			system("cls");
			basic();
			if(flag_g==1){
				search_Stu();
				
			}else if(flag_g==2){
				add_Stu();
					
			}else if(flag_g==3){
				sort_Stu();
				
			}else if(flag_g==4){
				del_Stu();
					
			}else if(flag_g==5){
				pan=0;
				              //�˳�����	
			}	
				
		}   
	}
	
	
	return 0;
}

//==================================================����ʵ����

void new_link(){
	FILE *g=fopen("�ɼ�.txt","r");
	head= (link*)malloc(sizeof(link));//ͷ�ڵ�  ��ʼ�� 

	fscanf(g,"%d",&num);
	int u=num;
	fscanf(g,"%s %s %f %f %f %f",&head->id, &head->name, &head->c, &head->math, &head->eng, &head->sum);
	head->next=NULL;
		
	link *temp=head;
	//��������
	u--;
	while(u){
		link* a= (link*)malloc(sizeof(link));
		fscanf(g,"%s %s %f %f %f %f",&a->id, &a->name, &a->c, &a->math, &a->eng, &a->sum);
		a->next=NULL;
		//��������
		temp->next= a;
		temp= temp->next; 
		u--;
	}
	tail= temp; 
	fclose(g);

} 
void swap_node(stu *p1, stu *p2){
	stu p3;
	p3.c=p2->c;
	p3.sum=p2->sum;
	p3.math=p2->math;
	p3.eng=p2->eng;
	strcpy(p3.id,p2->id);
	strcpy(p3.name,p2->name);
	//p3.next=p2->next;
	
	p2->c=p1->c;
	p2->sum=p1->sum;
	p2->math=p1->math;
	p2->eng=p1->eng;
	strcpy(p2->id,p1->id);
	strcpy(p2->name,p1->name);
//	p2->next=p1->next;
	
	p1->c=p3.c;
	p1->sum=p3.sum;
	p1->math=p3.math;
	p1->eng=p3.eng;
	strcpy(p1->id,p3.id);
	strcpy(p1->name,p3.name);
//	p1->next=p3.next;
	
}
void del_node(stu *p1){
	stu *pre=head;
	ps=head->next;

	for(int i=0;i<num-1;i++){
		if(ps->id==p1->id){
			pre->next=ps->next;
			delete ps;
			break;
		}
		
		pre=ps;
		ps=ps->next;
	}
}

void del_Stu(){
		int flag=0;
		puts("		������ɾ������ѧ�ţ�");	
		printf("		ѧ�ţ�");	
//		puts("		2.�������˵�");	
//		printf("		:");
		char hao[20];    scanf("%s",&hao);
		ps=head;   
		
		for(int i=0;i<num;i++){
			if(!strcmp(ps->id,hao)){
				flag=1;
				printf("ɾ��ѧ����\n");
				ps->printI();
				del_node(ps);
				break;
			}
			
			
			ps=ps->next;
		}
		
		
		system("cls");
		basic();
		if(flag==1){
			
			//��д�ļ� 
			FILE *fp=fopen("�ɼ�.txt","w");
			ps= head;
			num--;
			fprintf(fp,"%d\n",num);
			while(ps!=NULL){
				fprintf(fp,"%s %s %f %f %f %f\n",ps->id, ps->name, ps->c, ps->math, ps->eng, ps->sum);
				ps=ps->next;
			}
			fclose(fp);
			puts("\n\n		ɾ����ϣ�����������˳�");
		}else{
			puts("δ��ѯ����ѧ����");
		}
		
		char lll;
		getchar();
		scanf("%c",&lll);
	
}	


void sort_Stu(){
	while(1){
		puts("		��ѡ�������ѯ��ʽ��");	
		puts("		1.��c���Գɼ�");	
		puts("		2.�������ɼ�");	
		puts("		3.��Ӣ��ɼ�");	
		puts("		4.���ܳɼ�");	
		puts("		5.�������˵�");	
		
		printf("		:");
		int flag_s;    scanf("%d",&flag_s);
		if(flag_s==1){
			sort_by_c();
		}else if(flag_s==2){
			sort_by_math();	
		}else if(flag_s==3){
			sort_by_eng();
		}else if(flag_s==4){
			sort_by_sum();
		}else if(flag_s==5){
			break;
		}
		system("cls");
		basic();
	}
}
void sort_by_c(){
	system("cls");
	basic();
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	ps=head;
	for(int i=0;i<num;i++){
		stu *ps2=head;
		for(int j=0;j<num;j++){
			if(ps->c< ps2->c){
				swap_node(ps,ps2);
			}
			ps2=ps2->next;
		}
		ps=ps->next;
	}
	ps=head;
	for(int i=0;i<num;i++){
		printf("		");
		ps->printI();
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void sort_by_math(){
	system("cls");
	basic();
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	ps=head;
	for(int i=0;i<num;i++){
		stu *ps2=head;
		for(int j=0;j<num;j++){
			if(ps->math< ps2->math){
				swap_node(ps,ps2);
			}
			ps2=ps2->next;
		}
		ps=ps->next;
	}
	ps=head;
	for(int i=0;i<num;i++){
		printf("		");
		ps->printI();
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void sort_by_eng(){
	system("cls");
	basic();
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	ps=head;
	for(int i=0;i<num;i++){
		stu *ps2=head;
		for(int j=0;j<num;j++){
			if(ps->eng< ps2->eng){
				swap_node(ps,ps2);
			}
			ps2=ps2->next;
		}
		ps=ps->next;
	}
	ps=head;
	for(int i=0;i<num;i++){
		printf("		");
		ps->printI();
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void sort_by_sum(){
	system("cls");
	basic();
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	ps=head;
	for(int i=0;i<num;i++){
		stu *ps2=head;
		for(int j=0;j<num;j++){
			if(ps->sum< ps2->sum){
				swap_node(ps,ps2);
			}
			ps2=ps2->next;
		}
		ps=ps->next;
	}
	ps=head;
	for(int i=0;i<num;i++){
		printf("		");
		ps->printI();
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}


void search_Stu(){
	
	while(1){
		puts("		��ѡ���ѯ��ʽ��");	
		puts("		1.��ѧ��");	
		puts("		2.������");	
		puts("		3.��c���Գɼ�");	
		puts("		4.����ѧ�ɼ�");	
		puts("		5.��Ӣ��ɼ�");	
		puts("		6.���ܳɼ�");
		puts("		7.�������˵�");
		printf("		:");
		int flag_s;    scanf("%d",&flag_s);
		if(flag_s==1){
			search_by_id();
			
		}else if(flag_s==2){
			search_by_name();	
		}else if(flag_s==3){
			search_by_c();
		}else if(flag_s==4){
			search_by_math();
		}else if(flag_s==5){
			search_by_eng();
		}else if(flag_s==6){
			search_by_sum();
		}else if(flag_s==7){
			break;
		}
		system("cls");
		basic();
	}
}
void search_by_sum(){
	system("cls");
	basic();
	printf("		�������ܳɼ���");
	float score_sum;    scanf("%f",&score_sum);
	ps=head;
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	for(int i=0;i<num;i++){
		if(ps->eng==score_sum){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_eng(){
	system("cls");
	basic();
	printf("		������Ӣ��ɼ���");
	float score_eng;    scanf("%f",&score_eng);
	ps=head;
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	for(int i=0;i<num;i++){
		if(ps->eng==score_eng){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_math(){
	system("cls");
	basic();
	printf("		����������ɼ���");
	float score_math;    scanf("%f",&score_math);
	ps=head;
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	for(int i=0;i<num;i++){
		if(ps->math==score_math){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_c(){
	system("cls");
	basic();
	printf("		������c���Գɼ���");
	float score_c;    scanf("%f",&score_c);
	ps=head;
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	for(int i=0;i<num;i++){
		if(ps->c==score_c){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_name(){
	system("cls");
	basic();
	printf("		������������");
	char str[20];    scanf("%s",&str);
	ps=head;
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	for(int i=0;i<num;i++){
		if(!strcmp(ps->name,str)){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_id(){
	system("cls");
	basic();
	printf("		������ѧ�ţ�");
	char str[20];    scanf("%s",&str);
	ps=head;
	printf("		ѧ��	    ����     c����    ����   Ӣ��    �ܳɼ�\n");
	for(int i=0;i<num;i++){
		if(!strcmp(ps->id,str)){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		��ѯ��ϣ�����������˳�");
	char lll;
	getchar();
	scanf("%c",&lll);
}


void basic(){
	printf("		---------------ѧ����Ϣ����ϵͳ---------------\n\n"); 
} 


void add_Stu(){
	puts("		��ֱ�����ѧ���� ѧ�� ���� c���Գɼ� ��ѧ�ɼ� Ӣ��ɼ���");
	printf("                  ");
	stu *pp=(link*)malloc(sizeof(link));
	num++;
	//������ѧ�� 
	scanf("%s %s %f %f %f",&pp->id, &pp->name, &pp->c, &pp->math, &pp->eng);
	pp->sum = pp->c + pp->math + pp->eng;
	pp->next= NULL;
	pp->printI();
	
	//β�ڵ�ת�� 
	tail->next=pp;
	tail=pp;
	
	//��д�ļ� 
	FILE *fp=fopen("�ɼ�.txt","w");
	ps= head;
	fprintf(fp,"%d\n",num);
	while(ps!=NULL){
		fprintf(fp,"%s %s %f %f %f %f\n",ps->id, ps->name, ps->c, ps->math, ps->eng, ps->sum);
		ps=ps->next;
	}
	fclose(fp);
	
	puts("�����ɹ���"); 
	Sleep(2000);
} 


void error_cheek(FILE *p){     //�ļ��Ƿ�� 
	if(p==NULL){
		system("cls");
		basic();
		puts("open file fail!������δ�����˺ţ�");
		exit(0);
	}
}


void guanLi(){
	puts("		1.ѧ����Ϣ��ѯ");
	puts("		2.���ѧ��");
	puts("		3.�����ѯѧ��");
	puts("		4.ɾ��ѧ����Ϣ");
	puts("		5.�˳�����");
	puts("		--------------------------------------------");
	printf("		�������Ҫ��������ķ������:");	
	
	
	
}


int dengLu(){

	int f_time=0;
	
	while(f_time<3){
		puts("		��ӭ����ѧ����Ϣ����ϵͳ\n");
		puts("		���������İ������˺�������\n");
		if(f_time!=0)puts("		�˻�������������ԣ�\n\n");
		 
		printf("		�˺ţ�");
		char p_id[20];		scanf("%s",&p_id);
		
		printf("\n\n		���룺");
		char p_secret[20];		scanf("%s",&p_secret);
	
		FILE *p;	p=fopen("������.txt","r");
		error_cheek(p);
		 
		char p_id2[20],p_secret2[20];
		while(!feof(p)){	
			fscanf(p,"%s %s", &p_id2, &p_secret2);
			if((!strcmp(p_id2,p_id))&&(!strcmp(p_secret,p_secret2))){
				system("cls");
				basic();
				puts("		��½�ɹ�,loading...\n");
				Sleep(1000);
				system("cls");
				basic();
				return 1; 
			}
		}
		f_time++;
		system("cls");
		basic();
		fclose(p);
	
	}
	
	system("cls");
	basic();
	puts("		��½ʧ�ܳ������Σ������˳�����");
	return 0;
	

} 


