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
		printf("%s %s %.2f %.2f %.2f %.2f\n",id,name,c,math,eng,sum);
	}
} link; 

//=================================================���������� 
void new_link();

int dengLu();		//��½����  
void guanLi();    //����˵�����  
	void search_Stu();   //  1.ѧ����Ϣ��ѯ 
		void search_by_id(); 
		void search_by_name();
		void search_by_c();
		void search_by_math(int num);
		void search_by_eng(int num);
		void search_by_sum(int num);
		
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
			//	search_Stu();
				
			}else if(flag_g==2){
				add_Stu();
					
			}else if(flag_g==3){
				//sort_Stu();
				
			}else if(flag_g==4){
				//del_Stu();
					
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
	head= (link*)malloc(sizeof(link));//ͷ�ڵ�  ��ʼ�� 
	strcpy(head->name,"admin");
	strcpy(head->id,"123");
	head->c=0;
	head->eng=0;
	head->math=0;
	head->sum=0;
	
	link *temp=head;
	int i=0;
	//��������
	FILE *g=fopen("�ɼ�.txt","r");
	while(!feof(g)){
		link* a= (link*)malloc(sizeof(link));
		fscanf(g,"%s %s %f %f %f %f",&a->id, &a->name, &a->c, &a->math, &a->eng, &a->sum);
		a->next=NULL;
		//��������
		temp->next= a;
		temp= temp->next; 
		
	}
	tail= temp; 
	fclose(g);
}
 
void search_Stu(int num){
	puts("		��ѡ���ѯ��ʽ��");	
	puts("		1.��ѧ��");	
	puts("		2.������");	
	puts("		3.��c���Գɼ�");	
	puts("		4.����ѧ�ɼ�");	
	puts("		5.��Ӣ��ɼ�");	
	puts("		6.���ܳɼ�");
	puts("		7.�������˵�");
	
	while(1){
		
		int flag_s;    scanf("%d",&flag_s);
		if(flag_s==1){
			//search_by_id();
			
		}else if(flag_s==2){
			//search_by_name();
			
		}else if(flag_s==3){
			
		}else if(flag_s==4){
			
		}else if(flag_s==5){
			
		}else if(flag_s==6){
			
		}else if(flag_s==7){
		}	
	}
}
void search_by_id(int num){
	printf("		������ѧ�ţ�");
	char str[20];    scanf("%s",&str);
	
	for(int i=0;i<num;i++){
		
	}
	puts("\n\n		��ѯ��ϣ�");
}

void basic(){
	printf("		---------------ѧ����Ϣ����ϵͳ---------------\n\n"); 
} 

void add_Stu(){
	puts("		��ֱ�����ѧ���� ѧ�� ���� c���Գɼ� ��ѧ�ɼ� Ӣ��ɼ���");
	printf("                  ");
	stu *pp=(link*)malloc(sizeof(link));
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

void guanLi()
{
	puts("		1.ѧ����Ϣ��ѯ");
	puts("		2.���ѧ��");
	puts("		3.�����ѯѧ��");
	puts("		4.ɾ��ѧ����Ϣ");
	puts("		5.�˳�����");
	puts("		--------------------------------------------");
	printf("		�������Ҫ��������ķ������:");	
	
	
	
}


int dengLu(){

	return 1;
	

} 


